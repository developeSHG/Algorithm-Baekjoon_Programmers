#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    auto dash_fold = [](int a) {
                        int sum = 0;
                        for (size_t i = 2; i <= a/2; ++i)
                            sum += (a % i == 0) ? 1 : 0;
                        return (sum % 2 == 0) && a != 1;
                    };
    
    for (size_t i = left; i <= right; ++i)
        answer += dash_fold(i) ? i : -i;
    return answer;
}