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

// ˼·1��ֱ�ӷ�
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
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */

// ˼·2������ָ��
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

// 21. �ϲ�������������

// ˼·1�������������ϲ����޽ڵ�ʱ��Ҫ�ж�

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
//                // ��ǰ���(�����β���ӵ�list1)
//                tail->next = list1;
//                // �����β���list1
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

// ˼·2�����������������ڵ㣬Ȼ��ѭ���������ж�

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
//            // ��ǰ���(�����β���ӵ�list1)
//            tail->next = list1;
//            // �����β���list1
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

// ˼·3�������ڱ�λ�����迼��β�壬��󿽱��ڱ�λ��next
// �ͷ��ڱ�λ�����ؽ��

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
//            // ��ǰ���(�����β���ӵ�list1)
//            tail->next = list1;
//            // �����β���list1
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

// CM11 ����ָ�

// ˼·��������������һ��ΪС��k��һ��>=k�������ڱ�λ
// Ȼ��Ԫ�ط����ڶ�Ӧ������
// ���������������ҽ������β����next�ʵ�����
// �ͷ��ڱ�λ��������ȷ���

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* lessTail, * lessHead, * greaterTail, * greaterHead;
        // �����ڱ�λ
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