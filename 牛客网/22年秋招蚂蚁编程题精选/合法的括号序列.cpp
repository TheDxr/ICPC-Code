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
    int N;
    stack<char> s;
    string seq;
    cin >> seq;
    N = seq.length();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            {
                if (seq[i] == '?') {
                    if (j == 0) {
                        dp[i + 1][j + 1] = dp[i][j];
                    } else {
                        dp[i + 1][j + 1] = dp[i][j];
                        dp[i + 1][j - 1] = dp[i][j] + dp[i + 1][j - 1];
                        dp[i + 1][j - 1] %=INF;
                    }
                }
                if (seq[i] == '(') {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (seq[i] == ')' && j != 0) {
                    dp[i + 1][j - 1] = dp[i][j];
                }
            }
        }
    cout << dp[N][0] % static_cast<int64_t>(INF) << endl;
}