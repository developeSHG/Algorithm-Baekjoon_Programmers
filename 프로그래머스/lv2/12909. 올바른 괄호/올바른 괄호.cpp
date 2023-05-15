#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int res[2] = {};
    for (const auto& el : s)
    {
        ++res[(el == '(') ? 0 : 1];
        if (res[0] < res[1]) return false;
    }
    return res[0] == res[1];
}