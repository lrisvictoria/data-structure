#define _CRT_SECURE_NO_WARNINGS 1 

// 965. 单值二叉树

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

// 100. 相同的树

//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//
//    // 不可能全为空，那么只要有一个为空，则为假
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//
//    // 到这里，两个不可能同时为空并且两个都不为空
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    // 分别递归左右子树
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

// 572. 另一棵树的子树

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
//    // 子树不为空，如果树为空，则为假
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    // 如果找到了子树，则直接返回
//    if (isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    // 分别递归左右子树，子树只要找到了，则存在
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}

// KY11 二叉树遍历

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
    // 如果 str 为 # 说明无序构建，直接返回空
    if (str[*i] == '#')
    {
        (*i)++;
        return NULL;
    }

    // 否则创建节点，构建树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = str[(*i)++];
    // 递归处理左右子树
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
    // 创建一个字符数组
    char str[101];
    scanf("%s", str);
    int i = 0;

    // 重构树，这里需要地址
    struct TreeNode* root = rebuildTree(str, &i);
    // 中序遍历
    InOrder(root);

    return 0;
}