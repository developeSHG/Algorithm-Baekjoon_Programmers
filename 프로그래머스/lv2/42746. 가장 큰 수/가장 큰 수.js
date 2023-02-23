function solution(numbers) {
    const answer = numbers.sort((a, b) => {
        a += '';
        b += '';
        return (b + a) - (a + b);
    }).join("").toString();
    return answer[0] === '0' ? '0' : answer;
}