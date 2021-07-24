#ifndef STACK_LL_H
#define STACK_LL_H
#include <stdbool.h>
#define SIZE 200

typedef struct
{
    long long datas[SIZE];
    int top;
    int count;
} stack_ll;

// 初始化栈
void InitStack_ll(stack_ll *);

// 判断栈是否为空
bool StackIsEmpty_ll(const stack_ll *);

// 判断栈是否已满
bool StackIsFull_ll(const stack_ll *);

// 获取栈中的项数
int LenStack_ll(const stack_ll *);

// 读取栈顶项
bool StackGetTop_ll(const stack_ll *, long long *);

// 进栈操作
bool StackPush_ll(stack_ll *, long long);

// 出栈操作
bool StackPop_ll(stack_ll *, long long *);

// 清空栈
bool ClearStack_ll(stack_ll *);
#endif