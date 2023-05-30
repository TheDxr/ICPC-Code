#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MINF -1e9
#define INF 1e9

int main() {
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int step = a[0];
    if(n >= 2) step = std::max({ step, ( int )ceil(a[1] / 2.0) });
    int first_step = a[0], second_step = INF;
    //分开情况
    for(int i = 1; i < n; i++) {
        if(first_step > ceil(a[i] / 2.0)) {
            second_step = first_step;
            first_step = ceil(a[i] / 2.0);
        }else if(second_step > ceil(a[i] / 2.0)) {
            second_step = ceil(a[i] / 2.0);
        }
        step = min(step, first_step + second_step);
    }
    //相连情况
    for(int i = 2; i < n; i++) {
        if(2 * a[i - 1] < a[i]){
            step = min(step, (int)ceil(a[i]));
        }else {
            first_step = ceil(a[i] / 2.0);
            second_step = ceil((a[i - 1] - first_step) / 2.0);
            step = min(step, second_step + first_step);
        }
    }
    cout << step << endl;
}