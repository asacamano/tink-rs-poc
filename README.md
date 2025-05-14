# tink-rs - A rust wrapper of tink-cc

Rust bindings of [Tink crypto CC](https://github.com/tink-crypto/tink-cc.git)

NOTE: This doesn't build on Mac directly now - only Nix and Linux.

## How this works

The basic pattern is that tink-rs API provides Rust-idiomatic objects that wrap tink-cc
implementations. All interactions happen with function calls on those wrapped objects,
and the returned values are themselves either wrapped objects, or converted to
Rust-idiomatic types like `Vec[u8]`.

Currently, only one direction is supported: Rust calling C++ functions.

There are four conceptual layers.

* Rust-native: the public tink-rs API. Wraps the Rust-side transfer layer.
* Rust-side transfer layer: Rust versions of objects used to transfer between Rust and C++.
  Wraps the C-side transfer layer.
* C-side transfer layer: Plain C verions of objects used to transfer between Rust and C++.
  Wraps the C++ Tink-cc library.
* Tink-cc: the standard tink/tink-cc library.

## Transfer layers in general

Memory safety is not enforced by the compiler, but instead enforced by using clear
patterns and type naming conventions.

### Owned___

Owned___ wraps a pointer to heap memory, which is meant to be owned by the recipient.
This is similar to C++'s `std::unique_ptr`.

* When an Owned<x> is passed into a function, the caller no longer manages that memory,
  and the function itself is responsibile for freeing it.
* When an Owned<X> is returned from a function, the caller is responsible for freeing it.

Tink-rs supports this by:

* allowing a Rust object to to call the C++ `delete` function as when `drop` is invoked on
  the Rust object. 
* never requiring C++ to release memory created by Rust by:
  * only allowing Owned parameters to transfer functions to be objects that were created in C++
* only allowing the return types of transfer functions to be Owned, Static, or Value (see below).

### Borrowed___

Borrowed__ wraps a pointer to heap memory, which must be freed by whoever currently owns it.
This is similar to C++'s `std::shared_ptr`.

Currently, all of the memory safety is managed in Rust, so we must make sure that the lifetime
of the Rust objects which are borrowed outlasts the lifetime of the C++ objects. This also
means that borrowed objects can not be returned from C++ functions (since there is no 
support build into Tink-rs for tracking the lifetime of Rust objects from the C++ side.)

### Static___

Static___ wraps a pointer to heap memory. The creator of the object is responsible for ensuring
the object lasts as long as the program is running.

### Value____

Value___ is an struct which is passed by value on the stack.

Note that C++ and Rust can share a representation of many scalars and structures, and
in those cases the Value___ type might just be an alias.


## C++ types and interfaces, and Rust types and traits

In Tink-rs, Rust objects (like KeysetHandle) all wrap C++ objects. But often the C++ functions
which return these only return the interface, not the full type. So the underlying type is not
always known. Therefore Tink-rs doesn't try to figure out the underlying C++ type and reflect that
in a typed Rust object. Instead there are just Rust types for C++ intefaces, like KeysetHandle or
KeysetReader.

## Motivation

* Tink is a good crypto library.
    * It is highly auditable and very simple by design.
    * It makes key rotation easy and safe.
    * It is quite performant.
* Tink Python wraps Tink CC, so making Tink Rust wrap it also seemed reasonable.
* Tink CC includes support for AWS and GCP's KMSs, so it's easy to use in a cross-cloud context.

## Goals of this implementation.

* Stick with the core ideas and patterns of the Tink-cc library.
  * Easy to audit and review.
  * Limited dependencies.
  * Clarity about memory safety.
  * Clarity about statelessness.
* Provide idiomatic Rust APIs.
  * As much as possible, this follows the patterns established by https://github.com/project-oak/tink-rust.
* Why not https://github.com/project-oak/tink-rust?
  * Use Tink primitives.
  * Maintain feature parity with Tink-cc.
* Build Rust code with with cargo, package it in crates - so it's easy to use in Rust (and build eveything in Nix).
  * Some other constraints come in from that:
    * Cargo has CMake integration, but not Bazel.
    * Tink CC only supports CMake and Bazel.
    * It's hard to get Tink CC to build a statically linked library for Rust to integrate with.
* Introduce as few dependencies as possible.
  * There are libraries such as cxx-bridge that do a lot of this "for free" (but not all), but 
    they introduce their own specific patterns, and dependencies.
* Make it obvious how the C++ memory-safety patterns translate to Rust through the FFI.
  * This is done using the transfer layer naming patterns.
* Make it easy to understand how the layers work together.
  * By using clear naming patterns at each layer.


## Why not cxx bridge or bindgen.

* Bindgen doesn't support anything with templates - and Tink uses them extensively.
* cxx-bridge also has limitations (generics, so Abseil), and also introduced some non-standard
  types, like custom String and UniquePtr Rust equivalents to C++ types.
* Having implemented simple C wrappings around Tink's C++, bindgen could have been used to
  expose those, but ensuring the memory-safety of those bindings would have required extensive
  boilerplate - so bindgen ended up not adding much.