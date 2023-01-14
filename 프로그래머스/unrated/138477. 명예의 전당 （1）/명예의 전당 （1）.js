function solution(k, score) {
    var award = [];

    return score.reduce((a, element) => {
        if (k > award.length) {
            award.push(element);
            award.sort((a, b) => a - b);
        } else if (element >= award.at(0)) {
            award.push(element);
            award.sort((a, b) => a - b).shift();
        }

        a.push(award.at(0));
        return a;
    }, []);
}