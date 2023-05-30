// #include "Utils/Util.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int MINF = -1e9;
const int INF = 1e9 + 7;

int main() {
    iostream::sync_with_stdio(false);
    int N, M;
    int64_t ans = 0;
    string command;
    cin >> N >> command >> M;
    vector<vector<bool>> food(2008, vector<bool>(2008, false));
    int offset = 1000;
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        food[x + offset][y + offset] = true;
    }

    int64_t length = 1;
    deque<pair<int, int>> route;
    route.emplace_back(make_pair(0 + offset, 0 + offset));
    for(int i = 0; i < N; i++) {
        int pos_x = route.front().first;
        int pos_y = route.front().second;
        switch(command[i]) {
        case 'W':
            pos_y += 1;
            break;
        case 'S':
            pos_y -= 1;
            break;
        case 'A':
            pos_x -= 1;
            break;
        case 'D':
            pos_x += 1;
            break;
        }
        if(pos_x < 2008 && pos_y < 2008 && pos_x >=0 && pos_y >= 0 &&  food[pos_x][pos_y]) {
            length += 1;
            food[pos_x][pos_y] = false;
            route.emplace_front(make_pair(pos_x, pos_y));
        }
        else {
            route.emplace_front(make_pair(pos_x, pos_y));
            route.pop_back();
        }
        
        for(int r = 1;r < route.size();r++) {
            if(pos_x == route[r].first && pos_y == route[r].second) {
                cout << length << endl;
                return 0;
            }
        }
    }
    cout << length << endl;
}