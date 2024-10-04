#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer{x};
    
    for(size_t i = 1; i < n; ++i)
        answer.emplace_back(answer.back() + x);
    return answer;
}