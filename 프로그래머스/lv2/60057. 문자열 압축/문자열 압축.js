function solution(s) {
    let answer = s.length;
    for (let i = 1; i <= Math.floor(s.length / 2); ++i) {
        let [str, word, idx, cnt] = ["", "", 0, 1];
        let remain;
        while (idx < s.length) {
            const temp = s.substr(idx, i);
            if (temp === word) ++cnt;
            else {
                if (cnt > 1) str += cnt.toString() + word;
                else str += word;
                (cnt = 1), (word = temp);

                if (idx + i >= s.length) str += temp;
            }
            idx += i;
        }
        if (cnt > 1) str += cnt.toString() + word;

        answer = Math.min(str.length, answer);
    }
    return answer;
}
