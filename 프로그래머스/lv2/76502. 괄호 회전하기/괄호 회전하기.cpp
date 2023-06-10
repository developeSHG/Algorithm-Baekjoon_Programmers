#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        string temp = s;
        stack<char> st;

        int start = iter - s.begin();
        temp.erase(0, start);
        temp += s.substr(0, start);

        for (const auto word : temp)
        {
            if (st.empty())
                st.push(word);
            else if ((st.top() == '[' && word == ']')
                || (st.top() == '(' && word == ')')
                || (st.top() == '{' && word == '}'))
                st.pop();
            else if (word == ']' || word == ')' || word == '}') break;
            else st.push(word);
        };

        if (st.empty())
            ++answer;
    }

    return answer;
}