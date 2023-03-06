function solution(m, n, board) {
    const dirX = [0, 1, 1, 0],    // 시계 방향
        dirY = [0, 0, 1, 1];

    board = board.map((v) => v.split(""));

    do {
        const remove = [];

        for (let i = 0; i < m - 1; ++i) {
            for (let j = 0; j < n - 1; ++j) {
                if (board[i][j] === 0) continue;

                const checkBlocks = Array.from({ length: dirX.length }, (_, idx) => [i + dirY[idx], j + dirX[idx]]);
                if (checkBlocks.every(([x, y]) => board[x][y] === board[i][j])) checkBlocks.forEach(([x, y]) => remove.push([x, y]));
            }
        }

        if (!remove.length) break;

        remove.forEach(([x, y]) => board[x][y] = 0);

        for (let i = m - 1; i > 0; --i) {
            if (!board[i].some((e) => !e)) continue;

            for (let j = 0; j < n; ++j) {
                for (let k = i - 1; k >= 0 && !board[i][j]; --k) {
                    if (board[k][j]) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    } while (true)

    return [].concat(...board).filter((e) => !e).length;
}