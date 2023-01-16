function solution(k, m, score) {
    var answer = 0;

    score = score
        .sort((a, b) => b - a)
        .filter(
            (e, index) =>
                1 <= e && e <= k && index < parseInt(score.length / m) * m
        );

    for (let i = m - 1; i < score.length; i += m) answer += score[i] * m;

    return answer;
}