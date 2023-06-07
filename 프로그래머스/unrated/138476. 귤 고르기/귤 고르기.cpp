#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;

    for_each(tangerine.begin(), tangerine.end(), [&](const auto& el)
    {
        m[el]++;
    });

     using pp = pair<int, int>;
    vector<pp> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [](const pp& a, const pp& b) 
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    for (const auto& num : vec) 
    {
        answer++;
        if (k > num.second) k -= num.second;
        else break;
    }
        
    return answer;
}