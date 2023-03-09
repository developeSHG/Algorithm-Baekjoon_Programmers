function solution(x, y, n) {
    if (x === y) return 0;

    const dp = Array.from({ length: y + 1 }).fill(Infinity);
    dp[x] = 0;

    for (let i = x + 1; i <= y; ++i) {
        if (i - n >= 0) dp[i] = dp[i - n] + 1;
        if (!(i % 2)) dp[i] = Math.min(dp[Math.floor(i / 2)] + 1, dp[i]);
        if (!(i % 3)) dp[i] = Math.min(dp[Math.floor(i / 3)] + 1, dp[i]);
    }

    return (dp[y] !== Infinity) ? dp[y] : -1;
}