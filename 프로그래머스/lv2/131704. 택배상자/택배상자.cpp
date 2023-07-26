#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> q(order.begin(), order.end());

   for (size_t i = 0; i < order.size();)
    {
        const auto find = order[i];

        if (find < q.top() && !s.empty() && find != s.top()) break;

        if (!s.empty() && find == s.top()) s.pop(), ++i, ++answer;
        else if (find == q.top()) q.pop(), ++i, ++answer;
        else
        {
            if (find > q.top())
            {
                s.push(q.top());
                q.pop();
            }
        }
    }

    return answer;
}