#include "stack_c.h"

// 初始�?
void InitStack_c(stack_c *list)
{
    list->top = -1;
    list->count = 0;
}

// 判断栈是否为�?
bool StackIsEmpty_c(const stack_c *list)
{
    return list->count == 0;
}

// 判断栈是否已�?
bool StackIsFull_c(const stack_c *list)
{
    return list->count == SIZE;
}

// 获取栈中的项�?
int LenStack_c(const stack_c *list)
{
    return list->count;
}

// 读取栈顶�?
bool StackGetTop_c(const stack_c *list, char *data)
{
    if (StackIsEmpty_c(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    return true;
}

// 进栈
bool StackPush_c(stack_c *list, char data)
{
    if (StackIsFull_c(list))
    {
        return false;
    }
    ++list->top;
    list->datas[list->top] = data;
    list->count++;
    return true;
}

// 出栈
bool StackPop_c(stack_c *list, char *data)
{
    if (StackIsEmpty_c(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    --list->top;
    --list->count;
    return true;
}

// 清空�?
bool ClearStack_c(stack_c *list)
{
    if (StackIsEmpty_c(list))
    {
        return true;
    }
    list->top = -1;
    list->count = 0;
    return true;
}
