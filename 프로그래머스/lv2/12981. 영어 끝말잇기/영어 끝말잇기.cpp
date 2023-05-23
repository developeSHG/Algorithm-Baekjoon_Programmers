#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    int cnt{ 0 };
    
    auto res = any_of(words.begin(), words.end(), [&](const auto& str)
    {
        const auto& lastWord = cnt ? words[cnt - 1].back() : words[0].front();
        if (s.find(str) != s.end() || lastWord != str.front())
            return true;
 
        s.insert(str), ++cnt;
        return false;
    });
    
    return res ? vector<int>{ cnt % n + 1, cnt / n + 1 } : vector<int>{ 0, 0 };
}