// #include "Utils/Util.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int MINF = -1e6;
const int INF = 1e9;

int main() {
    iostream::sync_with_stdio(false);
    int64_t ans = 0;
    unordered_map<int, int> mx;
    unordered_map<int, int> my;
    map<pair<int,int>, int> over;
    int n;
    cin >> n;
    int offset = INF;
    while(n--) {
        int x, y;
        cin >> x >> y;
        x += offset;
        y += offset;
        if( mx.count(x) != 0 ||  my.count(y) != 0 ){
            ans+=mx[x]+my[y];
            if(over[{x,y}] >= 1){
                ans-=over[{x,y}];
            }
        }
        over[{x,y}] += 1;
        mx[x] += 1;
        my[y] += 1;
    }   
    cout << ans <<endl;
}