#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(long param)
{
    for (int i = 2; i <= sqrt(param); ++i)
        if (!(param % i)) return false;
    return (param > 1);
}

int solution(int n, int k) {
    int answer = 0;

    string str = "";
    while (n)
    {
        int temp = n % k;
        if (temp) str = to_string(temp) + str;
        else if (!str.empty()) answer += IsPrime(stol(str)) ? 1 : 0, str.clear();
        
        n /= k;
    }

    if (!str.empty()) answer += IsPrime(stol(str)) ? 1 : 0; // 마지막까지 남은 str
    return answer;
}
