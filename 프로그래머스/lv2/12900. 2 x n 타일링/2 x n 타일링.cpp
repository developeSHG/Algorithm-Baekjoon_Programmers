#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp(n + 1, 1);

    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;

    return dp[n];
}