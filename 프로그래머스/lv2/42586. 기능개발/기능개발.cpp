#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = 0;

    for (auto iter = progresses.begin(); iter != progresses.end(); ++iter)
    {
        int speed = speeds[iter - progresses.begin()];
        int time = ceil((100 - *iter) / static_cast<float>(speed));

        if (day == 0) day = time;

        if (answer.empty() || day < time)
        {
            answer.emplace_back(1);
            day = time;
        }
        else ++answer.back();
    }

    return answer;
}