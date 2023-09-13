#pragma once

#include "../DataStructure.h"

namespace util
{
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

} // namespace util
