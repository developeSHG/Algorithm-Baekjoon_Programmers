function solution(rows, columns, queries) {
    const arr = [...Array(rows)].map((v, r) =>
        [...Array(columns)].map((v, c) => r * columns + (c + 1))
    );
    return queries.reduce((acc, querie) => {
        const [x1, y1, x2, y2] = querie;
        const move = [x2 - x1, y2 - y1];
        const [dirX, dirY] = [
            [0, 1, 0, -1],
            [1, 0, -1, 0],
        ];

        let [x, y] = [x1 - 1, y1 - 1];
        let temp = arr[x][y],
            min = 9999999999;
        const swap = (a) => {
            const j = a;
            a = temp;
            temp = j;
            return a;
        };

        for (let i = 0; i < 4; ++i) {
            let cnt = move[(i + 1) % 2];

            while (cnt--) {
                (x += dirX[i]), (y += dirY[i]);
                arr[x][y] = swap(arr[x][y]);
                min = Math.min(min, arr[x][y]);
            }
        }
        acc.push(min);
        return acc;
    }, []);
}