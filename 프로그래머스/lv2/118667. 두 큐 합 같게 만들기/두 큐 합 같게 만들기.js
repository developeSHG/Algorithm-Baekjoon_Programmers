const sumFunc = (arr) => arr.reduce((acc, cur) => acc + cur, 0);

function solution(queue1, queue2) {
    let [answer, sum1, sum2, idx1, idx2] = [0, sumFunc(queue1), sumFunc(queue2), 0, 0];
    const [half, limit] = [(sum1 + sum2) / 2, queue1.length * 3];

    while (answer < limit) {
        if (sum1 === sum2)
            break;

        if (sum1 > half) {
            const data = queue1[idx1++];
            sum1 -= data, sum2 += data, queue2.push(data);
        } else {
            const data = queue2[idx2++];
            sum1 += data, sum2 -= data, queue1.push(data);
        }
        ++answer;
    }

    return (answer < limit) ? answer : -1;
}
