class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        for(auto node = head;node != nullptr;node = node->next)
        {
            numCount[node->val]++;
        }
        ListNode *ans = new ListNode(-1);
        auto cur = ans;
        for(auto node = head;node != nullptr;node = node->next)
        {
            if(numCount[node->val] == 1)
            {
                cur->next = node;
                cur = cur->next;
            }
        }
        cur->next = nullptr;
        return ans->next;
    }
private:
    unordered_map<int, int> numCount;
};