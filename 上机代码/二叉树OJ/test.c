#define _CRT_SECURE_NO_WARNINGS 1 

// 965. ��ֵ������

//bool isUnivalTree(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    if (root->left && root->left->val != root->val)
//    {
//        return false;
//    }
//
//    if (root->right && root->right->val != root->val)
//    {
//        return false;
//    }
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}

// 100. ��ͬ����

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//
//    // ������ȫΪ�գ���ôֻҪ��һ��Ϊ�գ���Ϊ��
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//
//    // ���������������ͬʱΪ�ղ�����������Ϊ��
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    // �ֱ�ݹ���������
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

// 572. ��һ����������

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    // ������Ϊ�գ������Ϊ�գ���Ϊ��
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    // ����ҵ�����������ֱ�ӷ���
//    if (isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    // �ֱ�ݹ���������������ֻҪ�ҵ��ˣ������
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}

// KY11 ����������

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* rebuildTree(char* str, int* i)
{
    // ��� str Ϊ # ˵�����򹹽���ֱ�ӷ��ؿ�
    if (str[*i] == '#')
    {
        (*i)++;
        return NULL;
    }

    // ���򴴽��ڵ㣬������
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = str[(*i)++];
    // �ݹ鴦����������
    root->left = rebuildTree(str, i);
    root->right = rebuildTree(str, i);

    return root;
}

void InOrder(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
int main()
{
    // ����һ���ַ�����
    char str[101];
    scanf("%s", str);
    int i = 0;

    // �ع�����������Ҫ��ַ
    struct TreeNode* root = rebuildTree(str, &i);
    // �������
    InOrder(root);

    return 0;
}