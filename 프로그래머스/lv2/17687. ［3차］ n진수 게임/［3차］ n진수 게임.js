function solution(n, t, m, p) {
    const max = m * (t - 1) + p;
    const answer = [];
    let numbers = "";
    let value = 0;

    while (numbers.length < max) numbers += (value++).toString(n);

    let i = 0;
    while (answer.length < t) {
        if ((i % m) + 1 === p) answer.push(numbers[i]);
        i++;
    }
    return answer.join("").toUpperCase();
}

// 제너레이터 활용
function solution(n, t, m, p) {
    const program = (function* (n) {
        let value = 0;
        while (true) {
            const numbers = [...value.toString(n)];
            for (let i = 0; i < numbers.length; i++)
                yield numbers[i].toString().toUpperCase();
            value++;
        }
    })(n);

    const output = [];
    let i = 0;
    while (output.length < t) {
        const { value } = program.next();
        if (i++ % m === p - 1) output.push(value);
    }
    return output.join("");
}
