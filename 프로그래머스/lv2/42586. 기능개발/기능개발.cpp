#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = 0;
    int sum = 0;

    for (auto iter = progresses.begin(); iter != progresses.end(); ++iter)
    {
        int speed = speeds[iter - progresses.begin()];
        int time = ceil((100 - *iter) / static_cast<float>(speed));

        if (day == 0) day = time;

        if (day < time)
        {
            answer.emplace_back(sum);
            day = time;
            sum = 1;
        }
        else ++sum;
    }
    answer.emplace_back(sum);

    return answer;
}