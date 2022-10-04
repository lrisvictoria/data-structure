#define _CRT_SECURE_NO_WARNINGS 1 

/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：


输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//#include <stdio.h>
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* cur = head;
//    struct ListNode* prep = NULL;
//
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            // 头删
//            if (cur == head)
//            {
//                head = cur->next;
//                cur = head;
//            }
//            // 其他节点删除
//            else
//            {
//                prep->next = cur->next;
//                free(cur);
//                cur = prep->next;
//            }
//        }
//        // 迭代往后走
//        else
//        {
//            prep = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}

// 206. 反转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 思路1：迭代
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//        return NULL;
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//    return n1;
//}

// 思路2：头插法
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newnode = NULL;
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;// 记录next
//        // 头插
//        cur->next = newnode;
//        newnode = cur;
//        // 迭代往后走
//        cur = next;
//    }
//    return newnode;
//}

// 876. 链表的中间结点
// 思路1：直接法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 算出链表长度
// 遍历一半链表
// 返回当前节点

//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    int len = 0;
//    while (cur != NULL)
//    {
//        cur = cur->next;
//        len++;
//    }
//
//    struct ListNode* ans = head;
//    for (int i = 0; i < len / 2; i++)
//    {
//        ans = ans->next;
//    }
//    return ans;
//}

// 思路2：快慢指针
// 快指针走一步，满指针走两步，根据奇偶来控制结束条件，最后返回慢指针节点

//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head, * slow = head;
//
//    while (fast && fast->next)// 空或者下一个节点为空
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}

// 链表中倒数第k个结点

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    struct ListNode* cur, * ans;
    cur = ans = pListHead;
    int len = 0;

    while (cur)
    {
        cur = cur->next;
        len++;
    }
    if (k <= 0 || k > len)
        return NULL;

    for (int i = 0; i < len - k; i++)
    {
        ans = ans->next;
    }
    return ans;
}