#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 25.02.14
    vector<int> answer(numbers.size());
    stack<int> stk;

    for (int i = numbers.size() - 1; i >= 0; i--) {
     
        while (true)
        {
            if (stk.empty())
            {
                answer[i] = -1;
                break;
            }
            if (numbers[stk.top()] > numbers[i]) {
                answer[i] = numbers[stk.top()];
                break;
            }
            else {
                stk.pop();
            }
        }
        stk.push(i);
    }
    
    

    return answer;
}