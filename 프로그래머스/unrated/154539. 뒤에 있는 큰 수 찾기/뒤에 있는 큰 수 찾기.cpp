#include <string>
#include <vector>
#include <stack>

using namespace std;

using p = pair<int, int>;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<p> st;

    answer.resize(numbers.size());

    for (int i = 0; i < numbers.size(); ++i)
    {
        while (!st.empty() && st.top().second < numbers[i])
        {
            answer[st.top().first] = numbers[i];
            st.pop();
        }
        st.push(make_pair(i, numbers[i]));
    }

    while (!st.empty())
    {
        answer[st.top().first] = -1;
        st.pop();
    }

    return answer;
}   