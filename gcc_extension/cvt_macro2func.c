#include <stdio.h>

//Ref: https://stackoverflow.com/questions/10405436/anonymous-functions-using-gcc-statement-expressions
/**
 *  It makes use of two gcc extensions:
 *      1. nested functions
 *      2. statement expressions
 */

#define WRAP(macro)                    \
            ({                         \
            void __null__(void) {macro}\
            __null__;                  \
            })

#define function() printf("Hello World\n"); 

struct obj {
    void (*func0)(void);
    void (*func1)(void);
};

// FIXME: Didn't work ...
/* void (*func3)(void) = WRAP(function()); */
/* static void (*func3)(void) = WRAP(function()) */
//

int main(void)
{
    void (*func3)(void) = WRAP(function());

    /* Didn't work, too */
    //static struct obj objs[3] = {

    struct obj objs[3] = {
        [2] = {
            .func0 = WRAP(function()),
            .func1 = WRAP(function()),
        },
    };
   /* 
    func = ({
            void __null__(void) {printf("Hello World\n");};// No matter append `;` at the end of func, all work
            __null__;
            });
    */

    objs[2].func0();
    objs[2].func1();
}
