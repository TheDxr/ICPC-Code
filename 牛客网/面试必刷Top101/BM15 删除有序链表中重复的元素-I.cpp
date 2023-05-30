class Solution
{
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNodePre = new ListNode(-1);
        ListNode *pNode = head;
        pNodePre->next = head;
        while (pNode != nullptr)
        {   
            if(pNode->val == pNodePre->val)
            {
                pNodePre->next = pNode->next;
                pNode = pNodePre;
            }
            pNodePre = pNode;
            pNode = pNode->next;
        }
        return head;
    }
};