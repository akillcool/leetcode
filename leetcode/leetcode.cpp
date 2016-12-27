// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

//1. Two Sum
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target)
{
	int* indices = (int*)malloc(2 * sizeof(int));

	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < numsSize&&j != i; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				if (i < j)
				{
					indices[0] = i;
					indices[1] = j;
				}
				else
				{
					indices[0] = j;
					indices[1] = i;
				}
				return indices;
			}
		}
	}
	return indices;
}


int main()
{
	int nums[3] = { 3,2,4 };
	int* indices = twoSum(nums, 3, 6);
	for (int i = 0; i < 2; i++)
	{
		printf("%d\t", indices[i]);
	}
	return 0;
}

