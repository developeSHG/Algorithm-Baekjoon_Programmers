#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    return ::accumulate(numbers.begin(), numbers.end(), vector<long long>(), [&](auto acc, const auto& number) {
        // 공식 (짝수도 동일)
        // 3 = 011 (마지막 1의 개수 2개)
        // 4 = 100
        // 5 = 101 (3 + (2 * *(1의 개수 - 1))) = (3 + (2 * *(2 - 1))) = 5

        long long n = 0, temp = number;
        while (temp % 2)
            ++n, temp /= 2;
        
        if (n == 0) n = 1; // n이 0이면 짝수인 경우인데, 무조건 +1은 해야하니까 n = 1

        acc.emplace_back(number + pow(2, n - 1));
        return acc;
    });
}