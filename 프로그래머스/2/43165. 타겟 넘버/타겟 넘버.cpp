#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, const int& target, int sum, int cnt)
{
    if (numbers.size() == cnt)
    {
        if (target == sum) ++answer;
        return;
    }

    dfs(numbers, target, sum - numbers[cnt], cnt + 1);
    dfs(numbers, target, sum + numbers[cnt], cnt + 1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    return answer;
}