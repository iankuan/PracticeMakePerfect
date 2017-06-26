#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Can I put anything here without warning?");

static int hi_init(void)
{
    printk(KERN_ALERT "Hi Device Driver\n");
    return 0;
}

static void hi_exit(void)
{
    printk(KERN_ALERT "Bye Device Driver\n");
}

module_init(hi_init);
module_exit(hi_exit);
