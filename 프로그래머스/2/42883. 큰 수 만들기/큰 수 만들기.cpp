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
        // end에서 구해야 할 남은 개수만큼 뺀 영역까지 최대 값 도출
        auto temp = max_element(number.begin() + start, number.end() - cnt + answer.length() + 1);

        // start를 새롭게 갱신
        answer += *temp, start = temp - number.begin() + 1;
    }
    
    return answer;
}