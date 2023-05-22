#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp = { 0, 1 };
    dp.resize(n + 1);

    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
        
    return dp[n];
}
