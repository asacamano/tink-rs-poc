# Tink Wrappers for Rust integration.

This directory contains C++ code to make it easier to interacti with the
[Tink CC library](https://github.com/tink-crypto/tink-cc) from Rust.

See ../README.md for notes about the conventions adopted for the Rust -> C++ bidndings.

### Statically linked version of Tink.

The Bazel and CMake versions of Tink are really focused on building code that gets integrated into binaries.
The "install" and "install/local" options didn't do anything. And `cmake --build . --target help` didn't show
anything else that looked useful.

Running CMake with this flag:

```
set(CMAKE_LINK_DEPENDS_DEBUG_MODE ON)
```

produces a list of 540+ carefully ordered dependencies. With a bit of tweaking, that list goes into build.rs.

See below for some thought about maybe making that automatic.

## Hacking on CMake

### How to build

CMake expects you to have a build directory which is not your source directory. (Nice!) You can just make one.
Then there are two steps - a configure step and a build step:

```
mkdir build;
cd build;
cmake .. ;
cmake --build . --parallel
```

### How to get the ordered list of deps (and why)

C++'s linker expects dependencies to be listed in a particular order. If A depends on B, then they must be
listed in this order. CMake has code to resovle this, which works great for Tink CC.  But it doesn't seem 
to export that information except through `CMAKE_LINK_DEPENDS_DEBUG_MODE`, and then you have to read
through the output of the build process to get the dependencies.

Someday, maybe these notes will be helpful:

The targets come out between lines like this:

```
target [tink_wrappers] links to
-------------------
```

Here's what I did to get it running:

* Manually cleanup to remove target [Threads::Threads] target [ZLIB::ZLIB] item [-lrt]
* ```
for file in $(cat deps.cleaned); do
  find . -name "lib${file}.a" | tee -a libs;
done
```

* Not libraries all showed up, e.g. protobuf libs ended with `d.a` instead of `.a` (like `libprotobufd.a` but the target output is `protobuf`). That can probably be solved in CMake with some magic.
# After that manually tweak the deps to include in build.rs.

TODO: Make this better - like generate the list as part of cmake. (I looked into it, and CMake really doesn't seem to export the ordered list of deps. Some adivce on line is that the order doesn't matter, but I had problems with just grabbing all the libraries from _deps - i.e. it couldn't resolve
some of the functions which it now resolves fine.)
