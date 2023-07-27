#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0, cnt = number.length() - k;

    while (answer.length() != cnt)
    {
        auto temp = max_element(number.begin() + start, number.end() - cnt + answer.length() + 1);
        answer += *temp;
        start = temp - number.begin() + 1;
    }
    
    return answer;
}