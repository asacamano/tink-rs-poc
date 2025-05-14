#pragma once 

#include "absl/status/status.h"
#include "absl/status/statusor.h"

extern "C" {
    // This file contains simple, and unsafe wrappers of the tink-cc code.
    // These are only intended to be themselves wrapped by Rust code.

    // The basic idea of this layer to make memory-safety semantics explicit in the names, even
    // though the actual structures do not provide langue-specific memory safety features.
    // For example, `OwnedString` is a pointer to a string that the caller owns, and must free.
    // `BorrowedString` is a pointer to a string that the caller does not own, and must not free.
    //
    // Memory safety is enforced by only defining transformations between these types and their
    // native-langauge memory-safe equivalents.
    //
    // Also, these should only ever be called from Rust, so we get a lot of safety from that, and
    // have no need to do things like check nulls on the way in.

    // An OwnedString is guaranteed to UTF-8 bytes, but not guarantted to be null terminated.
    struct OwnedString {
        // A pointer to a (not necessarily null terminated) value.
        // This is just a string of valid UTF-8 bytes.
        // Safety:
        // * This may be null.
        // * It is owned and the underlying value MUST be freed.
        char   *value_data;
        size_t value_len;
    };

    void wrapped_DeleteString(char *value_data);

    // A BorrowedBytes is just a string of bytes.
    struct BorrowedString {
        // A pointer to a (not necessarily null terminated) value.
        // This is just a string of bytes.
        // Safety:
        // * This may be null.
        // * It is borrowed, and the underlying value MUST NOT be freed.
        const char *value_data;
        size_t     value_len;
    };

    // An OwnedBytes is just a string of bytes.
    struct OwnedBytes {
        // A pointer to a (not necessarily null terminated) value.
        // This is just a string of bytes.
        // Safety:
        // * This may be null.
        // * It is owned and the underlying value MUST be freed.
        char   *value_data;
        size_t value_len;
    };

    void wrapped_DeleteBytes(char *value_data);
    
    // A BorrowedBytes is just a string of bytes.
    struct BorrowedBytes {
        // A pointer to a (not necessarily null terminated) value.
        // This is just a string of bytes.
        // Safety:
        // * This may be null.
        // * It is borrowed, and the underlying value MUST NOT be freed.
        const char *value_data;
        size_t     value_len;
    };
        
    // These comments and values are copyright The Abseil Authors, used under an Apache 2.0 License.
    // See https://github.com/abseil/abseil-cpp/blob/af5128235231b9f9b3ea1368b7d88b6d55560eca/absl/status/status.h#L1C1-L2C1
    enum StatusCode {
        // Source https://github.com/abseil/abseil-cpp/blob/af5128235231b9f9b3ea1368b7d88b6d55560eca/absl/status/status.h#L99

        // OK (gRPC code "OK") does not indicate an error; this value is returned on
        // success. It is typical to check for this value before proceeding on any
        // given call across an API or RPC boundary. To check this value, use the
        // `absl::Status::ok()` member function rather than inspecting the raw code.
        OK = 0,

        // CANCELLED (gRPC code "CANCELLED") indicates the operation was cancelled,
        // typically by the caller.
        CANCELLED = 1,

        // UNKNOWN (gRPC code "UNKNOWN") indicates an unknown error occurred. In
        // general, more specific errors should be raised, if possible. Errors raised
        // by APIs that do not return enough error information may be converted to
        // this error.
        UNKNOWN = 2,

        // INVALID_ARGUMENT (gRPC code "INVALID_ARGUMENT") indicates the caller
        // specified an invalid argument, such as a malformed filename. Note that use
        // of such errors should be narrowly limited to indicate the invalid nature of
        // the arguments themselves. Errors with validly formed arguments that may
        // cause errors with the state of the receiving system should be denoted with
        // `FAILED_PRECONDITION` instead.
        INVALID_ARGUMENT = 3,

        // DEADLINE_EXCEEDED (gRPC code "DEADLINE_EXCEEDED") indicates a deadline
        // expired before the operation could complete. For operations that may change
        // state within a system, this error may be returned even if the operation has
        // completed successfully. For example, a successful response from a server
        // could have been delayed long enough for the deadline to expire.
        DEADLINE_EXCEEDED = 4,

        // NOT_FOUND (gRPC code "NOT_FOUND") indicates some requested entity (such as
        // a file or directory) was not found.
        //
        // `NOT_FOUND` is useful if a request should be denied for an entire class of
        // users, such as during a gradual feature rollout or undocumented allow list.
        // If a request should be denied for specific sets of users, such as through
        // user-based access control, use `PERMISSION_DENIED` instead.
        NOT_FOUND = 5,

        // ALREADY_EXISTS (gRPC code "ALREADY_EXISTS") indicates that the entity a
        // caller attempted to create (such as a file or directory) is already
        // present.
        ALREADY_EXISTS = 6,

        // PERMISSION_DENIED (gRPC code "PERMISSION_DENIED") indicates that the caller
        // does not have permission to execute the specified operation. Note that this
        // error is different than an error due to an *un*authenticated user. This
        // error code does not imply the request is valid or the requested entity
        // exists or satisfies any other pre-conditions.
        //
        // `PERMISSION_DENIED` must not be used for rejections caused by exhausting
        // some resource. Instead, use `RESOURCE_EXHAUSTED` for those errors.
        // `PERMISSION_DENIED` must not be used if the caller cannot be identified.
        // Instead, use `UNAUTHENTICATED` for those errors.
        PERMISSION_DENIED = 7,

        // RESOURCE_EXHAUSTED (gRPC code "RESOURCE_EXHAUSTED") indicates some resource
        // has been exhausted, perhaps a per-user quota, or perhaps the entire file
        // system is out of space.
        RESOURCE_EXHAUSTED = 8,

        // FAILED_PRECONDITION (gRPC code "FAILED_PRECONDITION") indicates that the
        // operation was rejected because the system is not in a state required for
        // the operation's execution. For example, a directory to be deleted may be
        // non-empty, an "rmdir" operation is applied to a non-directory, etc.
        //
        //  Some guidelines that may help a service implementer in deciding between
        // `FAILED_PRECONDITION`, `ABORTED`, and `UNAVAILABLE`:
        //
        //  (a) Use `UNAVAILABLE` if the client can retry just the failing call.
        //  (b) Use `ABORTED` if the client should retry at a higher transaction
        //      level (such as when a client-specified test-and-set fails, indicating
        //      the client should restart a read-modify-write sequence).
        //  (c) Use `FAILED_PRECONDITION` if the client should not retry until
        //      the system state has been explicitly fixed. For example, if a "rmdir"
        //      fails because the directory is non-empty, `FAILED_PRECONDITION`
        //      should be returned since the client should not retry unless
        //      the files are deleted from the directory.
        FAILED_PRECONDITION = 9,

        // StatusCode::kAborted
        //
        // ABORTED (gRPC code "ABORTED") indicates the operation was aborted,
        // typically due to a concurrency issue such as a sequencer check failure or a
        // failed transaction.
        //
        // See the guidelines above for deciding between `FAILED_PRECONDITION`,
        // `ABORTED`, and `UNAVAILABLE`.
        ABORTED = 10,

        // OUT_OF_RANGE (gRPC code "OUT_OF_RANGE") indicates the operation was
        // attempted past the valid range, such as seeking or reading past an
        // end-of-file.
        //
        // Unlike `INVALID_ARGUMENT`, this error indicates a problem that may
        // be fixed if the system state changes. For example, a 32-bit file
        // system will generate `INVALID_ARGUMENT` if asked to read at an
        // offset that is not in the range [0,2^32-1], but it will generate
        // `OUT_OF_RANGE` if asked to read from an offset past the current
        // file size.
        //
        // There is a fair bit of overlap between `FAILED_PRECONDITION` and
        // `OUT_OF_RANGE`.  We recommend using `OUT_OF_RANGE` (the more specific
        // error) when it applies so that callers who are iterating through
        // a space can easily look for an `OUT_OF_RANGE` error to detect when
        // they are done.
        OUT_OF_RANGE = 11,

        // UNIMPLEMENTED (gRPC code "UNIMPLEMENTED") indicates the operation is not
        // implemented or supported in this service. In this case, the operation
        // should not be re-attempted.
        UNIMPLEMENTED = 12,

        // INTERNAL (gRPC code "INTERNAL") indicates an internal error has occurred
        // and some invariants expected by the underlying system have not been
        // satisfied. This error code is reserved for serious errors.
        INTERNAL = 13,

        // UNAVAILABLE (gRPC code "UNAVAILABLE") indicates the service is currently
        // unavailable and that this is most likely a transient condition. An error
        // such as this can be corrected by retrying with a backoff scheme. Note that
        // it is not always safe to retry non-idempotent operations.
        //
        // See the guidelines above for deciding between `FAILED_PRECONDITION`,
        // `ABORTED`, and `UNAVAILABLE`.
        UNAVAILABLE = 14,

        // DATA_LOSS (gRPC code "DATA_LOSS") indicates that unrecoverable data loss or
        // corruption has occurred. As this error is serious, proper alerting should
        // be attached to errors such as this.
        DATA_LOSS = 15,

        // UNAUTHENTICATED (gRPC code "UNAUTHENTICATED") indicates that the request
        // does not have valid authentication credentials for the operation. Correct
        // the authentication and try again.
        UNAUTHENTICATED = 16,

        // DO_NOT_USE_RESERVED_FOR_FUTURE_EXPANSION_USE_DEFAULT_IN_SWITCH_INSTEAD_
        //
        // NOTE: this error code entry should not be used and you should not rely on
        // its value, which may change.
        //
        // The purpose of this enumerated value is to force people who handle status
        // codes with `switch()` statements to *not* simply enumerate all possible
        // values, but instead provide a "default:" case. Providing such a default
        // case ensures that code will compile when new codes are added.
    DO_NOT_USE_RESERVED_FOR_FUTURE_EXPANSION_USE_DEFAULT_IN_SWITCH_INSTEAD_ = 20
    };
    
    // A TinkStatus is a status code and optional message. See absl::StatusOr
    struct OwnedTinkStatus {
        // A numeric code indicating whether the operation succeeded.
        size_t      code;
        // An optional message describing the result.
        OwnedString message;
    };

    // A TinkStatusOrString has 2 valid states. Either the code is OK, and a value is populated,
    // or the code is not OK, and there is no value.
    //
    // The value is 
    struct OwnedTinkStatusOrBytes {
        // The status of the operation
        OwnedTinkStatus result;
        // The result, which may be empty.
        OwnedBytes value;
    };
}

// Non-exported OwnedString conversions
std::string toStdString(OwnedString s);

OwnedString toOwnedString(std::string s);

// Non-exported BorrowedString conversions
absl::string_view toStringView(BorrowedString s);

// Non-exported OwnedBytes conversions
std::string toStdString(OwnedBytes s);

OwnedBytes toOwnedBytes(std::string s);

// Non-exported BorrowedBytes conversions
absl::string_view toStringView(BorrowedBytes s);

// Non-exported OwnedTinkStatus conversions
OwnedTinkStatus toOwnedTinkStatus(absl::Status s);

// Non-exported OwnedTinkStatusOrBytes conversions
OwnedTinkStatusOrBytes toOwnedTinkStatusOrBytes(absl::StatusOr<std::string> s);
