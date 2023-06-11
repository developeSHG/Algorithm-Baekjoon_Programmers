#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬

    // 인덱스가 값보다 크다면, 그 전 인덱스를 리턴
    for (int i = 0; i < citations.size(); ++i)
    {
        if (i + 1 > citations[i]) return i;
    }
    
    return citations.size();
}
