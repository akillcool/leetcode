// leetcode.cpp

#include "stdafx.h"
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode *p = l1, *q = l2;
	struct ListNode *ans = NULL;

	struct ListNode *pNext = NULL;
	int up = 0;		//处理进位

	//建立首节点
	struct ListNode *pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	ans = pNode;
	pNode->val = (p->val + q->val) % 10;
	up = (p->val + q->val) / 10;
	p = p->next;
	q = q->next;

	while (p != NULL && q != NULL)
	{
		pNext = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNext->val = (p->val + q->val + up) % 10;
		up = (p->val + q->val + up) / 10;

		pNode->next = pNext;
		pNode = pNext;
		p = p->next;
		q = q->next;
	}

	//若l1，l2还有剩余节点
	while (p != NULL)
	{
		pNext = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNext->val = (p->val + up) % 10;
		up = (p->val + up) / 10;

		pNode->next = pNext;
		pNode = pNext;
		p = p->next;
	}
	while (q != NULL)
	{
		pNext = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNext->val = (q->val + up) % 10;
		up = (q->val + up) / 10;

		pNode->next = pNext;
		pNode = pNext;
		q = q->next;
	}

	if (up)		//如果有进位，添加节点
	{
		pNext = (struct ListNode*)malloc(sizeof(struct ListNode));
		pNext->val = up;
		pNode->next = pNext;
		pNode = pNext;
	}

	pNode->next = NULL;		//尾节点指针置空

	return ans;
}

int main()
{
	struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
	struct ListNode *p1 = l1;
	p1->val = 8;
	p1->next = p1 + 1;
	p1++;

	p1->val = 9;
	p1->next = p1 + 1;
	p1++;

	p1->val = 9;
	p1->next = NULL;

	struct ListNode *l2 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
	struct ListNode *p2 = l2;
	p2->val = 2;
	p2->next = NULL;

	/*p2->next = p2 + 1;
	p2++;

	p2->val = 6;
	p2->next = p2 + 1;
	p2++;

	p2->val = 4;
	p2->next = NULL;*/

	struct ListNode *p = addTwoNumbers(l1, l2);

	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");

	return 0;
}

