#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string solution(vector<int> numbers) {
    //24.10.17
    string answer;

    sort(numbers.begin(), numbers.end(), [&](const auto& lhs, const auto& rhs) {
        return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
    });
    for (const auto& n : numbers) answer += to_string(n);
    
    return answer < "1" ? "0" : answer;
}