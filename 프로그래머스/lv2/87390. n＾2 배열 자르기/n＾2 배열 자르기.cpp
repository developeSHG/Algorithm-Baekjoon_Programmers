#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    // 굳이 2차원 배열을 만들어서 모든 값을 초기화할 필요는 없다.
    // left와 right 까지의 필요한 공간만을 n으로 행열을 계산해서 도출할 수 있다.
    for (long i = left; i <= right; ++i) // 제한사항의 데이터 유효범위로 인해 변수 type을 int가 아닌 long 사용
    {
        // +1을 다 해주는 이유는 프로그래밍상에선 0부터 시작이니 +1
        auto a = i / n + 1; // 행
        auto b = i % n + 1; // 열

        // a > b : 해당 행과 열이 가져야 하는 최소값보다 낮다는 것이니 행을 대입
        answer.push_back((a > b) ? a : b); 
    }

    return answer;
}