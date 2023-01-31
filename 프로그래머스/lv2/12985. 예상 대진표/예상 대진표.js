function solution(n, a, b) {
    [a, b] = a > b ? [b, a] : [a, b];
    for (var i = 1; i <= Math.sqrt(n); ++i) {
        if (b - a === 1 && a % 2&& !(b % 2)) break;
        a = Math.ceil(a / 2);
        b = Math.ceil(b / 2);
    }
    return i;
}