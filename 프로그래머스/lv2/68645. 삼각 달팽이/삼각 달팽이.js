function solution(n) {
    const arr = [];
    let [dir, cnt, col, row] = [0, 1, -1, 0];

    while (n) {
        const colArrow = (dir === 0 ? 1 : dir === 2 ? -1 : 0);

        for (let i = 0; i < n; ++i) {
            col += colArrow;
            if (colArrow === 0) ++row;
            else if (dir === 2) --row;

            if (!arr[col]) arr[col] = [];
            else if (arr[col].length < row) arr[col] = Array.from({ length: row + 1 }, (_, i) => arr[col][i] ? arr[col][i] : 0);

            arr[col][row] = cnt++;
        }
        
        dir = ++dir % 3;
        --n;
    }
    return arr.flat();
}