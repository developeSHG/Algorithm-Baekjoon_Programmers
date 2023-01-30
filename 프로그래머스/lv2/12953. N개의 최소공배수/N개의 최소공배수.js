function solution(arr) {
    arr.sort((a, b) => b - a);
    let loop = 1;
    while (
        arr.reduce((acc, e) => {
            return (loop * arr[0]) % e === 0 ? ++acc : acc;
        }, 0) != arr.length
    ) {
        ++loop;
    }

    return loop * arr[0];
}