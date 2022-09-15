#include "链表模板.hpp"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *pNode = head;
        ListNode *pNodeHead = new ListNode(-1);
        pNodeHead->next = head;
        ListNode *pNodePre = pNodeHead;

        for (int i = 1; i < m; i++)
        {
            pNodePre = pNode;
            pNode = pNode->next;
        }

        for (int i = m;i < n;i++)
        {            
            ListNode *pTemp = pNode->next;            
            pNode->next = pNode->next->next;
            pTemp->next = pNodePre->next;
            pNodePre->next = pTemp;
        }
        return pNodeHead->next;
    }
};