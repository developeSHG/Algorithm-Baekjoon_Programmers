#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> a, b;
    
    std::for_each(topping.begin(), topping.end(), [&](const auto& t) { ++b[t]; });
    return std::accumulate(topping.begin(), topping.end(), 0, [&](auto acc, const auto& t) {
        ++a[t], --b[t];
        if (b[t] == 0) b.erase(t);
        return (a.size() == b.size()) ? acc + 1 : acc;
    });
}
