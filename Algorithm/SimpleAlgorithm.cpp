#include <bits/stdc++.h>
using namespace std;
/*
    ios::sync_with_stdio(false), cin.tie(0);
    //优先队列用的结构
    struct Node
    {
        int first;
        int second;
        bool operator<(const Node &a) const { return first < a.first; }
        Node(int f, int s) : first(f), second(s){};
    };
 */
namespace SimpleAlgorithm
{

// 去空格
void Trim(string &s)
{
    int index = 0;
    if(!s.empty()) {
        while((index = s.find(' ', index)) != string::npos)
            s.erase(index, 1);
    }
}
// 筛选素数
void PrimeScreen(vector<bool> &prime)
{
    if(prime.size() > 1) prime[1] = false;
    for(int i = 4; i < prime.size(); i += 2)
        prime[i] = false;
    for(int i = 2; i < prime.size(); i++) {
        if(prime[i]) {
            for(int j = i * 2; j < prime.size(); j += i)
                prime[j] = false;
        }
    }
}
// 求最大公因数
int Gcd(int a, int b) { return b == 0 ? a : Gcd(b, a % b); }
// 通过最大公约数求最小公倍数
int Lcm(int p, int q)
{
    int pq = p * q;
    return pq / Gcd(p, q);
}
// 快速排序
void quick_sort(std::vector<int> &arr, int left, int right)
{
    if(left >= right) return;
    int i = left, j = right;
    while(i < j) {
        while(i < j && arr[j] >= arr[left])
            j--;
        while(i < j && arr[i] <= arr[left])
            i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[left]);
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}
void Quicksort(int l, int r, int *a)
{
    if(l >= r) return;
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[j] >= a[l])
            j--;
        while(i < j && a[i] <= a[l])
            i++;
        swap(a[i], a[j]);
    }
    swap(a[i], a[l]);
    Quicksort(l, i - 1);
    Quicksort(i + 1, r);
}
// 归并排序
void mergeSortSearch(int left, int right, vector<int> &vec, vector<int> &ret, int depth = 0)
{
    if(right <= left) return;
    int mid = (left + right) / 2;
    mergeSortSearch(left, mid, vec, ret, depth + 1);
    mergeSortSearch(mid + 1, right, vec, ret, depth + 1);
    int i = left, j = mid + 1;
    int idx = left;
    while(i <= mid && j <= right) {
        ret[idx++] = vec[i] < vec[j] ? vec[i++] : vec[j++];
    }
    while(i <= mid)
        ret[idx++] = vec[i++];
    while(j <= right)
        ret[idx++] = vec[j++];
    for(int i = left; i <= right; i++) {
        vec[i] = ret[i];
    }
}
// 快速幂
long long Pow_Mode(long long a, long long b, long long mode)
{
    long long sum = 1;
    a             = a % mode;
    while(b > 0) {
        if(b % 2 == 1) // 判断是否是奇数，是奇数的话将多出来的数事先乘如sum
            sum = (sum * a) % mode;
        b /= 2;
        a = (a * a) % mode; // 不断的两两合并再取模，减小a和b的规模
    }
    return sum;
}
// 递归版快速幂
double Pow2(double a, int n)
{
    if(n < 1) return 0;
    if(n == 1) return a;
    if(n % 2 == 0) {
        n /= 2;
        return Pow2(a, n) * Pow2(a, n);
    }
    else {
        n = --n / 2;
        return Pow2(a, n) * Pow2(a, n) * a;
    }
}
// 最长公共子序列
int Lcs(int *a, int *b, int c[][5], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    return c[5][5];
}
}; // namespace SimpleAlgorithm