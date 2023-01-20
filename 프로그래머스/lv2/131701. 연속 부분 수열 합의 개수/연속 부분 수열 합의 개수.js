function solution(elements) {
    var answer = new Set();

    elements.forEach((e, i) => {
        let acc = 0;
        for (const j in elements) {
            let idx = (parseInt(j) + i) % elements.length;
            acc += elements[idx];
            answer.add(acc);
        }
    });

    return answer.size;
}