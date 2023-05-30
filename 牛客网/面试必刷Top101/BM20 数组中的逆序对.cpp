class Solution
{
  public:
    int InversePairs(vector<int> data)
    {
        vector<int> ret(data.size());
        total = 0;
        mergeSortSearch(0, data.size() - 1, data, ret);
        return total % MAXN;
    }

  private:
    long long total;
    const int MAXN = 1000000007;

    void mergeSortSearch(int left, int right, vector<int> &vec, vector<int> &ret, int depth = 0)
    {
        if (right <= left)
            return;
        int mid = (left + right) / 2;
        mergeSortSearch(left, mid, vec, ret, depth + 1);
        mergeSortSearch(mid + 1, right, vec, ret, depth + 1);
        int i = left, j = mid + 1;
        int idx = left;
        while (i <= mid && j <= right)
        {
            if(vec[i] <= vec[j])
            {
                ret[idx++] = vec[i++];
            }
            else
            {
                total += (mid - i + 1)%MAXN;
                ret[idx++] = vec[j++];
            }
        }
        while (i <= mid)
        {
            ret[idx++] = vec[i++];
        }
        while (j <= right)
        {
            ret[idx++] = vec[j++];
        }            
        for (int i = left; i <= right; i++)
        {
            vec[i] = ret[i];
        }
    }
};