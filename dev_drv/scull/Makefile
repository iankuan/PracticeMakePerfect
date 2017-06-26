target = scull
obj-m = $(target).o
kobj = $(target).ko

$(target)-objs = main.o

KERNEL_VER ?= $(shell uname -r)
KERNEL_DIR ?= /lib/modules/$(KERNEL_VER)/build
PWD ?= $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

insmod:
	sudo insmod $(kobj)
rmmod:
	sudo rmmod $(kobj)

modinfo:
	sudo modinfo $(kobj)

modprobe:
	sudo modprobe $(kobj)
