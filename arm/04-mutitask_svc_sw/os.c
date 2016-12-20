#include <stdint.h>

#include "reg.h"
#include "init.h"

#define STACK_SIZE 256

#define TASK_LIMIT 2

/*exception return*/
#define HANDLER_MSP 0xFFFFFFF1
#define THREAD_MSP  0xFFFFFFF9
#define THREAD_PSP  0xFFFFFFFD

extern uint32_t *ctx_sw(uint32_t *);
extern void syscall();

#define USART_SR_TXE ((uint16_t) 0x0080)

/* USART TXE Flag
 * This flag is cleared when data is written to USARTx_DR and
 * set when that data is transferred to the TDR
 */

int puts(const char *str)
{
    while(*str) {
        ///FIXME: why use it?
        ///while(*(USART2_SR) & USART_SR_TXE) ;
        while(!(*(USART2_SR) & USART_SR_TXE)) ;
            *(USART2_DR) = *str++ & 0xFF;
    }

    return 0;
}

///create task
uint32_t *create_task(uint32_t *stack, void (*start)(void))
{
    static int first = 1;
                            ///here is the end not last entry
    stack += STACK_SIZE - 32;///FIXME: why 16

    if(first) {
        stack[8] = (uint32_t) start;
        first = 0;
    }
    else {
        stack[8] = (uint32_t) THREAD_PSP;
        stack[15]= (uint32_t) start;
        stack[16]= (uint32_t) 0x01000000;///PSR Thumb bit
    }

    return stack = ctx_sw(stack);
}

/*void task0(void)
{
    puts("enter 1st the task0\n");
    puts("svc to kernel mode\n");
    syscall();
    puts("enter 2st the task0\n");
    puts("svc to kernel mode\n");
    syscall();

    while(1) ;
}*/

void task0(void)
{
    puts("task0: Created\n");
    puts("task0: Enter => return to kernel\n");
    syscall();
    
    while(1) {
        puts("task0: Executed\n");
        puts("task0: While => return to kernel\n");
        syscall();
    }
}

void task1(void)
{
    puts("task1: Created\n");
    puts("task1: Enter => return to kernel\n");
    syscall();
    
    while(1) {
        puts("task1: Executed\n");
        puts("task1: While => return to kernel\n");
        syscall();
    }
}

int main()
{
    init();
    /// We should store these manually
    /// p4 - p11, lr
    uint32_t task_stack[TASK_LIMIT][STACK_SIZE];
    uint32_t *task_sp[TASK_LIMIT];

    puts("os main start\n");
    puts("OS: First create task0\n");
    task_sp[0] = create_task(task_stack[0], &task0);
    
    puts("OS: Second create task1\n");
    task_sp[1] = create_task(task_stack[1], &task1);

    puts("\nOS: Start multitasking back to OS\n");
    uint32_t cur_task = 0;

    while(1) {
        puts("OS: Activate next task\n");
        task_sp[cur_task] = ctx_sw(task_sp[cur_task]);
        puts("OSL Back to OS\n");

        cur_task = cur_task == TASK_LIMIT - 1 ? 0: cur_task + 1;
    }
}
