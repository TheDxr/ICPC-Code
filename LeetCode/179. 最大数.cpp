class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        std::sort(nums.begin(), nums.end(), compare);
        for(auto i : nums) {
            result += to_string(i);
        }
        if(result[0] == '0')return "0";
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