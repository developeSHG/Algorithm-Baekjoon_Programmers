const solution = (arr) => {
    return (quadTree = (arr, y, x, n, result) => {
        for (let i = y; i < y + n; ++i) {
            for (let j = x; j < x + n; ++j) {
                if (arr[y][x] !== arr[i][j]) {
                    n = Math.floor(n / 2);
                    for (let [ny, nx] of [[y, x], [y, x + n], [y + n, x], [y + n, x + n]]) result = quadTree(arr, ny, nx, n, result);
                    return result;
                }
            }
        }

        return arr[y][x] === 0
            ? [result[0] + 1, result[1]]
            : [result[0], result[1] + 1];
    })(arr, 0, 0, arr.length, [0, 0]);
};
