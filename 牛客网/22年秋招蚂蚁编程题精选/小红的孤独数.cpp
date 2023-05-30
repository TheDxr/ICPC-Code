//#include "Utils/Util.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int MINF = -1e6;
const int INF = 1e6 + 7;

int main() {
    iostream::sync_with_stdio(false);
    int n, k;
    int64_t ans = 0;
    cin >> n >> k;
    priority_queue<int,vector<int>, std::greater<int>> q;
    map<int,int> visit;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        visit[num]++;
        if(visit[num] == 1)q.emplace(num);
    }
    while(!q.empty()) {
        int now = q.top();
        q.pop();
        if(visit[now] > 1){
            if(visit[now + k] == 0)q.emplace(now + k);
            visit[now + k] += visit[now] - 1;
            ans += visit[now] - 1;
            visit[now] = 1;
        }
    }

    cout << ans << endl;
}