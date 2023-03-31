function solution(storey) {
    let plus = false;
    storey = [...storey.toString()].reverse();
    return storey.reduce((acc, el, idx) => {
        el *= 1;

        if (plus && el === 9) return ++acc;

        plus = el > 5;
        if (idx !== storey.length - 1 && el > 5 && storey[idx + 1] !== "9")
            ++acc;

        acc += el > 5 ? 10 - el : el;
        return acc;
    }, 0);
}
