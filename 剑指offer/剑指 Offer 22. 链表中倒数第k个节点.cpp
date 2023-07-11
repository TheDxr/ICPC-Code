
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int listLen = 0;
        auto next = head;
        while(next != nullptr) {
            next = next->next;
            listLen++;
        }
        int idx = 0;
        next = head;
        while(next != nullptr) {
            if(idx == listLen - k)return next;
            next = next->next;
            idx++;
        }
        return nullptr;
    }
};