const divide = (cur, target) => {
    let pivot = cur[0];
    while (pivot) {
        if (cur.every((num) => !(num % pivot)) && !target.some((num) => !(num % pivot))) return pivot;
        --pivot;
    }
    return 0;
};

function solution(arrayA, arrayB) { return Math.max(divide(arrayA, arrayB), divide(arrayB, arrayA)) }