#include <string>
#include <vector>

using namespace std;

int bit1_number(int n)
{
    int cnt = 0;

    while (n)
    {
        int remain = (n % 2);
        n /= 2;
        cnt += (remain == 1) ? 1 : 0;
    }
    return cnt;
}

int solution(int n) {
    int result = bit1_number(n);
    while (result != bit1_number(++n));
    return n;
}
