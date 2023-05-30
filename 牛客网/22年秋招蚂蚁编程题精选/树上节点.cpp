// #include "Utils/Util.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int MINF = -1e9;
const int INF = 1e9 + 7;

int main() {
    iostream::sync_with_stdio(false);
    int N,u,v;
    int64_t ans = 0;
    cin >> N;
    vector<int> father(N + 1, 0);
    vector<int> node(N + 1, 0);
    for(int n = 2;n <= N;n++)node[n] += n - 1;
    for(int n = 2;n <= N;n++)
    {
        cin >> u >> v;
        father[max(u,v)] = min(u,v);
    }
    for(int i = 1;i <=N;i++){
        ans+=node[i];
        ans-=node[father[i]];
    }     
    cout << ans << endl;
}