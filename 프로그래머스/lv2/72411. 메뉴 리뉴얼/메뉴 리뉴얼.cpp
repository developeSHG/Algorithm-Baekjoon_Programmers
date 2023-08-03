#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void combination(set<string>& set, const string& str, string res, int r, int next) {
    if (res.length() == r) {
        set.insert(res);
        return;
    }

    for (int i = next; i < str.length(); i++) {
        res += str[i];
        combination(set, str, res, r, i + 1);
        res.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (const auto& combi : course)
    {
        set<string> set; // 중복 단어 필터링하기 위해 set 사용

        // course에 맞게 단어 조합
        for (auto& str : orders)
        {
            ::sort(str.begin(), str.end());
            combination(set, str, "", combi, 0);
        }

        size_t maxCnt = 0;
        vector<string> temp;

        // 조합된 단어가 orders에 2개 이상있는지 체크
        for (auto combiStr : set) 
        {
            size_t cnt = 0;

            for (const auto& str : orders)
            {
                bool check = true;
                for (const auto& word : combiStr)
                {
                    if (str.find(word) == std::string::npos) {
                        check = false;
                        break;
                    }
                }

                if (check) ++cnt;
            }

            if (cnt >= 2 && maxCnt <= cnt)
            {
                if (maxCnt < cnt) 
                    maxCnt = cnt, temp.clear();

                temp.emplace_back(combiStr);
            }
        }

        answer.insert(answer.end(), temp.begin(), temp.end());
    }

    ::sort(answer.begin(), answer.end());
    
    return answer;
}