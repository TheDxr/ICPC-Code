#include <vector>
using namespace std;
/**
 * @brief 树状数组模板
 * 
 * @tparam T 
 */
template <typename T>
class BITree {
public:
    // Update
    void add(int index, T value) {
        while(index < n) {
            node[index] += value;
            index += low_bit(index);
        }
    }
    // 求前缀和
    T sum(int index) {
        T ret = 0;
        while(index > 0) {
            ret += node[index];
            index -= low_bit(index);
        }
        return ret;
    }
    BITree(vector<T> v) : n(v.size() + 1) {
        node.resize(n);
        for(int i = 1;i <= n;i++){
            add(i, v[i-1]);
        }
    }
    int size(){
        return n;
    }
private:
    vector<T> node;
    int low_bit(int x) {
        return x & (-x);
    }
    int n;
};