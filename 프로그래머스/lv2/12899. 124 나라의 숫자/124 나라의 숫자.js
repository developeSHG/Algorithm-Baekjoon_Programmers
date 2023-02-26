function solution(n) {
    let temp = n,
        answer = [],
        multiple = n % 3 === 0;

    if (multiple) --temp;
    while (temp !== 0) {
        let remain = parseInt(temp % 3);
        if (remain) answer.unshift(remain);
        else {
            answer.unshift(4);
            temp--;
        }
        temp = parseInt(temp / 3);
    }
    answer = answer.join("");

    if (multiple) answer = answer * 1 + 2;
    return answer.toString();
}