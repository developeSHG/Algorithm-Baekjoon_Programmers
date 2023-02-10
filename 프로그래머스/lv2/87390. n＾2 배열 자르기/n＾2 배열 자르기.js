function solution(n, left, right) {
    return Array.from({ length: right - left + 1 }, (undefined, idx) => {
        idx += left;
        return Math.max(parseInt(idx / n) + 1, idx % n + 1);
    });
}
