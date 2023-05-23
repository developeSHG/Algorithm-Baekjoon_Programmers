#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    int people{ 0 }, cnt{ 1 };
    char lastWord = words[0][0];
    
    auto res = any_of(words.begin(), words.end(), [&](const auto& str)
    {
        if (++people > n) people = 1, ++cnt;

        if (s.find(str) != s.end() || lastWord != str.front())
            return true;
        
        s.insert(str);
        lastWord = str.back();
        return false;
    });
    
    return res ? vector<int>{ people, cnt } : vector<int>{ 0, 0 };
}