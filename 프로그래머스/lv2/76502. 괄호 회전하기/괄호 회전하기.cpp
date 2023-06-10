#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        string temp = s;
        stack<char> st; // 후입선출로 괄호가 올바른지 체크

        int start = iter - s.begin(); // iter에서 begin과의 차이가 회전시킬 문자의 수
        temp.erase(0, start); // 앞에서부터 삭제
        temp += s.substr(0, start); // 맨 뒤에 붙여줌

        for (const auto word : temp)
        {
            if (st.empty())
                st.push(word);
            else if ((st.top() == '[' && word == ']')
                || (st.top() == '(' && word == ')')
                || (st.top() == '{' && word == '}'))
                st.pop();
            else if (word == ']' || word == ')' || word == '}') break; // 닫는 괄호일 경우, 뒤에 더이상 체크할 필요가 없어서 break;
            else st.push(word);

        };

        if (st.empty()) // 비어있으면 올바르다고 판단
            ++answer;
    }

    return answer;
}