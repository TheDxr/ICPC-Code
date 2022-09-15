#include "链表模板.hpp"

class Solution
{
  public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *pNewHead = new ListNode(-1);
        pNewHead->next = head;
        ListNode *pNodePre = pNewHead;
        ListNode *pNode = head;
        int listLen = 0;
        while(pNode != nullptr)
        {
            pNode = pNode->next;
            listLen++;
        }
        pNode = head;

        for(int j = 0;j < listLen/k; j++)
        {
            for (int i = 1; i < k; i++)
            {
                ListNode *pNodeNext = pNode->next;
                pNode->next = pNodeNext->next;
                pNodeNext->next = pNodePre->next;
                pNodePre->next = pNodeNext;
            }
            pNodePre = pNode;
            pNode = pNode->next;
        }
        return pNewHead->next;
    }
    
};