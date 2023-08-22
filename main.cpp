#include <basetsd.h>
#include <bits/stdc++.h>
#include "Utils/Util.hpp"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<int> test = {31, 30, 3, 34, 3 , 31, 3};
        std::sort(nums.begin(), nums.end(), compare);
        std::sort(test.begin(), test.end(), compare);
        util::print(test);
//        for(auto i : nums) {
//            result += to_string(i);
//        }
        return result;
    }
private:
    static bool compare(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        double ad = a * pow(10, sb.size()) + b;
        double bd = b * pow(10, sa.size()) + a;
        return ad > bd;
    }
};
int main()
{
    Solution solution;
    vector<int> test = {3, 30, 34};
    cout << solution.largestNumber(util::test_vector_int) << endl;
    return 0;
}
/*

开始时间：16:15
结束时间：
总计：min
 */