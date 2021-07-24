#include "static_link.h"

// 初始化链表
bool InitList(StaticLink list)
{
    for (int i = 0; i < SIZE - 2; i++)
    {
        list[i].next = i + 1;
    }
    list[SIZE - 2].next = NULL; // 设置可用地址的最大边界(可用地址有限)
    list[LINKHEAD].next = NULL;
    return true;
}

// 获取链表长度
int Len(StaticLink list)
{
    int count = 0;
    int head = list[LINKHEAD].next;
    while (head != NULL)
    {
        head = list[head].next;
        count++;
    }
    return count;
}

// 在链表末尾添加元素
bool Append(StaticLink list, Item data)
{
    int site;
    if (site = Malloc_List(list))
    {
        return false;
    }
    list[site].item = data;
    list[site].next = NULL;

    int head = LINKHEAD;
    while (list[head].next != NULL)
    {
        head = list[head].next;
    }
    list[head].next = site;
    return true;
}

// 在指定位置添加元素
bool Insert(StaticLink list, Item data, int index)
{
    if (index == Len(list))
    {
        return Append(list, data);
    }

    else if (index > Len(list))
    {
        puts("list index out of range");
        return false;
    }

    int site;
    if (!(site = Malloc_List(list)))
    {
        return false;   
    }
    list[site].item = data;

    int head = LINKHEAD;
    for (int i = 0; i < index - 1; i++)
    {
        head = list[head].next;
    }
    list[site].next = list[head].next;
    list[head].next = site;
    return true;
}

// 删除指定位置的元素
bool Delete(StaticLink list, Item *target, int index)
{
    if (index > Len(list))
    {
        puts("list index out of range");
        return false;
    }
    
    int head = LINKHEAD;
    for (int i = 0; i < index - 1; i++)
    {
        head = list[head].next;
    }
    int temp = list[head].next;
    list[head].next = list[temp].next;
    Free_List(list, temp);
    return true;
}

// 分配地址
int Malloc_List(StaticLink list)
{
    int site = list[0].next;
    if (list[0].next)
    {
        list[0].next = list[site].next;
    }
    if (!site)
    {
        puts("do not have space");
    }
    return site;
}

// 释放地址
bool Free_List(StaticLink list, int site)
{
    list[site].next = list[0].next;
    list[0].next = site;
    return true;
}
