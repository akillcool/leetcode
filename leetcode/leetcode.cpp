// leetcode.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

//������ظ��Ӵ�
int lengthOfLongestSubstring(char* s)
{
	int maxLengh = 0;
	//int begin = 0;
	int n = strlen(s);
	int * next = (int*)malloc(sizeof(int)*n); //next[i]��¼����һ����str[i]�ظ����ַ���λ��
	int * first = (int*)malloc(sizeof(int)*(n + 1)); //first[i]��¼str[i]���������һ���ظ���
	int hash[256];
	memset(hash, 'n', sizeof(hash));		//memsetһ��ֻ���ڸ�ֵ��0��-1������ʹ����������ģ����ǲ���Ӱ����

	first[n] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		next[i] = hash[s[i]];
		hash[s[i]] = i;
		if (next[i] < first[i + 1])
			first[i] = next[i];
		else
			first[i] = first[i + 1]; //����first[]�����Ӷ���O(N)��
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

