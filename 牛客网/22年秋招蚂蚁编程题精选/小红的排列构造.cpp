// #include "Utils/Util.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MINF -1e9
#define INF 1e9
vector<bool> isPrime(200000, true);
vector<int> ans;
int N;
void dfs(int n, vector<int>& v, vector<bool>& visit) {
    if(n == N + 1) {
        ans = v;
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(!visit[i] && !isPrime[i + n]) {
            v[n] = i;
            visit[i] = true;
            dfs(n + 1, v, visit);
        }
    }
}
int main() {
    iostream::sync_with_stdio(false);
    // isPrime[1] = false;
    // for(int i = 4; i < isPrime.size(); i += 2) isPrime[i] = false;
    // for(int i = 2; i < isPrime.size(); i++) {
    //     if(isPrime[i]) {
    //         for(int j = i * 2; j < isPrime.size(); j += i) isPrime[j] = false;
    //     }
    // }
    cin >> N;
    // vector<bool> visit(N + 1);
    // vector<int> v(N + 1);
    // dfs(1, v, visit);
    // if(ans.size() == 0 || ans[N] == 0){
    //     cout << -1 << endl;
    //     return 0;
    // }
    // for(int i = 1;i <= N;i++) {
    //     cout << ans[i];
    //     if(i != N)cout << " ";
    // }
    if(N <= 2) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= N; i++) {
        switch(i) {
        case 1:
            cout << 3;
            break;
        case 2:
            cout << 2;
            break;
        case 3:
            cout << 1;
            break;
        default:
            cout << i;
        }
        if(i != N) cout << " ";
    }
    cout << endl;
}