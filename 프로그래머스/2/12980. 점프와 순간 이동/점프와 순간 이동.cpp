#include <iostream>
using namespace std;

int solution(int n)
{
    // 24.10.17
    int ans = 0;
    while(n)
    {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}