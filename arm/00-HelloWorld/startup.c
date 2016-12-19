#include <stdint.h>


extern void main(void);

void re_hdlr(void)
{
    main(); ///start here
}

__attribute((section(".isr_vec")))
uint32_t *isr_vecs[] = {
    0, ///MSP initialize
    (uint32_t *) re_hdlr /// enter pt
};
