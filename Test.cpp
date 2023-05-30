#include<bits/stdc++.h>
using namespace std;
void findCombinations(const vector<int>& nums) {
    int n = nums.size();
    int totalCombinations = 1 << n;  // 总的组合数为2的n次方

    for (int i = 1; i < totalCombinations; ++i) {
        vector<int> combination;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {  // 检查二进制数i的第j位是否为1
                combination.push_back(nums[j]);
            }
        }

        // 输出当前组合
        for (const auto& num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
}