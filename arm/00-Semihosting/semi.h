///Ref: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0205g/Bgbjjgij.html         

enum SEMI_SVC {
    SYS_OPEN    = 0x01,///open file
    SYS_CLOSE   = 0x02,
    SYS_WRITEC  = 0x03,///write character to `console`
    SYS_WRITE0  = 0x04,///      null-terminated str
    SYS_WRITE   = 0x05,///      file on host(use file describer)
    SYS_READ    = 0x06,///read `file` into buf
    SYS_READC   = 0x07,///read c from `console`
    SYS_ISERROR = 0x08,///FIXME: ? determine if a return code is an error
    SYS_ISTTY   = 0x09,
    SYS_SEEK    = 0x0A,
    ///reserve  = 0x0B,
    SYS_FLEN    = 0x0C,
    SYS_TMPNAM  = 0x0D,///FIXME: ? temporary name
    SYS_REMOVE  = 0x0E,
    SYS_RENAME  = 0x0F,
    SYS_CLOCK   = 0x10,///centisecond from exec
    SYS_TIME    = 0x11,///time from Jan 1, 1970
    SYS_SYSTEM  = 0x12,///paste `command` to command-line interpreter
    SYS_ERRNO   = 0x13,///get the `errno` in C library
    ///reserve  = 0x14,
    SYS_GET_CMDLINE = 0x15,///get the command line used to call the execute
    SYS_HEADPINFO   = 0x16,///
    ///
    SYS_ELAPSED = 0x30,
    SYS_TICKFREQ    = 0x31
};

static int semi_call(int serv, void *param)
{
    register int r0 asm("r0") = serv;
    register void *r1 asm("r1") = param;
    register int result asm("r0");
    asm volatile("bkpt 0xab"
                    :"=r" (result): "r" (r0), "r" (r1));
                    ///FIXME: why `: : ,`

    return result;
}


