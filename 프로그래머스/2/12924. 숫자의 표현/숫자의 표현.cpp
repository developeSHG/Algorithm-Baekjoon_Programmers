#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 24.10.14
    int answer = 0;
    int lVal = 0, rVal = 0, sum = 0;
    
    while (true)
    {
        (sum <= n) ? ++rVal : ++lVal;
        sum += (sum <= n) ? rVal : -lVal;
        if (sum == n) 
            ++answer;
        
        if (lVal == n) break;
    }

    return answer;
}