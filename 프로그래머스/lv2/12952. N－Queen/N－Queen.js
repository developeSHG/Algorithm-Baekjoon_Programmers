function solution(n) {
    const NOT_VISITED = 100;
    let [answer, chess] = [0, Array(n).fill(NOT_VISITED)];

    const isAvailable = (row, col) => {
        if (chess[col] !== NOT_VISITED) return false;
        for (let idx = 0; idx < n; idx++) {
            if (Math.abs((row - chess[idx]) / (col - idx)) === 1) return false;
        }
        return true;
    };

    (dfs = (row) => {
        if (row === n) ++answer;
        else {
            for (let col = 0; col < n; ++col) {
                if (isAvailable(row, col)) {
                    chess[col] = row;
                    dfs(row + 1);
                    chess[col] = NOT_VISITED;
                }
            }
        }
    })(0);

    return answer;
}