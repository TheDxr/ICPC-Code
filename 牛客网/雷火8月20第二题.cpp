#include <basetsd.h>
#include <bits/stdc++.h>
#include "Utils/Util.hpp"
using namespace std;

int n = 2,m = 2,c = 1,d = 2;
int sum,cnt;
class Graph2D
{
public:
    Graph2D(int width, int height) : width(width), height(height)
    {
        data = std::vector<std::vector<int>>(height, std::vector<int>(width));

    }
    int& at(int x, int y)
    {
        if(!valid(x, y))throw std::out_of_range("x or y out of range");
        return data[y][x];
    }
    bool valid(int x, int y)
    {
        return (x >= 0 && x < width && y >= 0 && y < height);
    }
    std::vector<std::vector<int>> data;
    int width;
    int height;
    Graph2D for_each(std::function<void(int, int)> func)
    {
        for(int y = 0;y < height;++y) {
            for(int x = 0;x < width;++x) {
                func(x, y);
            }
        }
        return *this;
    }
    std::vector<int *> get_next4(int x, int y)
    {
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<int *> res;
        for(auto &d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if(valid(nx, ny)) {
                res.push_back(&at(nx, ny));
            }
        }
        return res;
    }
    std::vector<int *> get_next8(int x, int y)
    {
        int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{1,1},{1,-1},{-1,1},{-1,-1}};
        std::vector<int *> res;
        for(auto &d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if(valid(nx, ny)) {
                res.push_back(&at(nx, ny));
            }
        }
        return res;
    }
};
void dfs(int b, Graph2D campus,int pos)
{
    if(b == 0){
        campus.for_each([&campus](int x, int y) {
            if(campus.data[y][x] == 1){
                int temp = c;
                auto items = campus.get_next8(x, y);
                for(auto item:items){
                    if(*item == 0){
                        temp *= d;
                    }
                }
                sum += temp;
            }
        });
        cnt++;
        return;
    }
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            if(campus.data[i][j] == 0 && i*n + j >= pos){
                campus.data[i][j] = 1;
                dfs(b - 1, campus, i * n + j);
                campus.data[i][j] = 0;
            }
        }
    }
}


int main()
{
    // A:0 B:1
    Graph2D campus(m, n) ;
    for(int i = 0;i <= n*m;++i){
        sum = 0;
        cnt = 0;
        dfs(i, campus, 0);
        cout << sum << " " << cnt << endl;
    }
    return 0;
}
/*

开始时间：16:15
结束时间：20:17
总计：min
 */