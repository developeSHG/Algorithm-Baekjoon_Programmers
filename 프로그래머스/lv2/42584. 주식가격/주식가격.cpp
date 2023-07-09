#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int idx = 0; idx < prices.size(); idx++)
    {
        int cnt = 0;
        for(int idx_a = idx + 1 ; idx_a < prices.size() ; idx_a++) {
            cnt++;
            if (prices[idx] > prices[idx_a]) break;
        };

        answer.push_back(cnt);
    }
    return answer;
}