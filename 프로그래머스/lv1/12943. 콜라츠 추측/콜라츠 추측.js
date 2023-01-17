function solution(num) {
    if (num === 1) return 0;
    let cnt = 0;

    function Collatz(val) {
        if (val === 1) return cnt;
        if (++cnt >= 500) return -1;
        return Collatz(val % 2 ? val * 3 + 1 : val / 2);
    }

    return Collatz(num);
}