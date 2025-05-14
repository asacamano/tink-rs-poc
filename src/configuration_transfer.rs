// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {}

/// A specific type for opaque pointers to C++ Configuration objects, which helps ensure
/// type-safety throughout the transfer layer.
/// See https://doc.rust-lang.org/nomicon/ffi.html#representing-opaque-structs
#[repr(C)]
pub(crate) struct CCConfigurationOpaquePointer {
    _data: (),
    _marker: core::marker::PhantomData<(*mut u8, core::marker::PhantomPinned)>,
}

/// StaticConfiguration can be transferred between Rust and C++, and is treated as a static variable and never needs to be deleted or freed.
///
/// Nobody is not expected to delete the underlying object.
///
/// Note that in the actual StaticConfiguration itself is just a pass-by-value wrapper around the actual object.
#[repr(C)]
#[derive(Clone, Debug)]
pub(crate) struct StaticConfiguration {
    pub(crate) cc_ptr: *mut CCConfigurationOpaquePointer,
}
