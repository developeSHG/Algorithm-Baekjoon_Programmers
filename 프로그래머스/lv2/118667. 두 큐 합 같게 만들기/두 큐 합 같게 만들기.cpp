#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = ::accumulate(queue1.begin(), queue1.end(), 0),
           sum2 = ::accumulate(queue2.begin(), queue2.end(), 0);
    size_t idx1 = 0, idx2 = 0;
    int max = queue1.size() * 4;

    while (answer < max)
    {
        if (sum1 > sum2 && !queue1.empty())
        {
            queue2.emplace_back(queue1[idx1]);
            sum2 += queue1[idx1], sum1 -= queue1[idx1];
            ++idx1;
        }
        else if (sum1 < sum2 && !queue2.empty())
        {
            queue1.emplace_back(queue2[idx2]);
            sum1 += queue2[idx2], sum2 -= queue2[idx2];
            ++idx2;
        }
        else break;
        
        ++answer;
    }

    return answer >= max ? -1 : answer;
}