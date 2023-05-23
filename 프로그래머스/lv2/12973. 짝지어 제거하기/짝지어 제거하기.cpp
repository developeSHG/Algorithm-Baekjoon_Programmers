#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> _stack;

    for_each(&s[0], &s[0] + s.length(), [&](char& n) 
    {
        (!_stack.size() || _stack.top() != n) ? _stack.push(n) : _stack.pop();
    });

    return _stack.empty() ? 1 : 0;
}