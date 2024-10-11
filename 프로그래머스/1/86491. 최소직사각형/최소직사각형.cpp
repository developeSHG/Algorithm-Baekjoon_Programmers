#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    pair<int, int> wh(0, 0);

    for_each(sizes.begin(), sizes.end(), [&](const auto& v) {
        auto p = minmax(v[0], v[1]);
        wh.first = max(wh.first, p.first);
        wh.second = max(wh.second, p.second);
    });

    return wh.first * wh.second;
}
