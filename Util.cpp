#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

vector NodeAddr = vector<ListNode *>();
void showList()
{
    queue<pair<int, int>> Q;
    vector<string> canvas = vector<string>(100);
    for (int i = 0; i < NodeAddr.size(); i++)
    {
        canvas[i] = "  ";
    }
    for (int i = 0; i < NodeAddr.size(); i++)
    {
        if (NodeAddr[i]->next != nullptr && NodeAddr[i]->next->val == i - 1)
        {
            canvas[i - 1] = "<-";
        }

        if (NodeAddr[i]->next != nullptr && NodeAddr[i]->next->val == i + 1)
        {
            canvas[i] = "->";
        }
        if (NodeAddr[i]->next == nullptr)
        {
            canvas[i] = "-> NULL ";
        }
        if (NodeAddr[i]->next != nullptr && NodeAddr[i]->next->val != i + 1 && NodeAddr[i]->next->val != i - 1)
        {
            Q.emplace(make_pair(i, NodeAddr[i]->next->val));
        }
    }
    for (int i = 0; i < NodeAddr.size(); i++)
    {
        cout << i << " " << canvas[i] << " ";
    }
    cout << endl;
    while (!Q.empty())
    {
        auto val = Q.front();
        Q.pop();
        for (int i = 0; i <= val.second; i++)
        {
            if (val.first < i && i < val.second)
                cout << "-----";
            else if (val.first == i)
                cout << "|"
                     << "----";
            else if (val.second == i)
                cout << "|";
            else
                cout << " "
                     << " "
                     << "  "
                     << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printList(ListNode *pHead)
{
    ListNode *pNext = pHead;
    int i = 0;
    while (pNext != nullptr)
    {
        std::cout << pNext->val << " ";
        pNext = pNext->next;
        if (i++ > 20)
            break;
    }
    cout << "\n=======================\n";
}