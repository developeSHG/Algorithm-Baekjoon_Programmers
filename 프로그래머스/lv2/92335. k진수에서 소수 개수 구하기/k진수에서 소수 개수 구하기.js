function solution(n, k) {
    const isPrime = (N) => {
        if (["1", ""].includes(N)) return false;

        for (let i = 2; i <= Math.sqrt(N); i++) {
            if (N % i === 0) return false;
        }
        return true;
    }
    return n.toString(k).split(0).filter((e) => isPrime(e)).length;
}
