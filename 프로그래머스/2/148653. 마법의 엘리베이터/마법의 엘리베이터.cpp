#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> v;

    auto str = to_string(storey);
    for (const auto& element : str)
        v.push_back(element - '0');

    int order = v.size() - 1;
    while (order)
    {
        int type = 0;

        vector<int> v_case =
        {
            v[order] + v[order - 1],
            v[order] + 10 - (v[order - 1] + 1),
            10 - v[order] + v[order - 1] + 1,
            10 - v[order] + 10 - (v[order - 1] + 1)
        };

        const auto& iter = min_element(v_case.begin(), v_case.end());
        if (*iter == v_case[0] || *iter == v_case[1]) answer += v[order];
        else answer += 10 - v[order];
               
        if (*iter == v_case[2] || *iter == v_case[3])
        {
            int temp = order - 1;
            do
            {
                ++v[temp];
                if (v[temp] >= 10)
                {
                    v[temp] = 0;
                    --temp;
                    
                    if (temp < 0) ++answer;
                }
                else break;
            } while (temp >= 0);
        }

        --order;
    }

    answer += min(10 - v[0] + 1, v[0]);
    
    return answer;
}