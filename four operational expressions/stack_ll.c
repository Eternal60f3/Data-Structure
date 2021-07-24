#include "stack_ll.h"

// 初始化
void InitStack_ll(stack_ll *list)
{
    list->top = -1;
    list->count = 0;
}

// 判断栈是否为空
bool StackIsEmpty_ll(const stack_ll *list)
{
    return list->count == 0;
}

// 判断栈是否已满
bool StackIsFull_ll(const stack_ll *list)
{
    return list->count == SIZE;
}

// 获取栈中的项数
int LenStack_ll(const stack_ll *list)
{
    return list->count;
}

// 读取栈顶项
bool StackGetTop_ll(const stack_ll *list, long long *data)
{
    if (StackIsEmpty_ll(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    return true;
}

// 进栈
bool StackPush_ll(stack_ll *list, long long data)
{
    if (StackIsFull_ll(list))
    {
        return false;
    }
    ++list->top;
    list->datas[list->top] = data;
    list->count++;
    return true;
}

// 出栈
bool StackPop_ll(stack_ll *list, long long *data)
{
    if (StackIsEmpty_ll(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    --list->top;
    --list->count;
    return true;
}

// 清空栈
bool ClearStack_ll(stack_ll *list)
{
    if (StackIsEmpty_ll(list))
    {
        return true;
    }
    list->top = -1;
    list->count = 0;
    return true;
}