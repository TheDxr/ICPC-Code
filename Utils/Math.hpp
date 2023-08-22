#pragma once
#include <vector>
namespace math
{
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
} // namespace math
