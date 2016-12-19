.thumb
.syntax unified

.global syscall
syscall:
    svc 0
    bx lr
