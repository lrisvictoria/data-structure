#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>


typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

#include "Queue.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

// ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// �����������С
int size = 0;

int TreeSize1(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size++;
	TreeSize1(root->left);
	TreeSize1(root->right);

	return size;
}

int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// �������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	// ������ǿգ��������
	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	// ���зǿ�����б���
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);

		// �ǿ������
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");
	QueueDestroy(&q);
}

int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	if (k > 1)
	{
		return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
	}
}

BTNode* TreeFind(BTNode* root, int x)
{
	// ��� root Ϊ�գ��򷵻ؿ�
	if (root == NULL)
	{
		return NULL;
	}

	// �ҵ���
	if (root->data == x)
	{
		return root;
	}

	// ����ݹ���������
	BTNode* ret1 = TreeFind(root->left, x);
	// ����������ǿգ����ҵ��ˣ�����
	if (ret1 != NULL)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2 != NULL)
		return ret2;

	// ������û�ҵ����͵÷���NULL
	return NULL;
}

// �ж϶������Ƿ�����ȫ������
bool TreeComplete(BTNode* root)
{
	// ʹ�ò������˼��
	Queue q;
	QueueInit(&q);

	// ����ǿգ��������
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		
		// һ�������е��գ��ͳ�ȥ�ж�
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
		else
		{
			QueuePop(&q);
		}
	}
	QueueDestroy(&q);
	return true;
}

// ����
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

void TestBTree1()
{
	// ����������
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;

	PreOrder(n1);
	printf("\n");

	InOrder(n1);
	printf("\n");

	PostOrder(n1);
	printf("\n");
}


void TestBTree2()
{
	// ����������
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n2->right = n7;

	/*size = 0;
	printf("%d\n", TreeSize1(n1));
	size = 0;
	printf("%d\n", TreeSize1(n1));
	size = 0;
	printf("%d\n", TreeSize1(n1));

	printf("%d\n", TreeSize2(n1));

	printf("%d\n", TreeLeafSize(n1));

	printf("%d\n", TreeHeight(n1));

	printf("%d\n", TreeKLevelSize(n1, 3));*/

	printf("%d\n", TreeComplete(n1));

	LevelOrder(n1);

	TreeDestroy(n1);
	n1 = NULL;
}

int main()
{
	//TestBTree1();
	TestBTree2();

	return 0;
}