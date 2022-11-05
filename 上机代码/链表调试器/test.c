#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* CreatreList(int* a, int n)
{
	struct ListNode* phead = NULL, *ptail = NULL;
	for (int i = 0; i < n; i++)
	{
		struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (newnode == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		newnode->next = NULL;
		newnode->val = a[i];
		if (phead == NULL)
		{
			phead = ptail = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = ptail->next;
		}
	}
	return phead;
}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	struct ListNode* plist = CreatreList(a, sizeof(a) / sizeof(a[0]));
	return 0;
}