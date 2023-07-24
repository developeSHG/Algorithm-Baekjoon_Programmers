#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

void permutation(string& numbers, set<int>& s, string str, int r) {
    if (!str.empty()) s.emplace(stoi(str));

    if (r == numbers.length()) return;
    
    for (size_t i = r; i < numbers.length(); ++i)
    {
        ::swap(numbers[i], numbers[r]);
        permutation(numbers, s, str + numbers[r], r + 1);
        ::swap(numbers[i], numbers[r]);
    }
}

bool isprime(int n)
{
    if (n <= 1) return false;

    for (int i = 2; i <= sqrtf(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    set<int> s;

    permutation(numbers, s, "", 0);
    return ::accumulate(s.begin(), s.end(), 0, [](const auto& acc, const auto& n) {
        return acc + (isprime(n) ? 1 : 0);
    });
}
