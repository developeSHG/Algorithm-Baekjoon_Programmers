#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const int Get_N(int N, int idx)
{
    int result = N;
    for (int i = 0; i < idx; ++i)
        result = result * 10 + N;
    return result;
}

int solution(int N, int number) {
    //24.10.25
    vector<unordered_set<int>> dp(8);

    for (int k = 0; k < 8; ++k)
    {
        dp[k].insert(Get_N(N, k));

        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (i + j + 1 != k) continue;

                for (const auto& a : dp[i])
                {
                    for (const auto& b : dp[j])
                    {
                        dp[k].insert(a + b);

                        if (a - b > 0) dp[k].insert(a - b);

                        dp[k].insert(a * b);

                        if (a / b > 0) dp[k].insert(a / b);
                    }
                }
            }
        }

        if (dp[k].find(number) != dp[k].end()) return k + 1;
    }
    return -1;
}