function solution(babbling) {
    return babbling.filter((el, idx) => {
        let len = el.length;
        ["aya", "ye", "woo", "ma"].forEach((t) => {
            if (el.indexOf(t) != -1 && len >= t.length) len -= t.length;
        });
        return !len;
    }).length;
}