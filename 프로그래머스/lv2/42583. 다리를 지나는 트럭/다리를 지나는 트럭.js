function solution(bridge_length, weight, truck_weights) {
    if (truck_weights.length === 1) return bridge_length + 1;

    var sec = 1;
    let status = [];

    while (truck_weights.length || status.length) {
        let curWeight = 0;
        status = status.reduce((acc, t, i) => {
            if (i === 0)
                ++sec;

            if (++t.time <= bridge_length) {
                acc.push(t);
                curWeight += t.weight;
            }
            return acc;
        }, []);


        if (curWeight + truck_weights[0] <= weight) status.push({ weight: truck_weights.shift(), time: 1 });
    }
    return sec;
}
