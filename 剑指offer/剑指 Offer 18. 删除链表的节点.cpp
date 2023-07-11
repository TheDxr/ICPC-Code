class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode * pre = nullptr;
        for(ListNode * node = head;node != nullptr;node = node->next) {
            if(node->val == val) {
                if(pre == nullptr) {
                    return node->next;
                }
                else {
                    pre->next = node->next;
                }
            }
            pre = node;
        }
        return head;
    }
};