class Solution {
public:
//头插法
    ListNode* ReverseList(ListNode* pHead) {
        auto temp = new ListNode(-1);
        while(pHead != nullptr) {

            ListNode* pNext = pHead->next;//保持下一个节点
            //插入
            ListNode* p = temp->next;
            temp->next = pHead;
            pHead->next = p;

            pHead = pNext;
        }
        return temp->next;
    }
};