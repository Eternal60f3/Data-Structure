#include "stack.h"

// 初始化
void InitStack(stack *list)
{
    list->top = -1;
    list->count = 0;
}

// 判断栈是否为空
bool StackIsEmpty(const stack *list)
{
    return list->count == 0;
}

// 判断栈是否已满
bool StackIsFull(const stack *list)
{
    return list->count == SIZE;
}

// 获取栈中的项数
int LenStack(const stack *list)
{
    return list->count;
}

// 读取栈顶项
bool StackGetTop(const stack *list, Item *data)
{
    if (StackIsEmpty(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    return true;
}

// 进栈
bool StackPush(stack *list, Item data)
{
    if (StackIsFull(list))
    {
        return false;
    }
    ++list->top;
    list->datas[list->top] = data;
    list->count++;
    return true;
}

// 出栈
bool StackPop(stack *list, Item *data)
{
    if (StackIsEmpty(list))
    {
        return false;
    }
    *data = list->datas[list->top];
    --list->top;
    --list->count;
    return true;
}

// 清空栈
bool ClearStack(stack *list)
{
    if (StackIsEmpty(list))
    {
        return true;
    }
    list->top = -1;
    list->count = 0;
    return true;
}
