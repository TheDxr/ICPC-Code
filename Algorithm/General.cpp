#ifdef _USING_WHEEL_
class Wheel
{
  public:
	ios::sync_with_stdio(false), cin.tie(0);
//去空格
	void Trim(string &s){
		int index = 0;
		if (!s.empty()){
			while ((index = s.find(' ', index)) != string::npos)
				s.erase(index, 1);
		}
	}
// 求最大公因数
	int Gcd(int a, int b){
		return b == 0 ? a : Gcd(b, a % b);
	}
//快速排序
	void Quicksort(int l, int r){
		if (l >= r)
			return;
		int i = l, j = r;
		while (i < j){
			while (i < j && a[j] >= a[l])j--;
			while (i < j && a[i] <= a[l])i++;
			swap(a[i], a[j]);
		}
		swap(a[i], a[l]);
		Quicksort(l, i - 1);
		Quicksort(i + 1, r);
	}
	// 通过最大公约数求最小公倍数
	int Lcm(int p, int q){
		int pq = p * q;
		return pq / Gcd(p, q);
	}
//筛选素数
	void PrimeScreen(vector<bool>& prime){
    for(int i = 2;i < prime.size();i++)prime[i] = true;
	for (int i = 2; i < prime.size();i++){
		if (prime[i]){
			for (int j = i * 2; j < prime.size(); j += i)
				prime[j] = false;
		}
	}
	bool isPrime(int N){
        if(N == 1)return false;
        for(int i = 2;i*i <= N;i++)
            if(N%i == 0)return false;
        return true;
    }
//快速幂
	double Pow2(double a, int n){
		if (n < 1)
			return 0;
		if (n == 1)	return a;
		if (n % 2 == 0) {
			n /= 2;
			return Pow2(a, n) * Pow2(a, n);
		}
		else {
			n = --n / 2;
			return Pow2(a, n) * Pow2(a, n) * a;
		}
	}
	//taijan
	void Tarjan(int x)
	{
		dfn[x] = ++dfs_num;
		low[x] = dfs_num;
		vis[x] = true; //是否在栈中
		stack[++top] = x;
		for (int i = head[x]; i != 0; i = e[i].next)
		{
			int temp = e[i].to;
			if (!dfn[temp])
			{
				Tarjan(temp);
				low[x] = gmin(low[x], low[temp]);
			}
			else if (vis[temp])
				low[x] = gmin(low[x], dfn[temp]);
		}
		if (dfn[x] == low[x])
		{ //构成强连通分量
			vis[x] = false;
			color[x] = ++col_num; //染色
			while (stack[top] != x)
			{ //清空
				color[stack[top]] = col_num;
				vis[stack[top--]] = false;
			}
			top--;
		}
	}
	//优先队列用的结构
	struct Node
	{
		int first;
		int second;
		bool operator<(const Node &a) const { return first < a.first; }
		Node(int f, int s) : first(f), second(s){};
	};
//最长公共子序列
	int Lcs(int *a, int *b, int c[n + 1][n + 1], int n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (a[i] == b[j])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
					c[i][j] = max(c[i][j - 1], c[i - 1][j]);
			}
		return c[5][5];
	}
}
#endif

#ifdef _ALGORITHIM_

class Kmp
{
  private:
    void getNext(const string &substr, vector<int> &next){
        next.clear();
        next.resize(substr.size());
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < substr.size(); ++i){
            while (j > -1 && substr[j + 1] != substr[i])
                j = next[j];
            if (substr[j + 1] == substr[i])
                ++j;
            next[i] = j;
        }
    }
    int kmp(const string &str, const string &substr, vector<int> &next){
        int cnt = 0;
        getNext(substr, next);
        int j = -1;
        for (int i = 0; i < str.size(); ++i){
            while (j > -1 && substr[j + 1] != str[i])
                j = next[j];
            if (substr[j + 1] == str[i])
                ++j;
            if (j == substr.size() - 1){
                cout << "find in position : " << i << endl;
                ++cnt;
                j = next[j];
            }
        }
        if (cnt == 0)return -1;            
    }
};
class 线段树
{
	int a[MAXN];
	struct node
	{
		int l, r;
		long long lazy, sum;
		void update(long long x)
		{
			sum += 1ll * (r - l + 1) * x;
			lazy += x;
		}
	} tree[MAXN * 4];
	void Push_up(int x)
	{
		tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
	}
	void Push_down(int x)
	{
		int lazy_val = tree[x].lazy;
		if (lazy_val)
		{
			tree[x << 1].update(lazy_val);
			tree[x << 1 | 1].update(lazy_val);
			tree[x].lazy = 0;
		}
	}
	void Build(int x, int l, int r)
	{
		tree[x].l = l;
		tree[x].r = r;
		tree[x].lazy = tree[x].sum = 0;
		if (l == r)
			tree[x].sum = a[l];
		else
		{
			int mid = (l + r) / 2;
			Build(x << 1, l, mid);
			Build(x << 1 | 1, mid + 1, r);
			Push_up(x);
		}
	}
	void Update(int x, int l, int r, long long val)
	{
		int L = tree[x].l, R = tree[x].r;
		if (l <= L && R <= r)
			tree[x].update(val);
		else
		{
			Push_down(x);
			int mid = (L + R) / 2;
			if (mid >= l)
				Update(x << 1, l, r, val);
			if (r > mid)
				Update(x << 1 | 1, l, r, val);
			Push_up(x);
		}
	}
	long long Query(int x, int l, int r)
	{
		int L = tree[x].l, R = tree[x].r;
		if (l <= L && R <= r)
			return tree[x].sum;
		else
		{
			Push_down(x);
			long long ans = 0;
			int mid = (L + R) / 2;
			if (mid >= l)
				ans += Query(x * 2, l, r);
			if (r > mid)
				ans += Query(x * 2 + 1, l, r);
			Push_up(x);
			return ans;
		}
	}
}
#endif