function solution(numbers, target) {
    var answer = 0;
    const dfs = (idx, sum) => {
        if (idx >= numbers.length) {
            if (target === sum) answer++;
            return;
        }
        dfs(idx + 1, sum + numbers[idx]);
        dfs(idx + 1, sum - numbers[idx]);
    };

    dfs(0, 0);
    return answer;
}