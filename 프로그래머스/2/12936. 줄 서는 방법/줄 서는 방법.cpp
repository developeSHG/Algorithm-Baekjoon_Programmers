#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//이 문제는 팩토리얼로 전체 경우의 수를 구하고,
//거기서 범위를 연산해서 순서를 구해야 함.
//
//문제의 예시로 설명하면
//n = 3, k = 5일 때,
//전체 경우의 수는 3!= > 6.
//
//이렇게 2마다(전체 경우의 수 / n) 숫자가 바뀜을 알 수 있다.
//2마다 숫자가 바뀌는데, k가 5면 나머지 1, 몫 2가 나온다.

long long Factorial(int n)
{
    long long ret = 1;
    for (int i = n; i > 1; --i)
        ret *= i;
    return ret;
}

void Update(int quotient, vector<int>& answer, vector<int>& nums)
{
    int temp = nums[quotient];

    answer.push_back(temp);
    nums.erase(nums.begin() + quotient);
}

vector<int> solution(int n, long long k) {
    vector<int> answer, nums;
    long long pivot, quotient, remainder;

    for (int i = 1; i <= n; ++i) nums.push_back(i);

    while (true)
    {
        pivot = Factorial(n) / n;

        remainder = k % pivot;
        quotient = k / pivot;
            
        if (remainder == 0)
        {
            // 나머지가 0이 나온 경우에는 해당 숫자의 마지막 순서.
            // 고로 현재 위치의 숫자를 제거하고, 남은 숫자들을 큰 순서대로 나열.
            // (1 4 3 2)   6

            // 나머지가 0이면 인덱스를 -1
            Update(--quotient, answer, nums);

            for_each(nums.rbegin(), nums.rend(), [&](const auto& e) {
                answer.push_back(e);
            });

            break;
        }
        else if (remainder == 1)
        {
            // 나머지는 1로 몫의 값 순서에서 첫 번째가 된다.
            // 남은 숫자들을 작은 순서대로 나열
            // (1 2 3 4)   1

            Update(quotient, answer, nums);

            for_each(nums.begin(), nums.end(), [&](const auto& e) {
                answer.push_back(e);
            });
            break;
        }

        // 나머지가 0이나 1이 아닌 경우에는 n과k를 갱신하고, 위의 과정을 반복.
        // (2 1 4 3)   8

        Update(quotient, answer, nums);

        --n;
        k = remainder;
    }

    return answer;
}