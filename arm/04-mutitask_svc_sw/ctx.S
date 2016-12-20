.thumb
.syntax unified /*TODO: why*/

.global ctx_sw
ctx_sw:
    /*save kernel*/
    mrs ip, psr /*save Program Status Register*/
    push {r4-r11, ip, lr}

    /*switch to psp*/
    msr psp, r0///arg: user stack
    mov r0, #3 ///user+psp
    msr control, r0

    /*load user state*/
    pop {r4-r11, lr}

    /*jump to user task*/
    bx lr

/*svc handler*/
.type svc_hdlr, %function/*TODO: MUST HAVE IT,why?*/
.global svc_hdlr
svc_hdlr:
    /*save user state*/
    mrs r0, psp
    stmdb r0!, {r4-r11, lr}/*TODO: why need lr?*/
    /*TODO: why stm`db`? Because of `Decrease Before`, it is need to replace the pop!*/
    /*msr psp, r0*/

    /* load kernel state */
    pop {r4-r11, ip, lr}
    msr psr, ip

    bx lr
