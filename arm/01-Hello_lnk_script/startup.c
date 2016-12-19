#include <stdint.h>

extern void main(void);

/* start address for the initialization values of the .data section.
defined in linker script */
extern uint32_t sidata;
/* start address for the .data section. defined in linker script */
extern uint32_t sdata;
/* end address for the .data section. defined in linker script */
extern uint32_t edata;
/* start address for the .bss section. defined in linker script */
extern uint32_t sbss;
/* end address for the .bss section. defined in linker script */
extern uint32_t ebss;
/* end address for the stack. defined in linker script */
extern uint32_t estack;

void re_hdlr(void)
{
    main(); ///start here
}

void nmi_hdlr(void)
{
    while(1);
}

void hdf_hdlr(void)
{
    while(1);
}

__attribute((section(".isr_vec")))
uint32_t *isr_vecs[] = {
    &estack, ///MSP initialize
    (uint32_t *) re_hdlr, /// enter pt
    (uint32_t *) nmi_hdlr,
    (uint32_t *) hdf_hdlr
};
