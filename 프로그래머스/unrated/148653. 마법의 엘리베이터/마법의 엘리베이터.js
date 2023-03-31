function solution(storey) {
    storey = storey.toString();
    let result = Infinity;

    (dfs = (pivot, acc, add) => {
        if (pivot < 0) {
            result = Math.min(result, acc + add);
            return result;
        }

        const num = parseInt(storey[pivot]) + add;
        dfs(pivot - 1, acc + num, 0);
        dfs(pivot - 1, acc + 10 - num, 1);
    })(storey.length - 1, 0, 0);
    return result;
}