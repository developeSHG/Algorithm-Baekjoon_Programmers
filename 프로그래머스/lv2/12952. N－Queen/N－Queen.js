function solution(n) {
    const NOT_VISITED = 100; // 현재 열의 어느행에도 퀸이 놓여지지 않았음을 표시
    let [answer, chess] = [0, Array(n).fill(NOT_VISITED)];

    const isAvailable = (row, col) => {
        // [세로검사]
        // 1차원 배열 상에서 현재 접근한 인덱스(열)의 값이 비어있지 않다면,
        // 즉 NOT_VISITED 가 아닌 다른 값이 있다면 이미 퀸이 놓였다는 의미이다.
        if (chess[col] !== NOT_VISITED) return false;

        // [대각선 검사]
        // 1차원 배열의 모든 값에 대해 현재 위치를 기준으로 기울기를 비교한다.
        // 직선의 기울기가 절댓값으로 1이면 대각선에 퀸이 놓여있다는 의미이다.
        for (let idx = 0; idx < n; idx++) {
            if (Math.abs((row - chess[idx]) / (col - idx)) === 1) return false;
        }

        // 여기서 [가로 검사]는 하지 않았다.
        // dfs 함수를 보면 현재 위치에서 퀸을 놓을 수 있으면 다음 행을 검사하면 되기 때문에
        // row + 1 을 매개변수로 넘기고 있다.
        // 즉, row 값은 이전 값이 저장되지 않으면 그 이상의 값은 저장되지 않기 때문에
        // 별도로 가로 검사를 하지 않아도 되는 것이다.

        return true;
    };

    (dfs = (row) => {
        if (row === n) ++answer;
        else {
            for (let col = 0; col < n; ++col) {
                if (isAvailable(row, col)) { // 퀸을 놓을 수 있는지 확인
                    chess[col] = row;
                    dfs(row + 1);
                    chess[col] = NOT_VISITED;
                }
            }
        }
    })(0);

    return answer;
}