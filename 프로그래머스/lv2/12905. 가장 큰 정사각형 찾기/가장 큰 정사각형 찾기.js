function solution(board) {
    return board.reduce((acc, rows, i, board) => {
        if (rows.length <= 1) return 1;
        if (!i) return acc;

        rows.forEach((column, j) => {
            if (!j) return;

            if (column) {
                board[i][j] = Math.min(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1;
                acc = Math.max(acc, board[i][j]);
            }
        });

        return i !== board.length - 1 ? acc : acc * acc;
    }, 0);
}