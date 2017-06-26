#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#include <linux/slab.h>

#include "scull.h"

int scull_major = SCULL_MAJOR;
int scull_minor = 0;
const int scull_nr_devs = SCULL_NR_DEVS;

/* main scull devices */
struct scull_dev *scull_devices;

static void __exit scull_cleanup_module(void)
{
    dev_t devno = MKDEV(scull_major, scull_minor);

    if (scull_devices) {
        kfree(scull_devices);
    }

    unregister_chrdev_region(devno, scull_nr_devs);

    printk(KERN_ALERT "[Dev exit] eject module, major: %d, minor: %d\n",
        scull_major, scull_minor);
}

static int __init scull_init_module(void)
{
    int result;
    dev_t dev;

    if (scull_major) {
        dev = MKDEV(scull_major, scull_minor);
        result = register_chrdev_region(dev, scull_nr_devs, "scull");
    } else {
        result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
                    "scull");
        scull_major = MAJOR(dev);
    }
    if (result < 0) {
        printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
        return result;
    }

    printk(KERN_ALERT "[Dev init] major %d, minor %d\n", scull_major, scull_minor);

    scull_devices = kmalloc(scull_nr_devs * sizeof(struct scull_dev), GFP_KERNEL);
    if (!scull_devices) {
        result = -ENOMEM;
        goto fail;
    }
    memset(scull_devices, 0, scull_nr_devs * sizeof(struct scull_dev));

    /* Initialize each scull device */
    //for (int i = 0; i < scull_nr_devs; i++) {
    //}

    return 0;

fail:
    scull_cleanup_module();
    return result;
}

module_init(scull_init_module);
module_exit(scull_cleanup_module);
