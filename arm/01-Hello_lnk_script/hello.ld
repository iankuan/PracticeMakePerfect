ENTRY(re_hdlr)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 128K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH =  40K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vec))
        *(.text)
        *(.text.*)
        *(.rodata)
        sromdev = .;
        eromdev = .;
        sidata = .;
    } >FLASH

    .data : AT(sidata)
    {
        sdata = .;
        *(.data)
        *(.data.*)
        edata = .;
    } >SRAM

    .bss :
    {
        sbss = .;
        *(.bss)
        ebss = .;
    } >SRAM

    estack = ORIGIN(SRAM) + LENGTH(SRAM);
}
