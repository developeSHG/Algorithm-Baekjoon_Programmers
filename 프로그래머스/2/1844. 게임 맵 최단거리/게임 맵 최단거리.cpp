#include<vector>
#include<queue>
using namespace std;

struct POS
{
    POS(int _x, int _y) 
        : x(_x), y(_y)
    {
    }
    POS operator+(const POS &p) const
    {
        return POS(x + p.x, y + p.y);
	}
    
    int x;
    int y;
};

__inline bool PosCheck(POS newPos, int n, int m)
{
    return (newPos.x > -1 && newPos.x < n) && (newPos.y > -1 && newPos.y < m);
}

void BFS(const vector<vector<int>>& maps, vector<vector<int>>& distance, POS player)
{
    queue<POS> q;
    int n = maps.size(), m = maps[0].size();
    vector<POS> movement = 
    {
        POS(-1, 0),
        POS(1, 0),
        POS(0, -1),
        POS(0, 1)
    };
    
    q.push(player);
    
    while(!q.empty())
    {
        POS curPos = q.front();
        q.pop();
        
        for (const auto& movePos : movement)
        {
            auto newPos = curPos + movePos;
            if (PosCheck(newPos, n, m) && maps[newPos.x][newPos.y] == 1) 
            {
                if (distance[newPos.x][newPos.y] > distance[curPos.x][curPos.y] + 1 
                    || distance[newPos.x][newPos.y] == -1)
                {
                    distance[newPos.x][newPos.y] = distance[curPos.x][curPos.y] + 1;
                    q.push(newPos);
                }        
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    //24.12.22
    vector<vector<int>> distance(maps.size(), vector<int>(maps[0].size(), -1));
    POS player(0, 0);
    
    distance[player.x][player.y] = 1;
    
    BFS(maps, distance, player);
    
    return distance.back().back();
}