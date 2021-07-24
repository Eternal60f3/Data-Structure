#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#define SIZE 200

typedef char Item;
typedef struct
{
    Item datas[SIZE];
    int top;
    int count;
} stack;

// 初始化栈
void InitStack(stack *);

// 判断栈是否为空
bool StackIsEmpty(const stack *);

// 判断栈是否已满
bool StackIsFull(const stack *);

// 获取栈中的项数
int LenStack(const stack *);

// 读取栈顶项
bool StackGetTop(const stack *, Item *);

// 进栈操作
bool StackPush(stack *, Item);

// 出栈操作
bool StackPop(stack *, Item *);

// 清空栈
bool ClearStack(stack *);
#endif
