#include <string>
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
bool isSpace(char c)
{
    return (c == ' ');
}
bool isNum(char c)
{
    return ('0' <= c && c <= '9');
}
bool isLetter(char c)
{
    return (('a' <= c && c <= 'z')||('A' <= c && c <= 'Z'));
}
bool isOperator(char c)
{
    return !isSpace(c) && !isNum(c) && !isLetter(c);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string strIn;
    getline(cin, strIn);
    vector<char> strOut;
    for(int i = 0;i < strIn.size();i++)
    {
        char c = strIn[i];
        if(isOperator(c)){
            strOut.push_back(' ');
            strOut.push_back(c);
            strOut.push_back(' ');
        }
        else {
            if(c != ' ')strOut.push_back(c);
        }
    }
    strOut.push_back('\n');
    for(auto i:strOut){
        cout << i;
    }
}