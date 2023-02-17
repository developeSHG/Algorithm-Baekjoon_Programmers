function solution(land) {
    return Math.max(...land.reduce((acc, arr, idx) => {
        if (acc.length <= 0)
            return arr;

        const max = Math.max(...acc);
        const maxIdx = acc.findIndex((e) => e === max);
        const nextMax = Math.max(...acc.filter((_, idx) => idx !== maxIdx));
        return arr.map((e, i) => (i !== maxIdx) ? e + max : e + nextMax);
    }, []));
}