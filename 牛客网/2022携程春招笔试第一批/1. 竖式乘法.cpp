#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int trail;
    cin >> trail;
    while (trail--) {
        int a, b;
        int64_t ans = 0;
        cin >> a >> b;
        string bStr = to_string(b);
        for (int i = bStr.length() - 1; i >= 0; --i) {
            int temp = a * static_cast<int>(bStr[i] - '0');
            ans += temp;
        }
        cout << ans << endl;
    }
}