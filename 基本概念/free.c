#include <stdio.h>
void printn(int);
void main()
{
    int num;
    scanf("%d", &num);
    printn(num);
}
void printn(int num)
{
    for (int i; i <= num;i++)
    {
        printf("%d\n",i);
    }
}
