CROSS_COMPILE ?= arm-none-eabi-

CC := $(CROSS_COMPILE)gcc
OBJC := $(CROSS_COMPILE)objcopy
OBJD := $(CROSS_COMPILE)objdump

LNK ?= ld
LNKSCRIPT = hello.ld

GDB := $(CROSS_COMPILE)gdb
GDB_CFG = gdb.cfg

CFLAGS =  -Wall -O0 -g3

# Machine
CPU = cortex-m3
CFLAGS += -mcpu=$(CPU) -mthumb

TARGET = hello


BIN = $(TARGET).bin
ELF = $(TARGET).elf
LST = $(TARGET).list
SRC = $(wildcard *.c)

# for qemu
KER = $(BIN)
MACH= stm32-p103

#specified rule
$(ELF): CFLAGS += -fno-common -T $(LNKSCRIPT) -nostartfiles

all: $(BIN) $(LST)

$(BIN): $(ELF)
	$(OBJC) -Obinary $^ $@

$(ELF): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

# Disassembly
$(LST): $(ELF)
	$(OBJD) -S $^ > $(LST)

qemu: $(BIN)
	qemu-system-arm -M $(MACH) -nographic -kernel $(KER)

qemu-debug:
	qemu-system-arm -M $(MACH) -nographic -kernel $(KER) -S -s

qemu-gdb:
	$(GDB) $(ELF) -x $(GDB_CFG)

clean:
	$(RM) -rf $(ELF) $(BIN) $(LST)
