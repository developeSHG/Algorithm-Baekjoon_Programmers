const dfs = (graph, pivot, visited, vistedDuplication) => {
    const queue = [pivot];
    let cnt = 0;

    while (queue.length) {
        const dest = queue.shift();
        if (vistedDuplication[dest]) return Infinity;

        (visited[dest] = true), ++cnt;
        for (const to of graph[dest]) {
            if (visited[to]) continue;
            queue.push(to);
        }
    }
    return cnt;
};

function solution(n, wires) {
    const graph = wires.reduce((acc, [a, b]) => {
            acc[a].push(b), acc[b].push(a);
            return acc;
        }, Array.from(Array(n + 1), () => []));

    const visitedNone = visitedDivision = new Array(n + 1).fill(false);

    let result = Infinity;
    graph.forEach((form, idx) => {
        for (const division of form) {
            visitedNone[idx] = visitedDivision[idx] = true;
            const divisionCnt = dfs(graph, division, visitedDivision, visitedNone);

            let nodeCnt = 1;
            for (const node of form.filter((e) => e !== division))
                nodeCnt += dfs(graph, node, visitedNone, visitedDivision);

            result = Math.min(result, Math.abs(divisionCnt - nodeCnt));

            visitedDivision.fill(false);
            visitedNone.fill(false);
        }
    });

    return result;
}