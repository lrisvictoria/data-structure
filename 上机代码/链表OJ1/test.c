#define _CRT_SECURE_NO_WARNINGS 1 

// β�巨

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* cur, * dummy, * tail;
//    cur = head;
//    dummy = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            tail->next = cur;
//            tail = tail->next;
//            cur = cur->next;
//        }
//        else
//        {
//            cur = cur->next;
//        }
//    }
//    tail->next = NULL;
//    struct ListNode* ans = dummy->next;
//    free(dummy);
//    return ans;
//}

// ����ɾ��

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* prev, * cur;
//    prev = NULL;
//    cur = head;
//    while (cur)
//    {
//        // ɾ�����
//        if (cur->val == val)
//        {
//            // ˵��Ϊͷɾ���
//            if (cur == head)
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//            }
//            else
//            {
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}

// �����ڱ�λ

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//
//    struct ListNode* newhead, * tail;
//    newhead = tail = NULL;
//    while (list1 != NULL && list2 != NULL)
//    {
//        // �� list1 β��
//        if (list1->val < list2->val)
//        {
//            // �ж��Ƿ�Ϊ��һ�β���
//            if (newhead == NULL)
//            {
//                newhead = tail = list1;
//            }
//            else
//            {
//                tail->next = list1;
//                tail = tail->next;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (newhead == NULL)
//            {
//                newhead = tail = list2;
//            }
//            else
//            {
//                tail->next = list2;
//                tail = tail->next;
//            }
//            list2 = list2->next;
//        }
//    }
//    // list1 δ������
//    if (list1)
//        tail->next = list1;
//    if (list2)
//        tail->next = list2;
//    return newhead;
//}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* newhead, * tail;
    newhead = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    // һ��Ҫ��������Ļ�����������Ϊ�գ��������Ӳ��ϣ�����
    newhead->next = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        // �� list1 β��
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    // list1 δ������
    if (list1)
        tail->next = list1;
    if (list2)
        tail->next = list2;
    struct ListNode* ans = newhead->next;
    free(newhead);
    return ans;
}