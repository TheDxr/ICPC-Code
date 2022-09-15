#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) 
            for(int j = i + 1; j < nums.size(); j++) {
            if(target - nums[i] == nums[j]){
                ans.emplace_back(i);
                ans.emplace_back(j);
                return ans;
            }
        }
        return ans;
    }
};