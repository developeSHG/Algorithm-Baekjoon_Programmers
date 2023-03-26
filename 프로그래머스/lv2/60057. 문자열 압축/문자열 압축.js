function solution(s) {
    let answer = s.length;

    for (let i = 1; i <= Math.floor(s.length / 2); ++i) {
        let [str, word, idx, cnt] = ["", "", 0, 1];

        while (idx < s.length) {
            const temp = s.substr(idx, i);
            idx += i;

            if (temp === word) ++cnt;
            else {
                str += `${(cnt > 1 ? cnt : "")}${word}`;
                (cnt = 1), (word = temp);

                if (idx >= s.length) str += temp;
            }
        }

        if (cnt > 1) str += `${cnt}${word}`;
        answer = Math.min(str.length, answer);
    }
    return answer;
}