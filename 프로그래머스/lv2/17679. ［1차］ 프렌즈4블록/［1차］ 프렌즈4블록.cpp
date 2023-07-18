#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true)
    {
        vector<vector<bool>> check(m, vector<bool>(n, true));
        vector<pair<int, int>> remove;

        for (size_t x = 0; x < m - 1; ++x)
        {
            for (size_t y = 0; y < n - 1; ++y)
            {
                if (board[x][y] == 'X') continue;

                if (board[x][y] == board[x][y + 1] &&
                    board[x][y] == board[x + 1][y] &&
                    board[x][y] == board[x + 1][y + 1])
                {
                    vector<pair<int, int>> blocks{ {x, y}, {x, y + 1}, {x + 1, y}, {x + 1, y + 1} };
                    for (size_t i = 0; i < 4; ++i)
                    {
                        const auto& block = blocks[i];
                        if (check[block.first][block.second])
                        {
                            check[block.first][block.second] = false;
                            remove.emplace_back(make_pair(block.first, block.second));
                            ++answer;
                        }
                    }
                }
            }
        }

        if (remove.empty()) break;

        for (const auto& pos : remove)
            board[pos.first][pos.second] = 'X';

        for (size_t y = 0; y < n; ++y)
        {
            for (size_t x = m - 1; x > 0; --x)
            {
                if (board[x][y] == 'X')
                {
                    int t = x;
                    while (--t >= 0)
                    {
                        if (board[t][y] != 'X')
                        {
                            auto temp = board[t][y];
                            board[t][y] = board[x][y];
                            board[x][y] = temp;
                            break;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
