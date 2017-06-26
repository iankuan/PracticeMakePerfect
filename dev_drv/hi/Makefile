obj-m = hi_dev_drv.o
kobj = hi_dev_drv.ko

KERNEL_VER ?= $(shell uname -r)
KERNEL_DIR ?= /lib/modules/$(KERNEL_VER)/build
PWD ?= $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

insmod:
	sudo insmod $(kobj)

modinfo:
	sudo modinfo $(kobj)

rmmod:
	sudo rmmod $(kobj)
