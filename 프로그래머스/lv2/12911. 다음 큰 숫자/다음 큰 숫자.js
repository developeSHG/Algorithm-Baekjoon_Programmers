function solution(n) {
    const len = n.toString(2).split("1").length - 1;
    ++n;
    while (len != n.toString(2).split("1").length - 1) ++n;
    return n;
}