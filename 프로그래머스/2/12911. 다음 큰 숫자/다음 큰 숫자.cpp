#include <string>
#include <vector>
#include <iostream>

using namespace std;

size_t expression(int lhs)
{
    int num = 0;
    for (int i = 7; i >= 0; i--)
        if (lhs >> i & 1) ++num;

    return num;
}

int solution(int n) {
    //14.10.15
    int answer = n;
    const int num = expression(n);

    while (true)
        if (num == expression(++answer)) break;

    return answer;
}