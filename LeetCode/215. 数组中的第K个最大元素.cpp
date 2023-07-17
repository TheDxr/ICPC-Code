// 方法一：优先队列（堆）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> priQueue;
        for(int i = 0;i < nums.size();i++) {
            priQueue.push(nums[i]);
        }
        int ans = 0;
        for(int i = 0;i < k;i++) {
            ans = priQueue.top();
            priQueue.pop();
        }
        return ans;
    }
};
// 方法二 快速排序O(n)
