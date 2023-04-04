const divide = (a, b) => {
    let pivot = a[0];
    while (pivot) {
        if (a.every((num) => !(num % pivot)) && b.every((num) => num % pivot)) return pivot;
        --pivot;
    }

    return pivot;
};

function solution(arrayA, arrayB) {
    return Math.max(divide(arrayA, arrayB), divide(arrayB, arrayA));
}