const solution = (arr) => {
    return (quadTree = (arr, y, x, n, result) => {
        for (let i = y; i < y + n; ++i) {
            for (let j = x; j < x + n; ++j) {
                if (arr[y][x] !== arr[i][j]) {
                    n = Math.floor(n / 2);
                    for (let q = 0; q < 4; ++q) {
                        const [ny, nx] = [
                            q >= 2 ? y + n : y,
                            q % 2 ? x + n : x,
                        ];
                        result = quadTree(arr, ny, nx, n, result);
                    }
                    return result;
                }
            }
        }
        return arr[y][x] === 0
            ? [result[0] + 1, result[1]]
            : [result[0], result[1] + 1];
    })(arr, 0, 0, arr.length, [0, 0]);
};
