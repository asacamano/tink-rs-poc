// TinkError is the way the tink-rs API exposes errors to callers.
//
// It is meant to be part of the public API, idiomatic rust.

use crate::wrapped_base::OwnedTinkStatus;
use std::convert::From;
use std::convert::TryFrom;
use std::error::Error;

// This is a the Rust-native version of the C++ Tink StatusCode enum.
// It needs to maintain the same values as the C++ enum, and by convention
// all of the data from C++ to Rust will treat this as a usize.
#[repr(usize)]
#[derive(Clone, Debug, Hash, Copy, PartialEq, Eq)]
pub enum StatusCode {
    Ok = 0,
    Cancelled = 1,
    Unknown = 2,
    InvalidArgument = 3,
    DeadlineExceeded = 4,
    NotFound = 5,
    AlreadyExists = 6,
    PermissionDenied = 7,
    ResourceExhausted = 8,
    FailedPrecondition = 9,
    Aborted = 10,
    OutOfRange = 11,
    Unimplemented = 12,
    Internal = 13,
    Unavailable = 14,
    DataLoss = 15,
    Unauthenticated = 16,
    // Used if we every get a value from C++ which we don't know about.
    UnimplementedTinkStatusCode = 17,
    DoNotUseReservedForFutureExpansionUseDefaultInSwitchInstead_ = 20,
}

impl TryFrom<usize> for StatusCode {
    type Error = TinkError;
    fn try_from(value: usize) -> Result<Self, TinkError> {
        if value < StatusCode::UnimplementedTinkStatusCode as usize {
            unsafe { Ok(std::mem::transmute(value)) }
        } else {
            Err(TinkError::new(
                StatusCode::UnimplementedTinkStatusCode as usize,
                format!("Invalid StatusCode value: {}", value).as_str(),
            ))
        }
    }
}

impl PartialEq<usize> for StatusCode {
    fn eq(&self, other: &usize) -> bool {
        // A status code will always map to a valid usize.
        unsafe { std::mem::transmute::<StatusCode, usize>(*self) == *other }
    }
}

impl PartialEq<StatusCode> for usize {
    fn eq(&self, other: &StatusCode) -> bool {
        unsafe { *self == std::mem::transmute::<StatusCode, usize>(*other) }
    }
}

#[derive(Debug)]
pub struct TinkError {
    code: StatusCode,
    msg: String,
    src: Option<Box<dyn Error + Send>>,
}

impl Error for TinkError {}

impl TinkError {
    pub(crate) fn new(code: usize, msg: &str) -> Self {
        let enum_code = StatusCode::try_from(code);
        if enum_code.is_ok() {
            return TinkError {
                code: enum_code.unwrap(),
                msg: msg.into(),
                src: None,
            };
        } else {
            return enum_code.unwrap_err();
        }
    }
}

impl From<OwnedTinkStatus> for TinkError {
    fn from(value: OwnedTinkStatus) -> TinkError {
        let enum_code = StatusCode::try_from(value.code);
        if enum_code.is_ok() {
            TinkError {
                code: enum_code.unwrap(),
                msg: value.message.into(),
                src: None,
            }
        } else {
            enum_code.unwrap_err()
        }
    }
}

impl std::fmt::Display for TinkError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if let Some(src) = &self.src {
            write!(f, "{:?}:{}: {}", self.code, self.msg, src)
        } else {
            write!(f, "{:?}:{}", self.code, self.msg)
        }
    }
}

impl From<&str> for TinkError {
    fn from(msg: &str) -> Self {
        TinkError {
            code: StatusCode::Unknown,
            msg: msg.to_string(),
            src: None,
        }
    }
}

impl From<String> for TinkError {
    fn from(msg: String) -> Self {
        TinkError {
            code: StatusCode::Unknown,
            msg,
            src: None,
        }
    }
}
