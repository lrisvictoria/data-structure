#define _CRT_SECURE_NO_WARNINGS 1 

// CM11 ����ָ�
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

// OR36 ����Ļ��Ľṹ

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

// 160. �ཻ����

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
 //    // ���� lenA �� lenB ��ʵ��ϵ����
 //    // ��Ҫ�������ǵĲ�ֵ�����Լ�ʹ lenA �� lenB��ʼ��Ϊ 0 Ҳ���ܹ�
 //    // ���������Ǳ�����β������ lenA �� B ��ʼ��Ϊ1��������������ȵ�
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
 //    // ������Ҫע��һ�£�������Ŀ���ʽ���������һ��
 //    // ���������ֵ��ͬʱ�����ܻ�ѡȡͬһ������
 //    // ���½�������Ѳȿ�
 //    struct ListNode* shortList = lenA > lenB ? headB : headA;
 //
 //    int gap = abs(lenA - lenB);// ���ֵ
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

 // 141. ��������

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

 // 142. �������� II

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