#include <stdbool.h>
#include <stdio.h>
#define SIZE 1000
#define LINKHEAD SIZE - 1 // 静态链表的头部

typedef int Item;

typedef struct Node
{
    Item item;
    int next;
} Element, StaticLink[SIZE];


/*
操作:
    初始化静态链表
细节:
    设置一个数组将数组中的每一个元素的next指向其所在位置的后一个下标
*/
bool InitList(StaticLink list);

/* 
操作:
    获取链表长度
*/
int Len(StaticLink list);

/*
操作:
    在链表末尾添加元素
*/
bool Append(StaticLink list, Item data);

/*
操作:
    在指定位置添加元素
*/
bool Insert(StaticLink list, Item data, int index);

/*
操作:
    删除指定位置的元素
*/
bool Delete(StaticLink list, Item *target, int index);

/*
操作:
    分配地址
*/
int Malloc_List(StaticLink list);

/*
操作:
    释放地址
*/
bool Free_List(StaticLink list, int);