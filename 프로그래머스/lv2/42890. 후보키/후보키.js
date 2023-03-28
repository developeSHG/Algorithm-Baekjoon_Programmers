// 조합
const getCombination = (elements, pick) => {
    if (pick === 1) return elements.map((elem) => [elem]);

    const combinations = [];
    elements.forEach((element, index) => {
        const smallerCombinations = getCombination(elements.slice(index + 1), pick - 1);

        smallerCombinations.forEach((combination) => combinations.push([element].concat(combination)));
    });

    return combinations;
};

// 유일성 체크
const uniqueness = (relation, elements, row) => {
    const arr = new Array(row).fill("");
    elements.forEach((attr) => {
        for (let tuple = 0; tuple < row; ++tuple)
            arr[tuple] += relation[tuple][attr];
    });

    return !arr.some((x) => arr.indexOf(x) !== arr.lastIndexOf(x)); // 중복체크
};

// 최소성 체크
const minimality = (answer, elements) => {
    return answer.length 
        ? answer.every((arr) => arr.filter((a) => elements.some((b) => a === b)).length !== arr.length)
        : true;
};

function solution(relation) {
    const answer = [];
    const [attribute, row, column] = [Array.from({ length: relation[0].length }, (_, idx) => idx), relation.length, relation[0].length];

    for (let i = 1; i <= column; ++i) {
        const combinations = getCombination(attribute, i);
        combinations.forEach((elements) => {
            if (uniqueness(relation, elements, row) && minimality(answer, elements))
                answer.push(elements);
        });
    }

    return answer.length;
}
