#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string s)
{
    //24.10.15
    int answer = -1;
    stack<char> st;
    
    for_each(s.begin(), s.end(), [&](const auto& ch) {
        if (st.empty() || st.top() != ch) st.push(ch);
        else st.pop();
    });
    
    return st.empty() ? 1 : 0;
}