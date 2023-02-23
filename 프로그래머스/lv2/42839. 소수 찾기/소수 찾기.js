const isPrime = (n) => {
    if (n <= 1) return false;
    for (let i = 2; i <= Math.sqrt(n); ++i)
        if (n % i === 0) return false;
    return true;
}

function solution(numbers) {
    var answer = 0;
    const arr = numbers.split('');
    const check = {}, visit = {};

    (function dfs(value) {
        if (!check[value] && isPrime(value)) ++answer;
        check[value] = true;

        for (let i = 0; i < arr.length; ++i) {
            if (visit[i]) continue;

            const next = (value.toString() + arr[i]);
            visit[i] = true;
            dfs(next * 1, i);
            visit[i] = false;
        }
    })(0);

    return answer;
}
