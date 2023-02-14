function solution(priorities, location) {
    const recursive = (res, data) => {
        if (!data.some((e, i) => data[0] < e && 0 < i)) {
            if (0 == location) return res.length + 1;
            res.push(data[0]);
            --location;
        }
        else {
            location = (location - 1 < 0) ? data.length - 1 : location - 1;
            data.push(data[0]);
        }
        data.shift();
        return recursive(res, data);
    };

    return recursive([], priorities);
}