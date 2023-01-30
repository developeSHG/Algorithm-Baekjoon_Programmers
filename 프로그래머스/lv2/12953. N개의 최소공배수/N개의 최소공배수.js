function solution(arr) {
    let loop = 1;
    while (arr.reduce((acc, e) => (!((loop * arr[0]) % e) ? ++acc : acc), 0) !== arr.length) ++loop;
    return loop * arr[0];
}
