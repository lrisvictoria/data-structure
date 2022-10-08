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

//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        struct ListNode* lessTail, * lessHead, * greaterTail, * greaterHead;
//        // 建立哨兵位
//        lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//        struct ListNode* cur = pHead;
//
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = cur;
//            }
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = cur;
//            }
//            cur = cur->next;
//        }
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//
//        struct ListNode* ans = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//        return ans;
//
//    }
//};

// OR36 链表的回文结构

//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newNode = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        // 头插
//        cur->next = newNode;
//        newNode = cur;
//
//        // cur迭代
//        cur = next;
//    }
//
//    return newNode;
//}
//
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A) {
//        struct ListNode* mid = middleNode(A);
//        struct ListNode* rHead = reverseList(mid);
//
//        // A和rHead一般不会直接使用，拷贝一份
//        struct ListNode* curA = A;
//        struct ListNode* curR = rHead;
//
//        while (curA && curR)
//        {
//            if (curA->val != curR->val)
//            {
//                return false;
//            }
//            curA = curA->next;
//            curR = curR->next;
//        }
//        return true;
//    }
//};

// 160. 相交链表

// 思路1：暴力法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* curA = headA;
//
//    while (curA)
//    {
//        struct ListNode* ccurA = curA;
//        struct ListNode* curB = headB;
//        while (curB)
//        {
//            if (ccurA == curB)
//            {
//                return ccurA;
//            }
//            else
//            {
//                curB = curB->next;
//            }
//        }
//        curA = curA->next;
//    }
//    return NULL;
//}

// 思路2：差值法

//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lenA = 0, lenB = 0;
//
//    while (tailA->next)
//    {
//        lenA++;
//        tailA = tailA->next;
//    }
//
//    while (tailB->next)
//    {
//        lenB++;
//        tailB = tailB->next;
//    }
//
//    if (tailA != tailB)
//    {
//        return NULL;
//    }
//
//    int gap = abs(lenA - lenB);// 求差值
//
//    struct ListNode* longList = lenA > lenB ? headA : headB;
//    struct ListNode* shortList = lenA > lenB ? headB : headA;
//
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    return longList;
//}

// 141. 环形链表

// 思路：双指针

//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//}

// 142. 环形链表 II

// 思路1：公式法

//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        // 相遇
//        if (fast == slow)
//        {
//            struct ListNode* meetNode = slow;
//            // 公式推导
//            while (meetNode != head)
//            {
//                head = head->next;
//                meetNode = meetNode->next;
//            }
//            return meetNode;
//        }
//    }
//    return NULL;
//}

// 思路2：转化为相交链表

//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    struct ListNode* tail = NULL;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        // 相遇
//        if (fast == slow)
//        {
//            tail = slow;
//            break;
//        }
//    }
//
//    // 没有相遇
//    if (tail == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* newHead = tail->next;
//    int lenH = 1, lenN = 1;
//
//    struct ListNode* curH = head, * curN = newHead;
//
//    while (curH != tail)
//    {
//        lenH++;
//        curH = curH->next;
//    }
//
//    while (curN != tail)
//    {
//        lenN++;
//        curN = curN->next;
//    }
//
//    struct ListNode* longList = lenH > lenN ? head : newHead;
//    struct ListNode* shortList = lenH > lenN ? newHead : head;
//
//    int gap = abs(lenH - lenN);
//
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    return longList;
//}

// 138. 复制带随机指针的链表

// 思路：
// 1. 复制节点，插入到原节点和下一个节点之间
// 2. 根据原节点random，处理复制节点的random
// 3. 复制节点链接为新链表，原链表恢复

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;

    // 1. 在原节点后插入复制节点
    while (cur)
    {
        // 插入复制节点
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;

        // cur往后迭代
        cur = copy->next;
    }

    // 2. 根据原节点的random，处理复制节点的random
    cur = head;

    while (cur)
    {
        // copy节点在cur的后面
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }

        cur = copy->next;
    }

    // 3. 复制节点链接为新链表，原节点恢复

    struct Node* copyHead = NULL, * copyTail = NULL;
    cur = head;

    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;// 记录原链表的下一个节点

        // 复制节点链接为新链表(本质为尾插)
        if (copyTail == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copy;
        }

        cur->next = next;// 恢复链接
        cur = next;
    }

    return copyHead;
}