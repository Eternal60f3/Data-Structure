#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
    char str1[10];
    char *index = str1;
    *index = '1';
    *(index + 1) = '2';
    printf("%s\n", str1);
    printf("1:%c\n", *index++);
    printf("2:%c\n", *index);
    if ('\0')
    {
        printf("woiuiwe");
    }
}