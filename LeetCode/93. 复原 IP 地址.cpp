// 方法一 :递归遍历
class Solution
{
public:
    vector<string> restoreIpAddresses(const string &s)
    {
        size_ = s.size();
        restore(s);
        return ans;
    }

private:
    bool isVaild(const string s)
    {
        if(s.length() == 0) return false;
        int num = atoi(s.c_str());
        return num <= 255 && num >= 0;
    }
    vector<string> ans;
    int size_;
    void restore(const string s, int depth = 0, string temp = "")
    {
        if(s.length() == 0) return;
        if(depth == 4) {
            if(temp.length() - 4 == size_) {
                temp.pop_back();
                ans.push_back(temp);
                return;
            }
            else
                return;
        }
        for(int i = 1; i <= 3; i++) {
            string sub  = s.substr(0, i);
            string left = s.substr(s.length() > i ? i : 0);
            if(sub.length() != i || (sub.length() > 1 && sub[0] == '0')) continue;
            if(isVaild(sub)) {
                restore(left, depth + 1, temp + sub + ".");
            }
        }
    }
};
// 方法二:正则表达式