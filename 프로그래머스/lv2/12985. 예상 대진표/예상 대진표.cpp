#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Command
{
public:
    Command(const int& a, const int& b)
        : _a(a), _b(b)
    {
       
    }
    const bool operator() ()
    {
        return _a != _b;
    }

public:
    void vs()
    {
        _a = (_a + 1) >> 1;
        _b = (_b + 1) >> 1;
    }

private:
    int _a;
    int _b;
};

int solution(int n, int a, int b)
{
    int answer = 0;

    Command cmd(a, b);
    while (cmd())
    {
        cmd.vs();
        ++answer;
    }

    return answer;
}