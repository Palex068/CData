#ifndef _S21_MAC_ERRNO_H
#define _s21_MAC_ERRNO_H

#define MAX_ERROR_LEN 256

#define UNKNOWN_PREFIX "Unknown error: "

#define EPERM 1            /* Operation not permitted. */
#define ENOENT 2           /* No such file or directory. */
#define ESRCH 3            /* No such process. */
#define EINTR 4            /* Interrupted function call */
#define EIO 5              /* Input/output error */
#define ENXIO 6            /* No such device or address. */
#define E2BIG 7            /* Arg list too long. */
#define ENOEXEC 8          /* Exec format error. */
#define EBADF 9            /* Bad file descriptor. */
#define ECHILD 10          /* No child processes. */
#define EDEADLK 11         /* Resource deadlock avoided. */
#define ENOMEM 12          /* Cannot allocate memory. */
#define EACCES 13          /* Permission denied. */
#define EFAULT 14          /* Bad address. */
#define ENOTBLK 15         /* Not a block device. */
#define EBUSY 16           /* Resource busy. */
#define EEXIST 17          /* File exists. */
#define EXDEV 18           /* Improper link. */
#define ENODEV 19          /* Operation not supported by device. */
#define ENOTDIR 20         /* Not a directory. */
#define EISDIR 21          /* Is a directory. */
#define EINVAL 22          /* Invalid argument. */
#define ENFILE 23          /* Too many open files in system. */
#define EMFILE 24          /* Too many open files. */
#define ENOTTY 25          /* Inappropriate ioctl for device. */
#define ETXTBSY 26         /* Text file busy. */
#define EFBIG 27           /* File too large. */
#define ENOSPC 28          /* Device out of space. */
#define ESPIPE 29          /* Illegal seek. */
#define EROFS 30           /* Read-only file system. */
#define EMLINK 31          /* Too many links. */
#define EPIPE 32           /* Broken pipe. */
#define EDOM 33            /* Numerical argument out of domain. */
#define ERANGE 34          /* Numerical result out of range. */
#define EAGAIN 35          /* Resource temporarily unavailable. */
#define EINPROGRESS 36     /* Operation now in progress. */
#define EALREADY 37        /* Operation already in progress. */
#define ENOTSOCK 38        /* Socket operation on non-socket. */
#define EDESTADDRREQ 39    /* Destination address required. */
#define EMSGSIZE 40        /* Message too long. */
#define EPROTOTYPE 41      /* Protocol wrong type for socket. */
#define ENOPROTOOPT 42     /* Protocol not available. */
#define EPROTONOSUPPORT 43 /* Protocol not supported. */
#define ESOCKTNOSUPPORT 44 /* Socket type not supported. */
#define ENOTSUP 45         /* Not supported. */
#define EPFNOSUPPORT 46    /* Protocol family not supported. */
#define EAFNOSUPPORT 47  /* Address family not supported by protocol family. */
#define EADDRINUSE 48    /* Address already in use. */
#define EADDRNOTAVAIL 49 /* Cannot assign requested address. */
#define ENETDOWN 50      /* Network is down. */
#define ENETUNREACH 51   /* Network is unreachable. */
#define ENETRESET 52     /* Network dropped connection on reset. */
#define ECONNABORTED 53  /* Software caused connection abort. */
#define ECONNRESET 54    /* Connection reset by peer. */
#define ENOBUFS 55       /* No buffer space available. */
#define EISCONN 56       /* Socket is already connected. */
#define ENOTCONN 57      /* Socket is not connected. */
#define ESHUTDOWN 58     /* Cannot send after socket shutdown. */
#define ETIMEDOUT 60     /* Operation timed out. */
#define ECONNREFUSED 61  /* Connection refused. */
#define ELOOP 62         /* Too many levels of symbolic links. */
#define ENAMETOOLONG 63  /* File name too long. */
#define HOSTDOWN 64      /* Host is down. */
#define EHOSTUNREACH 65  /* No route to host. */
#define ENOTEMPTY 66     /* Directory not empty. */
#define EPROCLIM 67      /* Too many processes. */
#define EUSERS 68        /* Too many users. */
#define EDQUOT 69        /* Disc quota exceeded. */
#define ESTALE 70        /* Stale NFS file handle. */
#define EBADRPC 72       /* RPC struct is bad. */
#define ERPCMISMATCH 73  /* RPC version wrong. */
#define EPROGUNAVAIL 74  /* RPC prog. not avail. */
#define EPROGMISMATCH 75 /* Program version wrong. */
#define EPROCUNAVAIL 76  /* Bad procedure for program. */
#define ENOLCK 77        /* No locks available. */
#define ENOSYS 78        /* Function not implemented. */
#define EFTYPE 79        /* Inappropriate file type or format. */
#define EAUTH 80         /* Authentication error. */
#define ENEEDAUTH 81     /* Need authenticator. */
#define EPWROFF 82       /* Device power is off. */
#define EDEVERR 83       /* Device error. */
#define EOVERFLOW 84     /* Value too large to be stored in data type. */
#define EBADEXEC 85      /* Bad executable (or shared library). */
#define EBADARCH 86      /* Bad CPU type in executable. */
#define ESHLIBVERS 87    /* Shared library version mismatch. */
#define EBADMACHO 88     /* Malformed Mach-o file. */
#define ECANCELED 89     /* Operation canceled. */
#define EIDRM 90         /* Identifier removed. */
#define ENOMSG 91        /* No message of desired type. */
#define EILSEQ 92        /* Illegal byte sequence. */
#define ENOATTR 93       /* Attribute not found. */
#define EBADMSG 94       /* Bad message. */
#define EMULTIHOP 95     /* Reserved. */
#define ENODATA 96       /* No message available. */
#define NOLINK 97        /* Reserved. */
#define ENOSR 98         /* No STREAM resources. */
#define ENOSTR 99        /* Not a STREAM. */
#define EPROTO 100       /* Protocol error. */
#define ETIME 101        /* STREAM ioctl() timeout. */
#define EOPNOTSUPP 102   /* Operation not supported on socket.*/

#define _s21_sys_errlist s21_sys_errlist
#define _s21_sys_nerr s21_sys_nerr

const char *const _s21_sys_errlist[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
int _s21_sys_nerr = {sizeof _s21_sys_errlist / sizeof _s21_sys_errlist[0]};

#endif