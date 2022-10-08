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

//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        struct ListNode* lessTail, * lessHead, * greaterTail, * greaterHead;
//        // �����ڱ�λ
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

// OR36 ����Ļ��Ľṹ

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
//        // ͷ��
//        cur->next = newNode;
//        newNode = cur;
//
//        // cur����
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
//        // A��rHeadһ�㲻��ֱ��ʹ�ã�����һ��
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

// 160. �ཻ����

// ˼·1��������

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

// ˼·2����ֵ��

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
//    int gap = abs(lenA - lenB);// ���ֵ
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

// 141. ��������

// ˼·��˫ָ��

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

// 142. �������� II

// ˼·1����ʽ��

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
//        // ����
//        if (fast == slow)
//        {
//            struct ListNode* meetNode = slow;
//            // ��ʽ�Ƶ�
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

// ˼·2��ת��Ϊ�ཻ����

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
//        // ����
//        if (fast == slow)
//        {
//            tail = slow;
//            break;
//        }
//    }
//
//    // û������
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

// 138. ���ƴ����ָ�������

// ˼·��
// 1. ���ƽڵ㣬���뵽ԭ�ڵ����һ���ڵ�֮��
// 2. ����ԭ�ڵ�random�������ƽڵ��random
// 3. ���ƽڵ�����Ϊ������ԭ����ָ�

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

    // 1. ��ԭ�ڵ����븴�ƽڵ�
    while (cur)
    {
        // ���븴�ƽڵ�
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;

        // cur�������
        cur = copy->next;
    }

    // 2. ����ԭ�ڵ��random�������ƽڵ��random
    cur = head;

    while (cur)
    {
        // copy�ڵ���cur�ĺ���
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

    // 3. ���ƽڵ�����Ϊ������ԭ�ڵ�ָ�

    struct Node* copyHead = NULL, * copyTail = NULL;
    cur = head;

    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;// ��¼ԭ�������һ���ڵ�

        // ���ƽڵ�����Ϊ������(����Ϊβ��)
        if (copyTail == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copy;
        }

        cur->next = next;// �ָ�����
        cur = next;
    }

    return copyHead;
}