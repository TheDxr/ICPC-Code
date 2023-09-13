#pragma once
#include <vector>
#include <functional>


template <typename T = int>
class MatrixNxM
{
public:
    MatrixNxM(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols));
    }
    T& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return -1;
        }
        return data[row][col];
    }
    int rows;
    int cols;
    std::vector<std::vector<T>> data;
};

template <typename T>
bool Valid(int x, int y,const MatrixNxM<T> &matrix)
{
    return (x >= 0 && x < matrix.cols && y >= 0 && y < matrix.rows);
}

template <typename T>
void For_each(MatrixNxM<T> &matrix, std::function<void(int, int)> func)
{
    for (int y = 0; y < matrix.rows; ++y) {
        for (int x = 0; x < matrix.cols; ++x) {
            func(x, y);
        }
    }
}

template <typename T>
void Bfs(MatrixNxM<T> &matrix, int x, int y)
{
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{1,1},{1,-1},{-1,1},{-1,-1}};
    std::vector<std::vector<bool>> visited(matrix.rows, std::vector<bool>(matrix.cols));
    std::vector<std::vector<int>> dist(matrix.rows, std::vector<int>(matrix.cols));
    std::vector<std::vector<int>> prev(matrix.rows, std::vector<int>(matrix.cols));
    std::queue<std::pair<int, int>> q;
    q.emplace(x, y);
    visited[y][x] = true;
    dist[y][x] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto &d : directions) {
            int nx = p.first + d[0];
            int ny = p.second + d[1];
            if (Valid(nx, ny, matrix) && !visited[ny][nx]) {
                q.emplace(nx, ny);
                visited[ny][nx] = true;
                dist[ny][nx] = dist[p.second][p.first] + 1;
                prev[ny][nx] = p.second * matrix.cols + p.first;
            }
        }
    }
}