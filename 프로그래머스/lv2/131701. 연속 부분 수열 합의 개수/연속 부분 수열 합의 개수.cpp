#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    vector<int> v = elements;
    set<int> s(elements.begin(), elements.end());

    for (int i = 1; i < v.size(); ++i) // 위에서 선언할 때, 길이가 1인 연속부분수열은 계산했으니 1부터 시작
    {
        for (int j = 0; j < v.size(); ++j)
        {
            v[j] += elements[(j + i) % v.size()];
            s.insert(v[j]);
        }
    }

    return s.size();
}