class Solution
{
public:
    int calculate(string s)
    {
        vector<int> nums;
        vector<char> opers;
        char ch[s.size() + 8];
        int offset = 0, ans;
        unordered_map<char, int> op_hash{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        for(int i = 0; i < s.size(); i++) {
            if('0' <= s[i] && s[i] <= '9') {
                ch[offset] = s[i];
                offset++;
            }
            if(i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                ch[offset] = '\0';
                int num    = atoi(ch);
                offset     = 0;
                nums.push_back(num);
                if(i == s.size() - 1) {
                    break;
                }
                
                if((!opers.empty() && op_hash[opers.back()] >= op_hash[s[i]])) {
                    calcu(opers, nums);
                }
                if((!opers.empty() && opers.back() == '-')) {
                    int num1 = nums.back();
                    nums.pop_back();
                    nums.push_back(-num1);
                    opers.pop_back();
                    opers.push_back('+');
                }
                opers.push_back(s[i]);
                
                
            }
        }
        while(!opers.empty()) {
            calcu(opers, nums);
        }
        return nums.back();
    }

private:
    void calcu(vector<char>& opers, vector<int>& nums)
    {
        char op  = opers.back();
        int num2 = nums.back();
        nums.pop_back();
        int num1 = nums.back();
        nums.pop_back();
        if(op == '+') {
            nums.push_back(num1 + num2);
        }
        else if(op == '-') {
            nums.push_back(num1 - num2);
        }
        else if(op == '*') {
            nums.push_back(num1 * num2);
        }
        else if(op == '/') {
            nums.push_back(num1 / num2);
        }
        opers.pop_back();
    }
};