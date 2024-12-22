#include <string>
#include <vector>

using namespace std;

const int dfs(const vector<int>& numbers, const int& target, int start, int sum)
{
    if (start == numbers.size())
    {
        if (sum == target) return 1;
        return 0;
    }
    
    return dfs(numbers, target, start + 1, sum + numbers[start])
            + dfs(numbers, target, start + 1, sum - numbers[start]);
}

int solution(vector<int> numbers, int target) {
    //24.12.22
    return dfs(numbers, target, 0, 0);
}