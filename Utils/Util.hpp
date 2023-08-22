#pragma once

#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "DrawGraph.hpp"
#include "Math.hpp"

namespace util
{
#pragma region 数据结构
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#pragma endregion

#pragma region 工具函数
bool isSpace(char c) { return (c == ' '); }
bool isNum(char c) { return ('0' <= c && c <= '9'); }
bool isLetter(char c) { return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')); }
bool isOperator(char c) { return !isSpace(c) && !isNum(c) && !isLetter(c); }
#pragma endregion

#pragma region 测试数据
// constexpr int MINF = std::numeric_limits<int>::min();
// constexpr int INF  = std::numeric_limits<int>::max();
std::vector<std::vector<int>> test_mat4x4_int{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {5, 4, -9, 16}};
std::vector<int> test_vector_int{8, 1, -3, 4, 5, 4, -9, 16, 9};
std::vector<std::vector<int>> test_mat2x1_int{{1, 0}};
std::vector<std::vector<float>> test_mat4x4_float{{1.1, 2.2, 3.3, 4.4},{5.5, 6.6, 7.7, 8.8},{9.9, 10.1, 11.2, 12.3},{5.4, 4.3, -9.2, 16.1}};

ListNode *CreateList(std::vector<int> vec)
{
    ListNode *pHead = new ListNode(-1);
    ListNode *pNode = pHead;
    for(int i : vec) {
        pNode->next = new ListNode(i);
        pNode       = pNode->next;
    }
    return pHead->next;
}
ListNode *test_list = CreateList(test_mat4x4_int[1]);
std::map<int, ListNode *> CreateListAddress(ListNode *pHead, int max_size = 20)
{
    std::map<int, ListNode *> NodeAddr;
    ListNode *pNode = pHead;
    int i           = 0;
    while(pNode != nullptr) {
        if(i++ > max_size) break;
        NodeAddr.emplace(pNode->val, pNode);
        pNode = pNode->next;
    }
    return NodeAddr;
}

class TestClass
{
public:
    TestClass(int _id) : id(_id), Val(_id)
    {
        std::cout << "Init TestClass() ID: " << id << std::endl;
    }
    TestClass(const TestClass &t)
    {
        this->id  = t.id;
        this->Val = t.Val;
        std::cout << "Cpoied TestClass ID: " << t.id << std::endl;
    }
    TestClass(TestClass &&t)
    {
        this->id  = t.id;
        this->Val = t.Val;
        std::cout << "Moved TestClass ID: " << t.id << std::endl;
        t.id  = -1;
        t.Val = -1;
    }
    TestClass &operator=(const TestClass &t)
    {
        this->id  = t.id;
        this->Val = t.Val;
        std::cout << "Copied TestClass by operator= ID: " << t.id << std::endl;
        return *this;
    }
    TestClass &operator=(TestClass &&t)
    {
        this->id  = t.id;
        this->Val = t.Val;
        std::cout << "Moved TestClass operator= ID: " << t.id << std::endl;
        t.id  = -1;
        t.Val = -1;
        return *this;
    }
    ~TestClass() { std::cout << "Destructed TestClass ID: " << id << std::endl; }
    void print() { std::cout << "TestClass::print::ID : " << id << std::endl; }
    int Val;

private:
    int id;
};
class comma_numpunct : public std::numpunct<char>
{
protected:
    virtual char do_thousands_sep() const { return ','; }

    virtual std::string do_grouping() const { return "\03"; }
};
class MicrosecondsTimer
{
public:
    static void UnitTest(std::function<void()> func, int loop_times)
    {
        std::locale comma_locale(std::locale(), new comma_numpunct());
        std::cout.imbue(comma_locale);
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < loop_times; i++) {
            func();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Time: " << std::setprecision(2)
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " us\n";
    }
    virtual void Update() {}
    void StartTest(int loop_times)
    {
        std::locale comma_locale(std::locale(), new comma_numpunct());
        std::cout.imbue(comma_locale);
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < loop_times; i++) {
            Update();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Time: " << std::setprecision(2)
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " us\n";
    }
};
namespace show_copy
{
int copy_count     = 0;
int move_count     = 0;
int init_count     = 0;
int destruct_count = 0;
void reset()
{
    copy_count     = 0;
    move_count     = 0;
    init_count     = 0;
    destruct_count = 0;
}
struct Node
{
    int Val;
    Node(int _val) : Val(_val) { init_count++; }
    Node() : Val(-2147483647) { init_count++; }
    Node(const Node &n)
    {
        Val = n.Val;
        copy_count++;
    }
    Node(Node &&n)
    {
        Val = n.Val;
        move_count++;
    }
    ~Node() { destruct_count++; }
    Node &operator=(const Node &n)
    {
        Val = n.Val;
        copy_count++;
        return *this;
    }
    Node &operator=(Node &&n)
    {
        Val = n.Val;
        move_count++;
        return *this;
    }
};
void print()
{
    std::cout << "Copy: " << copy_count << " Move: " << move_count << " Init: " << init_count
              << " Destruct: " << destruct_count << std::endl;
}
} // namespace show_copy
#pragma endregion

#pragma region 输出
void print(ListNode *pHead)
{
    ListNode *pNext = pHead;
    int i           = 0;
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
        if(i == 0) buffer+= "┌";
        else if(i == row - 1) buffer += "└";
        else buffer += "│";
        for(int j = 0; j < col; j++) {
            int space = max_type_width - std::to_string(matrix[i][j]).size();
            buffer += std::string(space, ' ');
            buffer += std::to_string(matrix[i][j]);
            if(j == col - 1) {
                if(i == 0) buffer += " ┐\n";
                else if(i == row - 1) buffer += " ┘\n";
                else buffer += " │\n";
            }else {
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
void print(T t,const std::string& end = "\n")
{
    std::cout << t << end;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
    std::cout << t << " ";
    print(args...);
}

void displayList(
    std::map<int, ListNode *> NodeAddr, std::string displayPath = "./Display/display.dot")
{
    DrawGraph draw(displayPath, DrawGraph::DiGraph);

    draw.Start();
    draw.Set("rankdir", "LR");

    for(auto &addr : NodeAddr) {
        if(addr.second->next != nullptr) {
            draw.CreateRelationship(
                std::to_string(addr.first),
                std::to_string(addr.second->next->val),
                {{"constraint", "false"}});
        }
        else {
            draw.CreateRelationship(
                std::to_string(addr.first), "NULL", {{"constraint", "false"}, {"style", "dotted"}});
        }
    }
    draw.End();
}

void displayList(
    ListNode *pHead,
    std::vector<std::pair<ListNode *, std::string>> HightLight,
    std::string displayPath = "./Display/display.dot")
{
    auto NodeAddr = CreateListAddress(pHead);

    DrawGraph draw(displayPath, DrawGraph::DiGraph);
    draw.Start();
    draw.Set("rankdir", "LR");

    for(auto &addr : NodeAddr) {
        if(addr.second->next != nullptr) {
            draw.CreateRelationship(
                std::to_string(addr.first),
                std::to_string(addr.second->next->val),
                {{"constraint", "false"}});
        }
        else {
            draw.CreateRelationship(
                std::to_string(addr.first), "NULL", {{"constraint", "false"}, {"style", "dotted"}});
        }
    }
    for(auto high : HightLight) {
        std::string highLight =
            "  " + std::to_string(high.first->val) + "[color=" + high.second + ",style=filled];";
        draw.AppendProperty(highLight);
    }

    draw.End();
}

void displayList(ListNode *pHead, std::string displayPath = "./Display/display.dot")
{
    auto NodeAddr = CreateListAddress(pHead);

    DrawGraph draw(displayPath, DrawGraph::DiGraph);
    draw.Start();
    draw.Set("rankdir", "LR");

    // int i = 0;
    // for (auto &addr : NodeAddr)
    // {
    //     draw.createNode(to_string( addr.first ),{{"constraint","false"},
    //                             {"pos","\""+to_string(i++)+",1"+"\""}
    //                            // {"rect","true"}
    //                             });
    // }
    for(auto &addr : NodeAddr) {
        if(addr.second->next != nullptr) {
            draw.CreateRelationship(
                std::to_string(addr.first),
                std::to_string(addr.second->next->val),
                {{"constraint", "false"}});
        }
        else {
            draw.CreateRelationship(
                std::to_string(addr.first), "NULL", {{"constraint", "false"}, {"style", "dotted"}});
        }
    }

    draw.End();
}
#pragma endregion
} // namespace util