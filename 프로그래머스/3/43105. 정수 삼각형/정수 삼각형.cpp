#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    //24.10.21
    vector<vector<int>> dp{ triangle.front() };
    dp.resize(triangle.size());

    for (int i = 1; i < triangle.size(); ++i)
    {
        dp[i].resize(triangle[i].size());
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i].back() = dp[i - 1].back() + triangle[i].back();

        for (int j = 1; j < triangle[i].size() - 1; ++j)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    }

    return *max_element(dp.back().begin(), dp.back().end());
}