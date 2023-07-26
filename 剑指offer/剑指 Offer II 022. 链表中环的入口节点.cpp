// 方法一：哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        for(auto node = head;node != nullptr;node = node->next) {
            if(nodes.count(node) != 0)return node;
            nodes.insert(node);
        }
        return nullptr;      
    }
};
// 方法二：双指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(true) {
            if(fast == nullptr || fast->next == nullptr)return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }

};