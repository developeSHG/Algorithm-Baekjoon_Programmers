function solution(brown, yellow) {
    var answer = [];

    const SUM = brown + yellow;
    for (height = 3; height <= SUM / 2; ++height) {
        let width = Math.floor(SUM / height);
        if ((width - 2) * (height - 2) === yellow) return [width, height];
    }

    return answer;
}