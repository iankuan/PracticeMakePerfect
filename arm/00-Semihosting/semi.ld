ENTRY(re_hdlr)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 128K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vec))
        *.(text)
    } >FLASH
}
