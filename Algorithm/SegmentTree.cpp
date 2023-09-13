class SegmentTree
{
private:
    int *a;
    struct node
    {
        int l, r;
        long long lazy, sum;
        void update(long long x)
        {
            sum += 1ll * (r - l + 1) * x;
            lazy += x;
        }
    } *tree;
    void Push_up(int x) { tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum; }
    void Push_down(int x)
    {
        int lazy_val = tree[x].lazy;
        if(lazy_val) {
            tree[x << 1].update(lazy_val);
            tree[x << 1 | 1].update(lazy_val);
            tree[x].lazy = 0;
        }
    }

public:
    SegmentTree(const int MAXN, int *array, int len)
    {
        a    = array;
        tree = new node[MAXN * 4];
    }
    ~SegmentTree() { delete tree; }
    void Build(int l, int r, int x = 1)
    {
        tree[x].l    = l;
        tree[x].r    = r;
        tree[x].lazy = tree[x].sum = 0;
        if(l == r)
            tree[x].sum = a[l];
        else {
            int mid = (l + r) / 2;
            Build(l, mid, x << 1);
            Build(mid + 1, r, x << 1 | 1);
            Push_up(x);
        }
    }
    void Update(int l, int r, long long val, int x = 1)
    {
        int L = tree[x].l, R = tree[x].r;
        if(l <= L && R <= r)
            tree[x].update(val);
        else {
            Push_down(x);
            int mid = (L + R) / 2;
            if(mid >= l) Update(l, r, val, x << 1);
            if(r > mid) Update(l, r, val, x << 1 | 1);
            Push_up(x);
        }
    }
    long long Query(int l, int r, int x = 1)
    {
        int L = tree[x].l, R = tree[x].r;
        if(l <= L && R <= r)
            return tree[x].sum;
        else {
            Push_down(x);
            long long ans = 0;
            int mid       = (L + R) / 2;
            if(mid >= l) ans += Query(l, r, x * 2);
            if(r > mid) ans += Query(l, r, x * 2 + 1);
            Push_up(x);
            return ans;
        }
    }
};