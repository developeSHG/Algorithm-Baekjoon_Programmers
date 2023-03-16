const solution = (N, road, K) => {
  const dis = new Array(N + 1).fill(Infinity);
  const graph = Array.from(Array(N + 1), () => []);
  for (let [from, to, cost] of road) {
    // 무방향 그래프
    graph[from].push({ to: to, cost: cost });
    graph[to].push({ to: from, cost: cost });
  }

  const queue = [];

  // 첫 노드로 가는 정보를 큐에 삽입하고 bfs를 시작.
  queue.push({ to: 1, cost: 0 });
  dis[1] = 0;

  while (queue.length) {
    const { to: cur, cost: cost } = queue.shift();
    for (let next of graph[cur]) {
      // 다음 좌표의 dis값과 현재 dis값과 다음좌표로가는 코스트
      if (dis[next.to] > dis[cur] + next.cost) {
        dis[next.to] = dis[cur] + next.cost;
        queue.push(next);
      }
    }
  }

  return dis.filter((e) => e <= K).length;
};