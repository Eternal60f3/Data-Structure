#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_c.h"
#include "stack_c.c"
#include "stack_ll.h"
#include "stack_ll.c"
#define SLEN 201
#define LENNUM 19
#define OPERATOR "+-*/() "

void Get_expression(char *expression, int size);
bool s_gets(char *text, int size);
bool expression_isInvalid(const char *expression);
long long Calculate(const char *expression);
void infix_suffix(const char *infix, char *suffix);
bool compare_operator(char x, char y);
int array_find(const char **, int, char);

void main(void)
{
    puts("Welcome to the use of science calculator");
    while (true)
    {
        char expression[SLEN];
        long long result = 0;

        puts("Please enter your arithmetic expression(enter q to quit)");

        Get_expression(expression, SLEN);
        if (expression[0] == 'q')
        {
            break;
        }

        result = Calculate(expression);
        printf("result: %lld\n", result);
    }
    puts("Thank you for using it");
    puts("done");
}

// 获取中缀表达式
void Get_expression(char *expression, int size)
{
    while (true)
    {
        if (!(s_gets(expression, size)))
        {
            break;
        }
        if (expression[0] == 'q')
        {
            break;
        }
        if (!(expression_isInvalid(expression)))
        {
            break;
        }
        puts("The expression is invalid. Please re-enter it");
    }
}

bool s_gets(char *expression, int size)
{
    fgets(expression, size, stdin);
    bool not_outofslen = true;
    char *empty = strchr(expression, '\n');
    if (empty)
    {
        *empty = '\0';
    }
    else
    {
        while (getchar() != '\n')
        {
            not_outofslen = false;
            continue;
        }
    }
    return not_outofslen;
}

bool expression_isInvalid(const char *expression)
{
    typedef char Item;
    stack_c bracket;
    InitStack_c(&bracket);
    while (*expression != '\0')
    {
        if (!(isdigit(*expression)) && !(strchr(OPERATOR, *expression)))
        {
            return true;
        }
        else if (*expression == '(')
        {
            StackPush_c(&bracket, *expression);
        }
        else if (*expression == ')')
        {
            Item temp;
            StackPop_c(&bracket, &temp);
        }
        expression++;
    }
    return !(StackIsEmpty_c(&bracket));
}

// 计算表达式的结果
long long Calculate(const char *expression)
{
    char suffix[SLEN];
    infix_suffix(expression, suffix);
    char *suffix_index = suffix;

    typedef long long Item;
    Item result = 0;

    stack_ll nums;
    InitStack_ll(&nums);

    char str_num[LENNUM];
    char *str_index = str_num;

    while (*suffix_index != '\0')
    {
        if (isdigit(*suffix_index))
        {
            *str_index = *suffix_index;
            ++str_index;
        }
        else if (*suffix_index == ' ')
        {
            if (str_index != str_num)
            {
                *str_index = '\0';
                Item num = atoll(str_num);
                str_index = str_num;
                StackPush_ll(&nums, num);
            }
        }
        else if (strchr(OPERATOR, *suffix_index))
        {
            Item top, under, in_result;
            StackPop_ll(&nums, &top);
            StackPop_ll(&nums, &under);
            switch (*suffix_index)
            {
            case '+':
                in_result = under + top;
                break;
            case '-':
                in_result = under - top;
                break;
            case '*':
                in_result = under * top;
                break;
            case '/':
                in_result = under / top;
                break;
            }
            StackPush_ll(&nums, in_result);
        }
        suffix_index++;
    }
    StackPop_ll(&nums, &result);
    return result;
}

void infix_suffix(const char *infix, char *suffix)
{
    typedef char Item;
    stack_c operator;
    InitStack_c(&operator);

    while (*infix != '\0')
    {
        if (isdigit(*infix))
        {
            *suffix = *infix;
            suffix++;
        }
        else if (*infix == ' ')
        {
        }
        else if (*infix == '(')
        {
            StackPush_c(&operator, * infix);
        }
        else if (*infix == ')')
        {
            *suffix = ' ';
            ++suffix;

            Item temp;
            while (StackPop_c(&operator, & temp) && temp != '(')
            {
                *suffix = temp;
                ++suffix;
            }
        }
        else if (strchr(OPERATOR, *infix))
        {
            *suffix = ' ';
            ++suffix;
            Item top;
            if (!(StackGetTop_c(&operator, & top)) || compare_operator(*infix, top))
            {
                StackPush_c(&operator, * infix);
            }
            else
            {
                while (StackGetTop_c(&operator, & top) && !(compare_operator(*infix, top)))
                {
                    if (top != '(')
                    {
                        *suffix = top;
                        ++suffix;
                        Item temp;
                        StackPop_c(&operator, & temp);
                    }
                }
                StackPush_c(&operator, * infix);
            }
        }
        if (*(infix + 1) == '\0')
        {
            *suffix = ' ';
            ++suffix;
            while (StackPop_c(&operator, suffix++))
            {
                continue;
            }
        }
        infix++;
    }
}

bool compare_operator(char x, char y)
{
    const char *priority[3] = {"()", "-+", "*/"};
    return array_find(priority, 3, x) > array_find(priority, 3, y);
}

int array_find(const char **text, int size, char x)
{
    for (int i = 0; i < size; i++)
    {
        for (int o = 0; o < strlen(text[i]); o++)
        {
            if (text[i][o] == x)
            {
                return i;
            }
        }
    }
}