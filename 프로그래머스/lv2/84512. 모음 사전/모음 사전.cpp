#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<char> v = { 'A', 'E', 'I', 'O', 'U' };
    
    // 각 자리는 이전 자리들의 가중치 [ 5^4, 5^3, 5^2, 5^1, 5^0 ] 를 가짐.
    // 따라서 AAE 에서 'E' 는 이전 자리수 52 + 51 + 50 = 31 의 가중치를 가지는데
    // E 는 [ 'A', 'E', 'I', 'O', 'U' ] 에서 두번째(인덱스로는 1) 을 이기 때문에
    // [ 31 * index + 1 ] 의 정보를 가진다.
    // 여기서 +1 을 하는 이유는 단어의 누적, A가 항상 +1 정보를 누적하는 것에서 영감
    // "I"(1563) 를 한번 공식으로 풀어보면,
    // (5^4 + 5^3 + 5^2 + 5^1 + 5^0 ) * 2 + 1 = ( 625 + 125 + 25 + 5 + 1 ) * 2 + 1 = 781 * 2 + 1 = 1563

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