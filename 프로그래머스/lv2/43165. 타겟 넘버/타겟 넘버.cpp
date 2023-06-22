#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, const int& target, int order, int res, int answer) {
    if (order >= numbers.size())
        return (res == target) ? answer + 1 : answer;

    answer = dfs(numbers, target, order + 1, res + numbers[order], answer);
    answer = dfs(numbers, target, order + 1, res - numbers[order], answer);
    
    return answer;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0, 0);
}