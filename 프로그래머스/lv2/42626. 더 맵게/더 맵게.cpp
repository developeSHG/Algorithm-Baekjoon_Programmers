#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    for (const auto& e : scoville) q.push(e);

    int first, second, result;
    while (true) {
        if (q.top() >= K) break;
        else if (q.size() <= 1) return -1;
        else {
            first = q.top(); q.pop();
            second = q.top(); q.pop();
            result = first + (second * 2);

            q.push(result), answer++;
        }
    }
    return answer;
}