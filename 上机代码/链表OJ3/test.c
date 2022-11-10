#define _CRT_SECURE_NO_WARNINGS 1 

// 141. ��������

//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head, * slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//}

// Ͷ��ȡ��

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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
// �ཻ��������

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head, * slow = head;
//    struct ListNode* meet = NULL;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            meet = fast;
//            break;
//        }
//    }
//    // û������
//    if (meet == NULL)
//    {
//        return NULL;
//    }
//    // ���� meet ����һ���ڵ㣬meet ����
//    struct ListNode* newHead = meet->next;
//    meet->next = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* curN = newHead;
//    int len1 = 1, len2 = 1;
//    while (cur->next)
//    {
//        cur = cur->next;
//        ++len1;
//    }
//    while (curN->next)
//    {
//        curN = curN->next;
//        ++len2;
//    }
//    struct ListNode* longList = len1 > len2 ? head : newHead;
//    struct ListNode* shortList = len1 > len2 ? newHead : head;
//    int gap = abs(len1 - len2);
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//    while (longList != shortList)
//    {
//        shortList = shortList->next;
//        longList = longList->next;
//    }
//    return shortList;
//}

// ��ʽ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            struct ListNode* meet = fast;
//            while (meet != head)
//            {
//                head = head->next;
//                meet = meet->next;
//            }
//            return meet;
//        }
//    }
//    return NULL;
//}

// 138. ���ƴ����ָ�������

// �����λ�ã�����������O(N^2)

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

//struct Node* copyRandomList(struct Node* head)
//{
//    if (head == NULL)
//        return NULL;
//    struct Node* copyHead = NULL, * copyTail = NULL;
//    struct Node* cur = head;
//    // ���� random �Ľڵ㿽��
//    while (cur)
//    {
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        copy->next = NULL;
//        if (copyHead == NULL)
//        {
//            copyHead = copyTail = copy;
//        }
//        else
//        {
//            copyTail->next = copy;
//            copyTail = copyTail->next;
//        }
//        cur = cur->next;
//    }
//    cur = head;
//    struct Node* copyCur = copyHead;
//    while (cur)
//    {
//        // ���ԭ����� random ��Ӧ���ǿ�ָ�룬��ô֮������
//        if (cur->random == NULL)
//        {
//            copyCur->random = NULL;
//        }
//        else
//        {
//            // ÿ�δӿ�ͷ��ʼ�����������λ��
//            int index = 0;
//            struct Node* srcTmp = head;
//            struct Node* copyTmp = copyHead;
//            // �� srcTmp ����ԭ����ֱ���ҵ� cur �� random ��ԭ�����е����λ��
//            while (srcTmp)
//            {
//                if (srcTmp == cur->random)
//                {
//                    break;
//                }
//                ++index;
//                srcTmp = srcTmp->next;
//            }
//            // ��ʱ���� copyHead ֱ�����λ��
//            while (index--)
//            {
//                copyTmp = copyTmp->next;
//            }
//            // ��ʱ copyTmp ���� random ��λ��
//            copyCur->random = copyTmp;
//        }
//        cur = cur->next;
//        copyCur = copyCur->next;
//    }
//    return copyHead;
//}

// ��������

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
    // 1. ��ÿ���ڵ�󴴽����ƽڵ�
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    // 2. ͨ����ϵ���Ӹ��ƽڵ��е�random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = next;
    }
    // 3. ���Ӹ��ƽڵ㣬�ָ�����
    cur = head;
    struct Node* copyHead = NULL, * copyTail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copyHead == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copyTail->next;
        }
        cur->next = next;
        cur = next;
    }
    return copyHead;
}