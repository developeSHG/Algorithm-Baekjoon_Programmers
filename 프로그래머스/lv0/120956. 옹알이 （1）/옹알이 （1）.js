function solution(babbling) {
    return babbling.filter((el, idx) => {
        const temp = ["aya", "ye", "woo", "ma"];
        let length = el.length;

        temp.forEach((t) => {
            if (el.indexOf(t) != -1 && length >= t.length) length -= t.length;
        });
        return length <= 0;
    }).length;
}
