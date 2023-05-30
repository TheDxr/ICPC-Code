class Solution 
{
public:
     ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *pHeadNew = new ListNode(-1);
        ListNode *pNode = pHeadNew;

        while (pHead1 != nullptr || pHead2 != nullptr)
        {
            if (pHead1 == nullptr && pHead2 != nullptr)
            {
                pNode->next = pHead2;
                break;
            }
            if (pHead1 != nullptr && pHead2 == nullptr)
            {
                pNode->next = pHead1;
                break;
            }
            if (pHead1->val < pHead2->val)
            {
                ListNode *pTemp = pHead1;
                pNode->next = pHead1;
                pHead1 = pHead1->next;
                pTemp->next = nullptr;
                pNode = pTemp;
            }
            else
            {
                ListNode *pTemp = pHead2;
                pNode->next = pHead2;
                pHead2 = pHead2->next;
                pTemp->next = nullptr;
                pNode = pTemp;
            }
        }
        return pHeadNew->next;
    }
};