function solution(A, B) {
    A.sort((a, b) => a - b);
    B.sort((a, b) => b - a);
    return A.reduce((acc, e, i) => {
        acc += e * B[i];
        return acc;
    }, 0);
}