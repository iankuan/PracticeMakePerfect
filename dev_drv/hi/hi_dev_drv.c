#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL"); //GPL, GPL v2 ...

MODULE_AUTHOR("Yen-Kuan Wu");
MODULE_DESCRIPTION("Implement a simple module to show \"Hi Device Driver\"");
//MODULE_VERSION("");
//MODULE_ALIAS("");
//MODULE_DEVICE_TABLE("");

//__devinitdata
int __initdata disappear_after_init = 666;

//__devinit: for hotpluggable devices
static int __init hi_init(void)
{
    printk(KERN_ALERT "Hi Device Driver %d\n", disappear_after_init);
    return 0;
}
//EXPORT_SYMBOL(hi_init);
//EXPORT_GPL_SYMBOL(hi_init);

static void __exit hi_exit(void)
{
    printk(KERN_ALERT "Bye Device Driver\n");
    //printk(KERN_ALERT "Bye Device Driver %d\n", disappear_after_init);
}

module_init(hi_init);
module_exit(hi_exit);
