#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    // 24.12.18
    int answer = 0;
    while(storey)
    {
        int n = storey % 10;
        storey /= 10;
        
        bool isUp = (n == 5 && storey % 10 >= 5) || (n > 5);  
        answer += isUp ? (10 - n) : n; 
        storey += isUp ? 1 : 0;
    }
    return answer;
}