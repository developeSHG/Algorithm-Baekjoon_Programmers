const sumFunc = (arr) => arr.reduce((acc, cur) => acc + cur, 0);

function solution(queue1, queue2) {
    let [answer, sum1, sum2, idx1, idx2] = [0, sumFunc(queue1), sumFunc(queue2), 0, 0];
    const [half, limit] = [(sum1 + sum2) / 2, queue1.length * 3];

    while (true) {
        if (answer >= limit) return -1;
        
        if (sum1 === sum2)
            break;
        const data = (sum1 > sum2) ? queue1[idx1++] : queue2[idx2++];

        if (data > half)
            return -1;

        if (sum1 > half) {
            queue2.push(data);
            sum1 -= data;
            sum2 += data;
        } else {
            queue1.push(data);
            sum1 += data;
            sum2 -= data;
        }

        ++answer;
    }

    return answer;
}
