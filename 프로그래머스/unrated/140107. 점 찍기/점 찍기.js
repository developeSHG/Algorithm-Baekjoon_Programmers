function solution(k, d) {
    let answer = 0;

    const getY = (num) => Math.sqrt(d ** 2 - num ** 2);

    for (let i = 0; i <= d; i += k) answer += Math.floor(getY(i) / k) + 1;

    return answer;
}