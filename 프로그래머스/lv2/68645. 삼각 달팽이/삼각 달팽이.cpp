#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> vec;
    const size_t size = n * (n + 1) / 2;    // n = 4 => 1+2+3+4 = 10
    size_t row = 0, col = 0, count = 1;

    /*
        n = 4 일 때 다음 배열을 먼저 생성
        [
          [0],
          [0, 0],
          [0, 0, 0],
          [0, 0, 0, 0],
        ]
    */
    vec.resize(n);
    for (size_t i = 0; i < n; ++i) 
        vec[i].resize(i + 1);

    while (count <= size)
    {
        // down
        {
            while (row < n && col < n && !vec[row][col])
                vec[row][col] = count++, ++row;

            --row, ++col; // 다음 좌표로 이동
        }

        // right
        {
            while (row < n && col < n && !vec[row][col])
                vec[row][col] = count++, ++col;

            col -= 2, --row; // 다음 좌표로 이동
        }

        // left diagonal
        {
            while (row < n && col < n && !vec[row][col])
                vec[row][col] = count++, --row, --col;

            row += 2, ++col; // 다음 좌표로 이동
        }
    }

    return ::accumulate(vec.begin(), vec.end(), vector<int>(), [&](auto& acc, const auto& v) {
        acc.insert(acc.end(), v.begin(), v.end());
        return acc;
    });
}