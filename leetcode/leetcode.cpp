// leetcode.cpp

#include "stdafx.h"
#include <string.h>

//求最长非重复子串
int lengthOfLongestSubstring(char* s)
{
	if (strlen(s) == 0)
		return 0;

	int maxLengh = 1;
	int totalLength = strlen(s);
	for (int i = 0; i < totalLength; ++i)
	{
		for (int j = i + 1; j < totalLength; ++j)
		{
			int flag = 0;
			for (int m = i; m <= j; ++m)
			{
				for (int n = m + 1; n <= j; ++n)
				{
					if (s[n] == s[m])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag == 0 && j - i + 1 > maxLengh)
			{
				maxLengh = j - i + 1;
			}
		}
	}
	return maxLengh;
}

int main(void)
{
	char targetString[8] = { "bbbbbbb" };
	printf("%d\n", lengthOfLongestSubstring(targetString));
}

