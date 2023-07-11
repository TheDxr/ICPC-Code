
// slow
class Solution
{
public:
    string minRemoveToMakeValid(string s) 
    {
        vector<char> stk;
        vector<int>  braceIdx;
        string ans;
        braceIdx.reserve(s.size());
        ans.reserve(s.size());
        for(int i = 0;i < s.size();++i){
            char c = s[i];
            if(c == '(') {
                stk.push_back(c);
                braceIdx.push_back(i);
            }
            else if(c == ')') {
                if(!stk.empty()) {
                    stk.pop_back();
                    braceIdx.pop_back();
                }
                else {
                    ans.push_back(' ');
                    continue;
                }
            }
            ans.push_back(c);
        }
        if(!stk.empty())
        {
           for(int i = braceIdx.size() - 1;i >= 0; --i)
           {
                ans.erase(ans.begin() + braceIdx[i]);
           }
        }
        for(int i = ans.size() - 1;i >= 0; --i)
        {   
            if(ans[i] == ' ')
                ans.erase(ans.begin() +i);
        }
        return ans;
    }
};