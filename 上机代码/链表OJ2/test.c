#define _CRT_SECURE_NO_WARNINGS 1 

// CM11 链表分割
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        struct ListNode* lessTail, * greaterTail, * lessHead, * greaterHead;
//        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//        struct ListNode* ans = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//        return ans;
//    }
//};

// OR36 链表的回文结构

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//class PalindromeList {
//public:
//    struct ListNode* findMid(struct ListNode* head)
//    {
//        struct ListNode* fast, * slow;
//        fast = slow = head;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//    struct ListNode* reverseList(struct ListNode* head)
//    {
//        struct ListNode* cur = head;
//        struct ListNode* newhead = NULL;
//        while (cur)
//        {
//            struct ListNode* next = cur->next;
//            cur->next = newhead;
//            newhead = cur;
//            cur = next;
//        }
//        return newhead;
//    }
//    bool chkPalindrome(ListNode* A)
//    {
//        struct ListNode* mid = findMid(A);
//        struct ListNode* rHead = reverseList(mid);
//        struct ListNode* curA = A, * curR = rHead;
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
 //{
 //    struct ListNode* tailA = headA;
 //    struct ListNode* tailB = headB;
 //    int lenA = 1, lenB = 1;
 //    // 这里 lenA 和 lenB 其实关系不大
 //    // 主要是算它们的差值，所以即使 lenA 和 lenB初始化为 0 也能跑过
 //    // 但是由于是遍历到尾，所以 lenA 和 B 初始化为1是真正算出链表长度的
 //    while (tailA->next)
 //    {
 //        ++lenA;
 //        tailA = tailA->next;
 //    }
 //    while (tailB->next)
 //    {
 //        tailB = tailB->next;
 //        ++lenB;
 //    }
 //    if (tailA != tailB)
 //    {
 //        return NULL;
 //    }
 //    struct ListNode* longList = lenA > lenB ? headA : headB;
 //    // 这里需要注意一下，两次三目表达式的条件最好一样
 //    // 否则链表的值相同时，可能会选取同一个链表
 //    // 导致结果错误，已踩坑
 //    struct ListNode* shortList = lenA > lenB ? headB : headA;
 //
 //    int gap = abs(lenA - lenB);// 求差值
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

 //bool hasCycle(struct ListNode* head)
 //{
 //    struct ListNode* cur = head;
 //    size_t count = 0;
 //    while (cur)
 //    {
 //        if (count > 10000)
 //            return true;
 //        cur = cur->next;
 //        ++count;
 //    }
 //    return false;
 //}

 // 142. 环形链表 II

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode* meet = fast;
            while (meet != head)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}