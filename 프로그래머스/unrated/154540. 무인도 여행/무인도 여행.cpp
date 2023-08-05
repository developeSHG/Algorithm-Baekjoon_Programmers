#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int x, int y, vector<vector<bool>>& visited, const vector<pair<int, int>>& dir, const vector<string>& maps)
{
    int value = maps[x][y] - '0';
    visited[x][y] = true;

    for (const auto& d : dir)
    {
        int tx = x + d.first,
            ty = y + d.second;

        if (tx < 0 || tx >= maps.size() || ty < 0 || ty >= maps[0].length()) continue;
        if (maps[tx][ty] == 'X' || visited[tx][ty]) continue;

        value += dfs(tx, ty, visited, dir, maps);
    }
    return value;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    size_t row = maps.size(), col = maps[0].length();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    const vector<pair<int, int>> dir = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    
    for (size_t x = 0; x < row; ++x)
    {
        for (size_t y = 0; y < col; ++y)
        {
            if (maps[x][y] == 'X' || visited[x][y]) continue;

            answer.emplace_back(dfs(x, y, visited, dir, maps));
        }
    }

    if (answer.empty()) answer.emplace_back(-1);
    else ::stable_sort(answer.begin(), answer.end());

    return answer;
}