#include <vector>
using namespace std;
/**
 * @brief ST表模板
 * 解决区间最值问题
 */
class STTable {
public:
    STTable(vector<int>& init) {
        mn = init;
        dp.resize(init.size());
        for(int i = 0; i < init.size(); i++) {
            dp[i].resize(25);
            dp[i][0] = init[i];
        }
        for(int j = 1; (1<<j) <= n; j++) {
            for(int i = 1; i + (1<<j) -1 <= n; i++) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
                // 例: min(5,12) = min(min(5, 2), min(9, 2))
                //     min(5,12) = min(min(5...8), min(9...12))
              }
              // TODO:
        }
    }
    int rmq(int L, int R) {}

private:
    /** @i:区间左 @j:区间右 = i + 2^j - 1 */
    vector<vector<int>> dp;
    vector<int> mn;
};
