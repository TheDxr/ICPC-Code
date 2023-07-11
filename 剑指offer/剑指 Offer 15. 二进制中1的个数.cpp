class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t ans = 0;
        while(n != 0){
            ans += n & 1;
            n = n >> 1;
        }
        return ans;
    }
};