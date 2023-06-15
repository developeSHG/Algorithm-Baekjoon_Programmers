#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;

    for_each(clothes.begin(), clothes.end(), [&](const auto& v) { ++m[v[1]]; });

    for (auto& e : m) answer *= (e.second + 1); // 아무것도 안입은 경우가 있어서 + 1
    return --answer;
}