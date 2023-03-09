const sumFunc = (arr) => arr.reduce((acc, cur) => acc + cur, 0);

function solution(queue1, queue2) {
    let [answer, sum1, sum2, idx1, idx2] = [0, sumFunc(queue1), sumFunc(queue2), 0, 0];
    const [half, limit] = [(sum1 + sum2) / 2, queue1.length * 3];

    // shift 없이 idx를 사용하는 이유는 js는 queue를 지원하지 않기 때문에
    // shift를 사용하면 시간복잡도(n)이 걸려서 시간초과가 날 수 있다.
    
    // limit는 최악의 케이스를 대비한 수.
    // 최악의 케이스는 한 큐에서 하나를 제외하고, 다른 큐로 모두 보내는 경우이기 때문에
    // 원래 길이 * 3을 넘어서 순회할 경우 return해서 탈출하도록 설정.
    
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
