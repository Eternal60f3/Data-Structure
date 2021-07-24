#ifndef STACK_C_H
#define STACK_C_H
#include <stdbool.h>
#define SIZE 200

typedef struct
{
    char datas[SIZE];
    int top;
    int count;
} stack_c;

// 初始化栈
void InitStack_c(stack_c *);

// 判断栈是否为空
bool StackIsEmpty_c(const stack_c *);

// 判断栈是否已满
bool StackIsFull_c(const stack_c *);

// 获取栈中的项数
int LenStack_c(const stack_c *);

// 读取栈顶项
bool StackGetTop_c(const stack_c *, char *);

// 进栈操作
bool StackPush_c(stack_c *, char);

// 出栈操作
bool StackPop_c(stack_c *, char *);

// 清空栈
bool ClearStack_c(stack_c *);
#endif
