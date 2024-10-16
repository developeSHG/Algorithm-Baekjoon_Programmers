#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    //24.10.17    
    sort(citations.rbegin(), citations.rend());
    int h = citations.front();
    int idx = 0, cnt = 0;

    while(h)
    {
        if (citations[idx] >= h)
        {
            ++cnt;
            ++idx;
        }
        if (h <= cnt) break;
        --h;
    }

    return h;
}