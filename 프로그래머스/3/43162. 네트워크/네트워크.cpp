#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int here, const vector<vector<int>>& computers)
{
    visited[here] = true;
    
    for (int i = 0; i < computers.size(); ++i)
    {
        if (!visited[i] && computers[here][i])
            dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    //24.10.23
    int answer = 0;
    visited.resize(n);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, computers);
            ++answer;
        }
    }
    return answer;
}