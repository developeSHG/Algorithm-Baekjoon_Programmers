#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    //24.10.15
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for_each(scoville.begin(), scoville.end(), [&](auto p) { pq.emplace(p); });
    while (!pq.empty() && pq.size() >= 2)
    {
        if (pq.top() >= K) break;
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        auto newK = a + b * 2;
        pq.emplace(newK);
        ++answer;
    }
    return pq.top() < K ? -1 : answer;
}