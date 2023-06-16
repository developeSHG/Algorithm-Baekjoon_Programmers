#include <string>
#include <vector>

using namespace std;

int dfs(int& k, vector<vector<int>>& dungeons, int idx, int answer, vector<bool>& visit)
{
    k -= dungeons[idx].back(), visit[idx] = true;

    int res = answer;
    if (answer == dungeons.size())
        return res;
    
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (visit[i] || k < dungeons[i].front()) continue;

        res = max(dfs(k, dungeons, i, answer + 1, visit), res);
        k += dungeons[i].back(), visit[i] = false;
    }

    return res;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0, origin = k;
    vector<bool> visit(dungeons.size(), false);

    for (int i = 0; i < dungeons.size(); ++i)
    {
        answer = max(dfs(k, dungeons, i, 1, visit), answer);
        k = origin, visit[i] = false;
    }

    return answer;
}