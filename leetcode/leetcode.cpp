// leetcode.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

//求最长非重复子串
int lengthOfLongestSubstring(char* s)
{
	int maxLengh = 0;
	//int begin = 0;
	int n = strlen(s);
	int * next = (int*)malloc(sizeof(int)*n); //next[i]记录了下一个与str[i]重复的字符的位置
	int * first = (int*)malloc(sizeof(int)*(n + 1)); //first[i]记录str[i]后面最近的一个重复点
	int hash[256];
	memset(hash, 'n', sizeof(hash));		//memset一般只用于赋值成0或-1，这里使用是有问题的，但是并不影响结果

	first[n] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		next[i] = hash[s[i]];
		hash[s[i]] = i;
		if (next[i] < first[i + 1])
			first[i] = next[i];
		else
			first[i] = first[i + 1]; //生成first[]表，复杂度是O(N)的
		//printf("%d\t%d\n", i, first[i]);
		//printf("%d\t%d\n", i, next[i]);
	}
	for (int i = 0; i<n; i++)
	{
		if (first[i] - i > maxLengh)
		{
			maxLengh = first[i] - i;
			//begin = i;
		}
	}
	free(first);
	free(next);
	//printf("%.*s\n", maxLengh, &s[begin]);
	return maxLengh;
}

int main(void)
{
	char targetString[8] = { "abcabcd" };
	printf("%d\n", lengthOfLongestSubstring(targetString));
}

