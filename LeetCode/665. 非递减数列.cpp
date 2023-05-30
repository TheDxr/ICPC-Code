class Solution {
  public:
    bool checkPossibility(vector<int>& nums) {
        int step = 0;
        for (int i = 0;i < nums.size() - 1;i++) {
            if(nums[i] > nums[i + 1]) {
                step += 1;
                if(i > 0 ){
                    if(nums[i - 1] <= nums[i + 1]){
                        nums[i] = nums[i - 1];
                    }
                    if(nums[i - 1] > nums[i + 1]){
                        nums[i + 1] = nums[i];
                    }
                }
                if(i == 0){
                    nums[i] = nums[i + 1];
                }
            }
        }
        return step < 2;
    }
};