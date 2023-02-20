const solution = (want, number, discount) => {
    return discount.reduce(
        (acc, el) => {
            if (acc.queue.length >= 10) var shifted = acc.queue.shift();
            acc.queue.push(el);

            if (want.some((e) => e === shifted)) ++number[want.indexOf(shifted)];
            if (want.some((e) => e === el)) --number[want.indexOf(el)];

            acc.res += number.every((e) => e <= 0) ? 1 : 0;

            return acc;
        },
        { queue: [], res: 0 }
    ).res;
};