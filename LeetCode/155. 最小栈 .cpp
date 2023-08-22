#include <bits/stdc++.h>

/*
 * 开始时间：13:10
 * 结束时间：13:41
 * 总计：31min
 */
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stk.push_back(val);
        if(minStk.empty() || val <= minStk.back()) {
            minStk.push_back(val);
        } else{
            for(int i = 0;i < minStk.size();++i) {
                if(val > minStk[i]) {
                    minStk.insert(minStk.begin() + i, val);
                    break;
                }
            }
        }
    }

    void pop() {
        if(stk.empty()) return;
        int val = stk.back();
        stk.pop_back();
        if(minStk.size() == 0)return;
        auto idx = find(minStk.begin(), minStk.end(), val);
        if(idx != minStk.end()) {
            minStk.erase(idx);
        }
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        return minStk.back();
    }
private:
    vector<int> stk;
    vector<int> minStk;
};

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stk.push_back(val);
        if(minStk.empty() || val <= minStk.back()) {
            minStk.push_back(val);
        }
    }

    void pop() {
        if(stk.empty()) return;
        int val = stk.back();
        stk.pop_back();
        if(minStk.size() == 0)return;
        if(val == minStk.back()) {
            minStk.pop_back();
        }
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        if(minStk.empty()) return stk.back();
        return minStk.back();
    }
private:
    vector<int> stk;
    vector<int> minStk;
};