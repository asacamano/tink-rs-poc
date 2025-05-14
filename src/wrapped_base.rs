use crate::tink_error::StatusCode;
use crate::tink_error::TinkError;

// --------------------------- Wrapped stuff goes here --------------------

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    fn wrapped_DeleteString(value_data: *mut u8);
}

#[repr(C)]
pub(crate) struct OwnedString {
    // A pointer to a (not necessarily null terminated) value.
    // This is just a string of valid UTF-8 bytes.
    // Safety:
    // * This may be null.
    // * It is owned and the underlying value MUST be freed.
    value_data: *mut u8,
    value_len: usize,
}

impl Drop for OwnedString {
    fn drop(&mut self) {
        unsafe {
            if !self.value_data.is_null() {
                wrapped_DeleteString(self.value_data);
                // Just in case.
                self.value_data = std::ptr::null_mut();
            }
        }
    }
}

impl Into<String> for OwnedString {
    fn into(mut self) -> String {
        unsafe {
            if !self.value_data.is_null() {
                let result = String::from_utf8_unchecked(Vec::from_raw_parts(
                    self.value_data,
                    self.value_len,
                    std::mem::size_of::<u8>(),
                ));
                self.value_data = std::ptr::null_mut();
                return result;
            } else {
                String::new()
            }
        }
    }
}

#[repr(C)]
pub(crate) struct BorrowedString {
    // A pointer to a (not necessarily null terminated) value.
    // This is just a string of valid UTF-8 bytes.
    // Safety:
    // * This may be null.
    // * It is borrowed, and the underlying value MUST NOT be freed.
    value_data: *const u8,
    value_len: usize,
}

impl From<&str> for BorrowedString {
    fn from(s: &str) -> Self {
        BorrowedString {
            value_data: s.as_ptr(),
            value_len: s.len(),
        }
    }
}

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    fn wrapped_DeleteBytes(value_data: *mut u8);
}

#[repr(C)]
pub(crate) struct OwnedBytes {
    // A pointer to a set of bytes.
    // Safety:
    // * This may be null.
    // * It is owned and the underlying value MUST be freed.
    value_data: *mut u8,
    value_len: usize,
}

impl Drop for OwnedBytes {
    fn drop(&mut self) {
        unsafe {
            if !self.value_data.is_null() {
                wrapped_DeleteBytes(self.value_data);
                // Just in case.
                self.value_data = std::ptr::null_mut();
            }
        }
    }
}

impl Into<Vec<u8>> for OwnedBytes {
    fn into(mut self) -> Vec<u8> {
        unsafe {
            if !self.value_data.is_null() {
                let result =
                    Vec::from_raw_parts(self.value_data, self.value_len, std::mem::size_of::<u8>());
                self.value_data = std::ptr::null_mut();
                return result;
            } else {
                Vec::new()
            }
        }
    }
}

#[repr(C)]
pub(crate) struct BorrowedBytes {
    // A pointer to a bytes.
    // Safety:
    // * This may be null.
    // * It is borrowed, and the underlying value MUST NOT be freed.
    value_data: *const u8,
    value_len: usize,
}

impl From<&[u8]> for BorrowedBytes {
    fn from(s: &[u8]) -> Self {
        BorrowedBytes {
            value_data: s.as_ptr(),
            value_len: s.len(),
        }
    }
}

#[repr(C)]
pub(crate) struct OwnedTinkStatusOrBytes {
    pub(crate) status: OwnedTinkStatus,
    pub(crate) owned: OwnedBytes,
}

impl From<OwnedTinkStatusOrBytes> for Result<Vec<u8>, TinkError> {
    fn from(status_or_owned: OwnedTinkStatusOrBytes) -> Self {
        if status_or_owned.status.code != StatusCode::Ok {
            Err(status_or_owned.status.into())
        } else if status_or_owned.owned.value_data.is_null() {
            Err(TinkError::new(
                StatusCode::Unknown as usize,
                "Bytes pointer is null",
            ))
        } else {
            Ok(status_or_owned.owned.into())
        }
    }
}

#[repr(C)]
pub(crate) struct OwnedTinkStatus {
    // A numeric code indicating whether the operation succeeded.
    pub(crate) code: usize,
    // An optional message describing the result.
    pub(crate) message: OwnedString,
}

impl From<OwnedTinkStatus> for Result<(), TinkError> {
    fn from(status: OwnedTinkStatus) -> Self {
        if status.code != StatusCode::Ok {
            let code = status.code;
            if status.message.value_data.is_null() {
                return Err(TinkError::new(code, ""));
            }
            let message: String = status.message.into();
            return Err(TinkError::new(
                code,
                format!("Error code {code}: \"{message}\"").as_str(),
            ));
        }
        Ok(())
    }
}

impl OwnedTinkStatus {
    pub(crate) fn _ok(&self) -> bool {
        self.code == StatusCode::Ok
    }
}
