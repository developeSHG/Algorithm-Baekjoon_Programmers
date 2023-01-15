function solution(number, limit, power) {
    let a = 0;

    for (let cur = 1; cur <= number; cur++) {
        let divisors = 0;
        for (let i = 1; i <= cur / 2; ++i) {
            if (cur % i === 0) ++divisors;
        }
        ++divisors;
        a += divisors <= limit ? divisors : power;
    }

    return a;
}
