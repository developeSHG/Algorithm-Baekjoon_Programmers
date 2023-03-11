function solution(n, k) {
    const [arr, result, dp] = [
        Array.from({ length: n }, (_, i) => i + 1),
        [],
        [1, 1, 2],
    ];
    const factorial = (n) => {
        if (dp[n] !== undefined) return dp[n];
        return (dp[n] = n * factorial(n - 1));
    };

    for (let i = 0; i < n; ++i) {
        const fac = factorial(arr.length - 1);
        const idx = Math.ceil(k / fac) - 1;
        k = k - idx * fac;

        result.push(arr[idx]);
        arr.splice(idx, 1);
    }
    return result;
}