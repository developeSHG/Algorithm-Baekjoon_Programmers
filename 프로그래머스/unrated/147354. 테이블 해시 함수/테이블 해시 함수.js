function solution(data, col, row_begin, row_end) {
    data = data.sort((a, b) => {
        const res = a[col - 1] - b[col - 1];
        return res === 0 ? b[0] - a[0] : res;
    });

    const answer = [];
    for (let idx = row_begin; idx <= row_end; ++idx)
        answer.push(data[idx - 1].reduce((acc, el) => acc + (el % idx), 0));

    return answer.reduce((acc, el) => acc ^ el, 0);
}