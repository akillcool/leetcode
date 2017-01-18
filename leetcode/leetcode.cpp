// leetcode.cpp

#include "stdafx.h"
#include <string.h>

//������ظ��Ӵ�
int lengthOfLongestSubstring(char* s)
{
	int i, j;
	int maxLengh = 0;
	int hash[256];
	int n = strlen(s);
	for (i = 0; i<n; ++i)
	{
		memset(hash, 0, sizeof(hash));
		hash[s[i]] = 1;
		for (j = i + 1; j<n; ++j)
		{
			if (hash[s[j]] == 0)
				hash[s[j]] = 1;
			else
				break;
		}
		if (j - i > maxLengh)
		{
			maxLengh = j - i;
		}
	}
	return maxLengh;
}

int main(void)
{
	char targetString[8] = { "bbbbbbb" };
	printf("%d\n", lengthOfLongestSubstring(targetString));
}

