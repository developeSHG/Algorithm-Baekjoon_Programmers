#include <string>
#include <vector>

using namespace std;

typedef struct _POS
{
    size_t x;
    size_t y;
} POS;

class QurdTree
{
public:
    QurdTree(POS pos, size_t cnt)
        : _pos(pos), _cnt(cnt)
    {
    }
    void operator()(const vector<vector<int>>& arr, vector<int>& answer, const QurdTree& root)
    {
        const auto pivot = arr[root.GetPos().x][root.GetPos().y];
        const int itv = root.GetCnt() / 2;

        for (size_t i = 0; i < _cnt; ++i)
        {
            for (size_t j = 0; j < _cnt; ++j)
            {
                if (pivot != arr[i + _pos.x][j + _pos.y])
                {
                    QurdTree qt1(POS{ root.GetPos().x, root.GetPos().y }, itv);
                    qt1(arr, answer, qt1);
                    QurdTree qt2(POS{ root.GetPos().x + itv, root.GetPos().y }, itv);
                    qt2(arr, answer, qt2);
                    QurdTree qt3(POS{ root.GetPos().x, root.GetPos().y + itv }, itv);
                    qt3(arr, answer, qt3);
                    QurdTree qt4(POS{ root.GetPos().x + itv, root.GetPos().y + itv }, itv);
                    qt4(arr, answer, qt4);

                    return;
                }
            }
        }

        ++answer[pivot];
    }

    const POS GetPos() const { return _pos; }
    const size_t GetCnt() const { return _cnt; }

private:
    POS _pos;
    size_t _cnt;
};

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0, 0 };
    
    QurdTree qt(POS{ 0, 0 }, arr.size());
    qt(arr, answer, qt);

    return answer;
}