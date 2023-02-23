function solution(numbers) {
    const answer = numbers.sort((a, b) => {
        a += '';
        b += '';
        return (b + a) * 1 - (a + b) * 1;
    }).join("").toString();
    return answer[0] === '0' ? '0' : answer;
}