#ifndef _SCULL_H
#define _SCULL_H

#include <linux/cdev.h>

#define SCULL_MAJOR     0
#define SCULL_NR_DEVS   1

//struct scull_qset {
//    void **data;
//    struct scull_qset *next;
//}

struct scull_dev {
    //struct scull_qset *data; /* ptr to first qset entry*/
    struct cdev cdev;
};

#endif /* _SCULL_H */
