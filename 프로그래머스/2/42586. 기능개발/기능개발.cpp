#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    //24.10.15
    vector<int> answer;
    int d = 0;

    for(size_t i = 0; i < progresses.size(); ++i)
    {
        const auto day = ceil(float(100 - progresses[i]) / speeds[i]);
        if (d >= day)
            ++answer.back();
        else
        {
            d = day;
            answer.emplace_back(1);
        }
    }

    return answer;
}