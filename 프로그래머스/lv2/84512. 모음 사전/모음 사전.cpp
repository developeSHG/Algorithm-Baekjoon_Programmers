#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<char> v = { 'A', 'E', 'I', 'O', 'U' };

    for (int i = 0; i < word.length(); ++i)
    {
        int cnt = 0, sum = 0;
        while (cnt < 5 - i)
            sum += pow(5, cnt++);

        auto idx = find(v.begin(), v.end(), word[i]) - v.begin();
        answer += sum * idx + 1;
    }

    return answer;
}