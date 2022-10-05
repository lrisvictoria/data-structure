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

// 思路1：直接法
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    struct ListNode* cur, * ans;
//    cur = ans = pListHead;
//    int len = 0;
//
//    while (cur)
//    {
//        cur = cur->next;
//        len++;
//    }
//    if (k <= 0 || k > len)
//        return NULL;
//
//    for (int i = 0; i < len - k; i++)
//    {
//        ans = ans->next;
//    }
//    return ans;
//}

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */

// 思路2：快慢指针
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//
//    while (k--)
//    {
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

// 21. 合并两个有序链表

// 思路1：创建新链表，合并，无节点时需要判断

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* head = NULL, * tail = NULL;
//
//    if (list1 == NULL && list2)
//    {
//        return list2;
//    }
//
//    if (list2 == NULL && list1)
//    {
//        return list1;
//    }
//
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            if (head == NULL)
//            {
//                head = tail = list1;
//            }
//            else
//            {
//                // 当前结点(链表的尾链接到list1)
//                tail->next = list1;
//                // 链表的尾变成list1
//                tail = list1;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (head == NULL)
//            {
//                head = tail = list2;
//            }
//            else
//            {
//                tail->next = list2;
//                tail = list2;
//            }
//            list2 = list2->next;
//        }
//    }
//
//    if (list1)
//    {
//        tail->next = list1;
//    }
//    if (list2)
//    {
//        tail->next = list2;
//    }
//    return head;
//}

// 思路2：创建新链表，给定节点，然后循环中无需判断

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* head = NULL, * tail = NULL;
//
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//
//    if (list1->val < list2->val)
//    {
//        head = tail = list1;
//        list1 = list1->next;
//    }
//    else
//    {
//        head = tail = list2;
//        list2 = list2->next;
//    }
//
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            // 当前结点(链表的尾链接到list1)
//            tail->next = list1;
//            // 链表的尾变成list1
//            tail = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            tail->next = list2;
//            tail = list2;
//            list2 = list2->next;
//        }
//    }
//
//    if (list1)
//    {
//        tail->next = list1;
//    }
//    if (list2)
//    {
//        tail->next = list2;
//    }
//    return head;
//}

// 思路3：给定哨兵位，无需考虑尾插，最后拷贝哨兵位的next
// 释放哨兵位，返回结点

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* head = NULL, * tail = NULL;
//
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//
//
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            // 当前结点(链表的尾链接到list1)
//            tail->next = list1;
//            // 链表的尾变成list1
//            tail = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            tail->next = list2;
//            tail = list2;
//            list2 = list2->next;
//        }
//    }
//
//    if (list1)
//    {
//        tail->next = list1;
//    }
//    if (list2)
//    {
//        tail->next = list2;
//    }
//
//    struct ListNode* ans = head->next;
//    free(head);
//
//    return ans;
//}

// CM11 链表分割

// 思路：创建两个链表，一个为小于k，一个>=k，建立哨兵位
// 然后将元素放置于对应链表中
// 链接两个链表，并且将链表的尾部的next适当处理
// 释放哨兵位，返回正确结点

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* lessTail, * lessHead, * greaterTail, * greaterHead;
        // 建立哨兵位
        lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* cur = pHead;

        while (cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = cur;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = cur;
            }
            cur = cur->next;
        }
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;

        struct ListNode* ans = lessHead->next;
        free(lessHead);
        free(greaterHead);
        return ans;

    }
};