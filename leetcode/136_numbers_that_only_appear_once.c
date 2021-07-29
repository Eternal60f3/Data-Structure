#include <stdio.h>

int singleNumber(int *nums, int numsSize);
void main(void)
{
    int num[10] = {1, 2, 2, 3, 3};
    int singlenum = singleNumber(num, 10);
    printf("%d", singlenum);
}

int singleNumber(int *nums, int numsSize)
{
    int temp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        temp ^= nums[i];
    }
    return temp;
}