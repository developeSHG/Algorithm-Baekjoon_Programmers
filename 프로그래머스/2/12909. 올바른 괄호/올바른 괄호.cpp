#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int pivot = 0;
    for(const auto& chr : s)
    {
        pivot += (chr == '(') ? 1 : -1;
        if (pivot < 0) return false;
    }

    return pivot == 0;
}