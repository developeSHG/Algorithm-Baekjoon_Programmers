function solution(s) {
    let arr = s.split(" ");
    arr.sort((a, b) => a - b).splice(1, arr.length - 2);
    return arr.join(" ");
}
