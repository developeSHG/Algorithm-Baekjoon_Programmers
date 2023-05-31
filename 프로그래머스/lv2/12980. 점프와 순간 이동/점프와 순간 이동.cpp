#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;

    // 이진법에서 1의 수가 총 점프 수.
    while (n / 2)
    {
        if (n % 2) // 홀수일 경우
        {
            --n;
            ++ans;
        }
        n /= 2;
    }

    return ans;
}