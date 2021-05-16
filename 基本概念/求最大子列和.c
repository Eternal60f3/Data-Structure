#include <stdio.h>
int max_sum(int ,int * array);
void main(void)
{
    const int len;
    scanf("%d", &len);
    int array[len];
    for (int i = 0; i < len;i++)
    {
        scanf("%d", &array[i]);
    }
    printf("%d", max_sum(len, array));
}
int max_sum(int len, int * array)
{
    int this_sum = 0, max_sum = 0;
    for(int temp = 0; temp < len; temp++)
    {
        this_sum += array[temp];
        if (this_sum > max_sum)
        {
            max_sum = this_sum;
        }
        else if (this_sum < 0)
        {
            this_sum = 0;
        }
    }
    return max_sum;
}
