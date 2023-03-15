function solution(rows, columns, queries) {
    const arr = [...Array(rows)].map((v, r) =>
        [...Array(columns)].map((v, c) => r * columns + (c + 1))
    ); // 먼저 2차원 배열에 값을 초기화한다.
    return queries.reduce((acc, querie) => {
        const [x1, y1, x2, y2] = querie;
        const move = [x2 - x1, y2 - y1]; // 이동할 x의 길이, y의 길이
        const [dirX, dirY] = [ // 시계방향 순
            [0, 1, 0, -1],
            [1, 0, -1, 0],
        ];

        let [x, y] = [x1 - 1, y1 - 1]; // 2차원 배열상에서의 x, y 인덱스
        let temp = arr[x][y], min = Infinity;
        const swap = (a) => {
            const j = a;
            a = temp;
            temp = j;
            return a;
        };

        for (let i = 0; i < 4; ++i) {
            let cnt = move[(i + 1) % 2]; // 시계방향 순으로 y먼저 이동할 것이기 때문에, i에 +1

            while (cnt--) { // 이동할 카운트가 0이 될때까지 반복
                (x += dirX[i]), (y += dirY[i]); // 현재 위치에서 시계방향순으로 새로운 위치를 갱신
                arr[x][y] = swap(arr[x][y]); // 이전 위치의 값과 현재의 값을 swap
                min = Math.min(min, arr[x][y]); // 가장 낮은 값으로 갱신
            }
        }
        acc.push(min);
        return acc;
    }, []);
}