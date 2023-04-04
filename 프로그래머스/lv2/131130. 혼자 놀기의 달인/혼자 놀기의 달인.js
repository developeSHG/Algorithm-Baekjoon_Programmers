function solution(cards) {
    const [box, group] = [new Array(cards.length).fill(false), []];
    let i = 0;

    // while (group.some((v) => !v) && box.some((v) => !v)) {
    while (box.some((v) => !v)) {
        let num = box.indexOf(false);
        while (!box[num] && num < box.length) {
            box[num] = true;
            group[i] = ++group[i] || 1;
            num = cards[num] - 1;
        }
        ++i;
    }

    group.sort((a, b) => b - a);
    return group.length > 1 ? group[0] * group[1] : 0;
}
