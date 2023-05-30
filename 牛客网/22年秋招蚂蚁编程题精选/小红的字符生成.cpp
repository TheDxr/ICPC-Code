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
    cin >> N;
    string ans;
    int i = N;
    while(i != 0) {
        for(int j = 25; j >= 0; j--) {
            if(i - pow(2, j) >= 0) {
                ans.push_back(static_cast<char>('a' + j));
                i -= pow(2, j);
            }
        }
    }
    cout << ans << endl;
}