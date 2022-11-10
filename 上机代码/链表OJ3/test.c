#define _CRT_SECURE_NO_WARNINGS 1 

// 141. 环形链表

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

// 投机取巧

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


// 142. 环形链表 II
// 相交链表做法

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
//    // 没有相遇
//    if (meet == NULL)
//    {
//        return NULL;
//    }
//    // 拷贝 meet 的下一个节点，meet 链空
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

// 公式法
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

// 138. 复制带随机指针的链表

// 找相对位置，暴力做法，O(N^2)

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
//    // 不带 random 的节点拷贝
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
//        // 如果原链表的 random 对应的是空指针，那么之间链空
//        if (cur->random == NULL)
//        {
//            copyCur->random = NULL;
//        }
//        else
//        {
//            // 每次从开头开始遍历，找相对位置
//            int index = 0;
//            struct Node* srcTmp = head;
//            struct Node* copyTmp = copyHead;
//            // 让 srcTmp 查找原链表，直到找到 cur 的 random 在原链表中的相对位置
//            while (srcTmp)
//            {
//                if (srcTmp == cur->random)
//                {
//                    break;
//                }
//                ++index;
//                srcTmp = srcTmp->next;
//            }
//            // 此时遍历 copyHead 直到相对位置
//            while (index--)
//            {
//                copyTmp = copyTmp->next;
//            }
//            // 此时 copyTmp 就是 random 的位置
//            copyCur->random = copyTmp;
//        }
//        cur = cur->next;
//        copyCur = copyCur->next;
//    }
//    return copyHead;
//}

// 巧妙做法

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
    // 1. 在每个节点后创建复制节点
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    // 2. 通过关系链接复制节点中的random
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
    // 3. 链接复制节点，恢复链接
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