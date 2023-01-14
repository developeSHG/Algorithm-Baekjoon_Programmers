function solution(k, score) {
    var answer = [],
        award = [];

    for (const iterator of score) {
        if (k > award.length) {
            award.push(iterator);
            award.sort((a, b) => a - b);
            answer.push(award.at(0));
        } else if (iterator >= award.at(0)) {
            award.push(iterator);
            award.sort((a, b) => a - b).splice(0, 1);
            answer.push(award.at(0));
        } else answer.push(award.at(0));
    }
    return answer;
}