#pragma once
#include "../DataStructure.h"

namespace Utils
{
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

}
