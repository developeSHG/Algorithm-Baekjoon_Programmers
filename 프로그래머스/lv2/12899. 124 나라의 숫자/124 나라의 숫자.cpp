#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "", str = "412";
    bool three = (n % 3 == 0);
    n -= three ? 1 : 0;

    while (n)
    {
        answer = str[n % 3] + answer;
        if (n % 3 == 0) --n;
        n = n / 3;
    }

    if (three) answer.back() = '4';
    return answer;
}