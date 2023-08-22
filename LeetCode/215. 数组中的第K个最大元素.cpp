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
//未优化 方法二 快速排序O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k_quick_sort(nums,0,nums.size()-1,k);
        return nums[nums.size()-k];
    }
private:
    void k_quick_sort(std::vector<int>& arr,int left, int right,int k)
    {
        if(left >= right ) return;
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && arr[j] >= arr[left]) j--;
            while(i < j && arr[i] <= arr[left]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);
        if( arr.size()- k < i){
            k_quick_sort(arr, left, i - 1,k);
        }
        if( arr.size()- k > i){
            k_quick_sort(arr, i + 1, right,k);
        }

    }
};