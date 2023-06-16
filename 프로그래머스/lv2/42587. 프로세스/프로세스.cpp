#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    deque<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); ++i)
        q.emplace_back(make_pair(i, priorities[i]));
    
    auto max = *max_element(q.begin(), q.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    while (true)
    {  
        auto pp = q.front();
        q.pop_front();

        if (pp.second == max.second)
        {
            ++answer;
            if (pp.first == location) break;

            max = *max_element(q.begin(), q.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        }
        else
            q.emplace_back(pp);
    }

    return answer;
}