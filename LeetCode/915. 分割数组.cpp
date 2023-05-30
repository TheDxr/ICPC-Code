class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<pair<int,int>> LMaxRMin(nums.size());
        int lmax = 0;
        for(int i = 0;i < nums.size(); ++i) {
            lmax = max(lmax, nums[i]);
            LMaxRMin[i].first = lmax;
        }
        int rmin = std::numeric_limits<int>::max();
        for(int i = nums.size() - 1;i >= 0 ; --i) {
            rmin = min(rmin, nums[i]);
            LMaxRMin[i].second = rmin;
        }
        int ans = 1;
        for(int i = 1;i < LMaxRMin.size(); ++i)
        {
            if(LMaxRMin[i -1].first <= LMaxRMin[i].second)break;
            ans++;
        }
        return ans;
    }
};