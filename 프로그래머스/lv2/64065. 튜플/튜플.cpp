#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    string tmp;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
            // 숫자일 경우
            tmp += s[i];

            // 10 이상의 수일 경우는 계속 숫자를 넣도록 함.
            if (s[i + 1] != ',' && s[i + 1] != '}') continue;

            // 카운팅
            m[stoi(tmp)]++;
        }
        tmp = "";
    }

    vector<pair<int, int>> vec(m.begin(), m.end());
    
    ::sort(vec.begin(), vec.end(), cmp); // 오름차순 정렬
    ::for_each(vec.begin(), vec.end(), [&](const auto& pp) { answer.push_back(pp.first); });
    
    return answer;
}