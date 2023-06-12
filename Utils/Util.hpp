#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "DrawGraph.hpp"

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
std::vector<std::vector<int>> test_matrix{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {5, 4, -9, 16}};
std::vector<int> test_vector{8, 1, -3, 4, 5, 4, -9, 16, 9};
std::vector<std::vector<int>> test_matrix_2{{1, 0}};
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
ListNode *test_list = CreateList(test_matrix[1]);
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
    std::cout << "==========List=========\n";
    while(pNext != nullptr) {
        std::cout << pNext->val << " ";
        pNext = pNext->next;
        if(i++ > 20) break;
    }
}

template <typename T>
void print(std::vector<std::vector<T>> matrix)
{
    std::cout << "==========matrix=========\n";
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
            if(j == matrix[0].size() - 1) std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void print(std::vector<T> vec)
{
    for(auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it;
        if(it != vec.end() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void print(bool b) { std::cout << (b ? "true" : "false") << std::endl; }

template <typename T>
void print(T item)
{
    std::cout << item << std::endl;
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