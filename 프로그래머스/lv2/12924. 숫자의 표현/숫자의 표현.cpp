#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // 자기자신 + 1

    // 두 개의 반복문을 이용해 연속된 숫자로 n이 되면 ++answer로 증가.
    for (int i = 1; i <= (n / 2); ++i)
    {
        int sum = i;
        for (int j = i + 1; j < n; ++j)
        {
            sum += j;
            if (sum == n) ++answer;
            else if (sum > n) break; // 연속된 숫자의 합이 n보다 커질경우, 반복문 종료
        }
    }
    return answer;
}