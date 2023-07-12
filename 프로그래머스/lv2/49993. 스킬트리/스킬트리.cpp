#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    return ::accumulate(skill_trees.begin(), skill_trees.end(), 0, [&](int acc, string str) {
        size_t pos = 0;
        for (size_t i = 0; i < str.length(); ++i)
        {
            auto temp = skill.find(str[i]);

            if ((temp != string::npos && temp < pos)        // 스킬트리 순서가 차례대로 안나옴
                || (temp != string::npos && temp > pos))    // pos가 0일 경우를 고려한 조건 (BDA일 경우)
                return acc;
            else if (temp != string::npos) pos = temp + 1;
        }
        return acc + 1;
    });
}
