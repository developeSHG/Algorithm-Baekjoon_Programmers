#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "", str = "412";

    while (n)
    {
        answer = str[n % 3] + answer;
        if (n % 3 == 0) --n; // 3인 경우는 4로 표현하기 때문에 -1
        n = n / 3;
    }

    return answer;
}