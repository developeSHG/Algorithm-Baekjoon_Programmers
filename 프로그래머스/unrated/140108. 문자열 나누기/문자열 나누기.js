function solution(s) {
    var first;
    var countArr = new Array(3).fill(0);

    [...s].forEach((element, index) => {
        first ||= element;

        if (element === first) ++countArr[0];
        else ++countArr[1];

        if (countArr[0] === countArr[1]) {
            ++countArr[2];
            first = undefined;
        }
    });

    return countArr[0] !== countArr[1] ? ++countArr[2] : countArr[2];
}