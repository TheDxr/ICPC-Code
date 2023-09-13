#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../DataStructure.h"

namespace Utils
{
void print(ListNode *pHead)
{
    ListNode *pNext    = pHead;
    int i              = 0;
    std::string buffer = "[ ";
    while(pNext != nullptr) {
        buffer += std::to_string(pNext->val) + " ";
        pNext = pNext->next;
        if(i++ > 20) break;
    }
    buffer += "]\n";
    std::cout << buffer;
}

template <typename T>
void print(std::vector<std::vector<T>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int max_type_width = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            max_type_width = std::max(max_type_width, (int)std::to_string(matrix[i][j]).size());
        }
    }

    for(int i = 0; i < row; i++) {
        std::string buffer;
        if(i == 0)
            buffer += "┌";
        else if(i == row - 1)
            buffer += "└";
        else
            buffer += "│";
        for(int j = 0; j < col; j++) {
            int space = max_type_width - std::to_string(matrix[i][j]).size();
            buffer += std::string(space, ' ');
            buffer += std::to_string(matrix[i][j]);
            if(j == col - 1) {
                if(i == 0)
                    buffer += " ┐\n";
                else if(i == row - 1)
                    buffer += " ┘\n";
                else
                    buffer += " │\n";
            }
            else {
                buffer += " ";
            }
        }
        std::cout << buffer;
    }
}

template <typename T>
void print(std::vector<T> vec)
{
    std::string buffer = "[ ";
    for(auto it = vec.begin(); it != vec.end(); it++) {
        buffer += std::to_string(*it) + " ";
        //        if(it != vec.end() - 1) {
        //            buffer += " ";
        //        }
    }
    buffer += "]\n";
    std::cout << buffer;
}

void print(bool b) { std::cout << (b ? "true" : "false"); }

template <typename T>
void print(T t, const std::string &end = "\n")
{
    std::cout << t << end;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
    std::cout << t << " ";
    print(args...);
}
} // namespace util