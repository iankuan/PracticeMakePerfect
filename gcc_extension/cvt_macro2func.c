#include <stdio.h>

//Ref: https://stackoverflow.com/questions/10405436/anonymous-functions-using-gcc-statement-expressions
/**
 *  It makes use of two gcc extensions:
 *      1. nested functions
 *      2. statement expressions
 */

int main(void)
{
    void (*func)(void);
    func = ({
            void __null__(void) {printf("Hello World\n");}
            __null__;
            });
    /* 
    func = ({
            void __null__(void) {printf("Hello World\n");};// No matter append `;` at the end of func, all work
            __null__;
            });
    */


    func();
}
