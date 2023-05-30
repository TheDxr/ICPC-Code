
class Solution {
  public:
    vector<int> MySort(vector<int>& arr) {
        quick_sort(0, arr.size()- 1, arr);
        return arr;
    }
    void quick_sort(int l, int r, vector<int>& a) {
        if(l >= r)return;
        int i = l, j = r;
        while(i < j) {
            while(i < j && a[j] >= a[l]) j--;
            while(i < j && a[i] <= a[l]) i++;
            if(i >= j)break;
            swap(a[i], a[j]);
            if(i >= j)break;
        }
        swap(a[i], a[l]);
        quick_sort(l, i - 1, a);
        quick_sort(i + 1, r, a);
    }
};