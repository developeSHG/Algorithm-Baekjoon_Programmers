#include <string>
#include <vector>
#include <map>

using namespace std;

void search(int x, int y, int n, int count, vector<int>& v)
{
    if (v[x] && count >= v[x]) return;
    
    v[x] = count;

    if (x + n <= y) search(x + n, y, n, count + 1, v);
    if (x * 2 <= y) search(x * 2, y, n, count + 1, v);
    if (x * 3 <= y) search(x * 3, y, n, count + 1, v);
}

int solution(int x, int y, int n) {
    if (x == y) return 0;
    
    vector<int> v(y, 0);
    search(x, y, n, 0, v);
    return !v[y] ? -1 : v[y];
}