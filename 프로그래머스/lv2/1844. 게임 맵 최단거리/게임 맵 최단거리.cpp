#include<vector>
#include<queue>
using namespace std;

/*void dfs(int x, int y, int acc, vector<vector<int>>&maps)
{
    maps[x][y] = acc;

    for (size_t i = 0; i < 4; ++i)
    {
        const auto nx = x + dir[i][0],
            ny = y + dir[i][1];

        if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size() || maps[nx][ny] == 0)
            continue;

        if (maps[nx][ny] == 1 || maps[nx][ny] > acc + 1)
            dfs(nx, ny, acc + 1, maps);
    }
}*/

using p = pair<int, int>;

int solution(vector<vector<int>> maps)
{
    int n = maps.size(), m = maps[0].size();
    const vector<vector<int>> dir = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
    queue<p> q;

    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        const int x = q.front().first, y = q.front().second;
        q.pop();

        for (size_t i = 0; i < dir.size(); ++i)
        {
            const auto nx = x + dir[i][0],
                        ny = y + dir[i][1];

            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size() || maps[nx][ny] == 0)
                continue;

            if (maps[nx][ny] == 1 || maps[nx][ny] > maps[x][y] + 1)
            {
                q.push(make_pair(nx, ny));
                maps[nx][ny] = maps[x][y] + 1;
            }

            if (maps[n - 1][m - 1] > 1)
                break;
        }
    }
    
    return maps[n - 1][m - 1] == 1 ? -1 : maps[n - 1][m - 1];
}
