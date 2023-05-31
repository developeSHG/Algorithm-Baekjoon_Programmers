#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Command
{
public:
    Command(const int& a, const int& b)
        : _a(min(a, b)), _b(max(a, b))
    {
       
    }
    const bool operator() ()
    {
        return (_a % 2) && !(_b % 2) && (_b - _a == 1);
    }

public:
    void vs()
    {
        _a = ceil(_a / 2.f);
        _b = ceil(_b / 2.f);
    }

private:
    int _a;
    int _b;
};

int solution(int n, int a, int b)
{
    int answer = 1;

    Command cmd(a, b);
    while (!cmd())
    {
        cmd.vs();
        ++answer;
    }

    return answer;
}