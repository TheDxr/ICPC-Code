/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        ans.reserve(10000);
        for(auto node = head;node != nullptr;node = node->next) {
            ans.push_back(node->val);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};