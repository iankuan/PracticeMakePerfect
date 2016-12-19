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
