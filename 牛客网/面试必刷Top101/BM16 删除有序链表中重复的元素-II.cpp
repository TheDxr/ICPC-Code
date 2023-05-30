class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *pNodePre = new ListNode(-1);
        pNodePre->next = head;
        ListNode *pNode = head;
        ListNode *pNodeHead = pNodePre;
        while(pNode != nullptr)
        {
            if(pNode->next != nullptr && pNode->val == pNode->next->val)
            {
                int val = pNode->val;
                while(pNode != nullptr && pNode->val == val)
                {
                    pNode = pNode->next;
                }
                pNodePre->next = pNode;
                pNode = pNodePre;
            }
            pNodePre = pNode;
            if(pNode == nullptr && pNode->next == nullptr)break;
            pNode = pNode->next;
        }
        return pNodeHead->next;
    }
};