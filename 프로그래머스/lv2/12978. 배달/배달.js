function solution(N, road, K) {
    const graph = road.reduce((obj, [p1, p2, t]) => {
        (obj[p1] = obj[p1] || {}), (obj[p2] = obj[p2] || {});
        obj[p1][p2] = obj[p2][p1] = Math.min(obj[p1][p2] ? obj[p1][p2] : Infinity, t);
        return obj;
    }, {});

    const stack = [{ dest: 1, cost: 0 }],
        distance = new Array(N + 1).fill(Infinity);

    while (stack.length) {
        const { dest: cur, cost: cost } = stack.shift();

        if (distance[cur] > cost) distance[cur] = cost;

        for (const dest in graph[cur]) {
            if (distance[dest] < cost + graph[cur][dest]) continue;
            stack.push({ dest: dest, cost: cost + graph[cur][dest] });
        }
    }
    return distance.filter((e) => e !== Infinity && e <= K).length;
}