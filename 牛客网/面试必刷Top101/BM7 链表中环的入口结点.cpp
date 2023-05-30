class Solution
{
  public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *p1 = pHead;
        ListNode *p2 = pHead->next;
        while (p1 != p2)
        {
            if(p1 == nullptr || p2 == nullptr || p2->next == nullptr){
                return nullptr;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p2 = new ListNode(-1);
        p2->next = pHead;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
           
        }
        return p1;
    }
};