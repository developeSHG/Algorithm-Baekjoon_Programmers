#include <string>
#include <unordered_map>
#include <set>
using namespace std;

#define POS 5

bool move(int& x, int& y, int moveX, int moveY)
{
    if (x + moveX < -POS || x + moveX > POS 
        || y + moveY < -POS || y + moveY > POS)
        return false;

    x += moveX;
    y += moveY;
    return true;
}

int solution(string dirs) {
    int answer = 0, x = 0, y = 0;
    enum { U, D, R, L };
    int dirX[] = { 0, 0, 1, -1 },
        dirY[] = { 1, -1, 0, 0 };
    unordered_map<int, set<int>> m;

    for (size_t i = 0; i < dirs.length(); ++i)
    {
        int dirIdx = -1, prevIdx = -1;

        if (dirs[i] == 'U') dirIdx = U, prevIdx = D;
        else if (dirs[i] == 'D') dirIdx = D, prevIdx = U;
        else if (dirs[i] == 'R') dirIdx = R, prevIdx = L;
        else if (dirs[i] == 'L') dirIdx = L, prevIdx = R;

        const int prevID = x * 100 + y; // 자신만의 이전 인덱스 고유 ID
        if (move(x, y, dirX[dirIdx], dirY[dirIdx]))
        {
            const int newID = x * 100 + y; // 자신만의 새로운 인덱스 고유 ID
            if (m.find(prevID) != m.end()
                && m[prevID].find(dirIdx) != m[prevID].end())
                continue;

            m[prevID].insert(dirIdx); // prev -> new 방향
            m[newID].insert(prevIdx); // new -> prev 방향
            ++answer;
        }
    }
    return answer;
}