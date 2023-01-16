function solution(k, tangerine) {
    const temp = {};
    tangerine.forEach((element) => {
        temp[element] = ++temp[element] || 1;
    });

    const arr = Object.values(temp).sort((a, b) => b - a);

    let sum = 0,
        answer = 0;

    for (let num of arr) {
        answer++;
        sum += num;

        if (sum >= k) break;
    }

    return answer;
}