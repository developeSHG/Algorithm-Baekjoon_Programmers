function solution(n, left, right) {
    var answer = [];
    for (let i = left; i <= right; ++i)
        answer.push(Math.max(Math.floor(i / n) + 1, i % n + 1));
    return answer;
}
