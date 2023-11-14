#include <string>
#include <vector>

using namespace std;

enum EDIR
{
    RIGHT,
    DOWN,
    LEFT,
    UP,
    END
};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board;
    const int move[EDIR::END][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    int cnt = 1;
    for (int i = 0; i < rows; i++)
    {
        std::vector<int> v;
        for (int j = 0; j < columns; j++) v.push_back(cnt++);
        board.push_back(v);
    }

    for (const auto& pos : queries)
    {
        int start[] = { pos[0], pos[1] };
        int temp = board[start[0] - 1][start[1] - 1], resMin = 99999;

        for (int dir = static_cast<int>(EDIR::RIGHT); dir < EDIR::END; ++dir)
        {
            while (true)
            {
                int nPos[] = { start[0] + move[dir][0], start[1] + move[dir][1] };

                if (nPos[0] < pos[0] || nPos[0] > pos[2] || nPos[1] < pos[1] || nPos[1] > pos[3])
                    break;

                for (int i = 0; i < 2; ++i)
                    start[i] += move[dir][i];

                swap(temp, board[nPos[0] - 1][nPos[1] - 1]);
                resMin = min(temp, resMin);
            }
        }
        answer.push_back(resMin);
    }

    return answer;
}