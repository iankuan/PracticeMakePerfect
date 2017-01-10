#include <stdio.h>
#include <string.h>

struct _st {
    char *str;
    int     a;
    int     b;
};

#define init_struct(var, _str, _a, _b) \
    struct _st var = { \
        .str = _str, \
        .a   = _a, \
        .b   = _b, \
    };

#define init_struct1(var, _str, _a, _b) \
    struct _st1 { \
        char str[strlen(_str) + 1]; \
        int     a; \
        int     b; \
    }; \
    /*struct _st1 var = { \
        .a = _a,\
        .b = _b,\
    }; \
    strcpy(var.str, _str);*/
   
/*    struct _st1 var; \
    var.str = _str; \///FIXME: var.str is not assignable...
    var.a = _a;\
    var.b = _b;*/

    ///FIXME: error: variable-sized object may not be initialized
    /*struct _st1 var = { \
        .str = _str, \
        .a   = _a, \
        .b   = _b, \
    };*/

void func()
{
    init_struct1(st1, "This is str", 10, 20);
    init_struct1(st1, "str", 10, 20);///FIXME:Redefinition: It is a problem in Variable-len array redefinition
}

int main() {

    init_struct(st, "This is str", 10, 20);

    func();

    printf("Use GDB\n");

    return 0;
}
