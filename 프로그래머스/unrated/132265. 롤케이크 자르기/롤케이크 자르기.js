function solution(topping) {
    const [lDic, lSizeArr, rDic, rSizeArr] = [new Set(), [], new Set(), []];

    topping.forEach((el, idx) => {
        lDic.add(el);

        if (idx !== 0) rDic.add(topping.at(-idx));

        lSizeArr.push(lDic.size);
        rSizeArr.push(rDic.size);
    });
    return lSizeArr.reduce((acc, el, idx) => (el === rSizeArr.at(-idx - 1)) ? ++acc : acc, 0);
}