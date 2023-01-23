function solution(s) {
    let res = 0;
    for (let e of s) {
        e === "(" ? ++res : --res;
        if (res < 0) return false;
    }
    return !res;
}
