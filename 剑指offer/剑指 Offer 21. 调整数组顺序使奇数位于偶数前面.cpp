class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        deque<int> ans;
        for(int num:nums){
            if(num %2 == 0){
                ans.push_back(num);
            }else ans.push_front(num);
        }
        return vector<int>(ans.begin(),ans.end());
    }
};