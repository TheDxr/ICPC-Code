#include <bits/stdc++.h>
/*
 * 开始时间：13:00
 * 结束时间：13:07
 * 总计：7min
 */
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        vector<int> stk;
        N = pushed.size();
        for(int i = 0;i < N;++i) {
            stk.push_back(pushed[i]);
            while(!stk.empty() && stk.back() == popped[0]) {
                stk.pop_back();
                popped.erase(popped.begin());
            }
        }
        return stk.empty();
    }
private:
    size_t N;
    static constexpr int MAXN = 1e3 + 10;
};
