function solution(arr1, arr2) {
    return arr1.map((row) => {
        return arr2[0].map((_, col) => {
            return row.reduce((acc, e, idx) => acc + e * arr2[idx][col], 0);
        });
    });
}