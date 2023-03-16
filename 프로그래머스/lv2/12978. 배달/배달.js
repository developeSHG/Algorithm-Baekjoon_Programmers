function solution(N, road, K) {
    const graph = road.reduce((obj, [p1, p2, t]) => { 
        (obj[p1] = obj[p1] || {}), (obj[p2] = obj[p2] || {});
        obj[p1][p2] = obj[p2][p1] = Math.min(obj[p1][p2] ? obj[p1][p2] : Infinity, t);
        return obj;
    }, {}); // 무방향 그래프

    const stack = [{ dest: 1, cost: 0 }], // 첫 노드로 가는 정보를 삽입
        distance = new Array(N + 1).fill(Infinity); // distance는 각 노드의 최단 경로를 저장

    while (stack.length) { // dfs
        const { dest: cur, cost: cost } = stack.pop();

        if (distance[cur] > cost) distance[cur] = cost; // 최단 경로로 갱신

        for (const dest in graph[cur]) {
            if (distance[dest] < cost + graph[cur][dest]) continue; // dest 좌표의 경로 값보다, 현재 좌표에서 dest 좌표로 가는 경로가 크면 굳이 방문을 안함.
            stack.push({ dest: dest, cost: cost + graph[cur][dest] });
        }
    }
    return distance.filter((e) => e !== Infinity && e <= K).length; // K보다 낮은 최단 경로의 갯수만 추출
}