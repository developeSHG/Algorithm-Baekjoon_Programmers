const gcd = (a, b) => b ? gcd(b, a % b) : a;

function solution(w, h) {
    return w * h - (w + h - gcd(w, h));
}
