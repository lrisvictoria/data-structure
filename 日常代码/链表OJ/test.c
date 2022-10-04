#define _CRT_SECURE_NO_WARNINGS 1 

/*
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��

ʾ�� 1��


���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]
ʾ�� 2��

���룺head = [], val = 1
�����[]
ʾ�� 3��

���룺head = [7,7,7,7], val = 7
�����[]

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
//            // ͷɾ
//            if (cur == head)
//            {
//                head = cur->next;
//                cur = head;
//            }
//            // �����ڵ�ɾ��
//            else
//            {
//                prep->next = cur->next;
//                free(cur);
//                cur = prep->next;
//            }
//        }
//        // ����������
//        else
//        {
//            prep = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}

// 206. ��ת����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ˼·1������
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

// ˼·2��ͷ�巨
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newnode = NULL;
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;// ��¼next
//        // ͷ��
//        cur->next = newnode;
//        newnode = cur;
//        // ����������
//        cur = next;
//    }
//    return newnode;
//}

// 876. ������м���
// ˼·1��ֱ�ӷ�
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ���������
// ����һ������
// ���ص�ǰ�ڵ�

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

// ˼·2������ָ��
// ��ָ����һ������ָ����������������ż�����ƽ�����������󷵻���ָ��ڵ�

//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head, * slow = head;
//
//    while (fast && fast->next)// �ջ�����һ���ڵ�Ϊ��
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}

// �����е�����k�����

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