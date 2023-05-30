class Solution {
public:
    int balancedStringSplit(const string& s)
    {
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == 'L')left++;
            else right++;
            if(left != 0 && left == right)
            {
                right = 0;
                left = 0;
                ans++;
            }
        }
        return ans;
    }
private:
    int ans = 0;
    int right = 0;
    int left = 0;
};