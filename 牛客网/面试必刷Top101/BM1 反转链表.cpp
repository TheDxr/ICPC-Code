#include "链表模板.hpp"

class Solution
{
  public:
    //头插法
    ListNode *ReverseList1(ListNode *pHead)
    {
        ListNode *pNode = pHead;
        ListNode *pHeadTemp = new ListNode(-1);
        ListNode *pTemp;
        while (pNode != nullptr)
        {
            pTemp = pHeadTemp->next;
            pHeadTemp->next = pNode;
            pNode = pNode->next;
            pHeadTemp->next->next = pTemp;
        }
        return pHeadTemp->next;
    }
    //前后指针法

    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *pNode = pHead;
        ListNode *pNodePre = nullptr;
        ListNode *pTemp = nullptr;
        while (pNode != nullptr)
        {
            pTemp = pNode->next;
            pNode->next = pNodePre;

            pNodePre = pNode;
            pNode = pTemp;
        }
        return pNodePre;
    }
    //双指针法二
    ListNode *ReverseList2(ListNode *pHead)
    {
        ListNode *pNode = pHead;
        ListNode *pNodePre = new ListNode(-1);
        pNodePre->next = pHead;

        while (pNode->next != nullptr)
        {
            ListNode *pNext = pNode->next;
            pNode->next = pNext->next;
            pNext->next = pNodePre->next;
            pNodePre->next = pNext;
        }
        return pNodePre->next;
    }
};