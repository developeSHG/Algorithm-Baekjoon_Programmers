function solution(maps) {
    const bfs = (s, e) => {
        const [width, height] = [maps.length, maps[0].length],
            [queue, valueVisit] = [[], maps.map((e) => [...e].map((v) => 0))];
        const [dirX, dirY] = [[0, 0, -1, 1], [-1, 1, 0, 0]];

        queue.push([s[0], s[1]]);

        while (queue.length) {
            const [x, y] = queue.shift();

            for (let i = 0; i < 4; ++i) {
                const [nx, ny] = [x + dirX[i], y + dirY[i]];

                if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                if (maps[nx][ny] === "X") continue;
                if (valueVisit[nx][ny] && valueVisit[x][y] + 1 >= valueVisit[nx][ny]) continue;

                valueVisit[nx][ny] = valueVisit[x][y] + 1;
                queue.push([nx, ny]);
            }
        }

        return valueVisit[e[0]][e[1]] === 0 ? -1 : valueVisit[e[0]][e[1]];
    };

    const pos = maps.reduce((acc, e, i) => ([...e].forEach((v, j) => {
                    if (["S", "L", "E"].includes(v)) acc[v] = [i, j];
                }), acc), {});
    const [dist1, dist2] = [bfs(pos["S"], pos["L"]), bfs(pos["L"], pos["E"])];
    
    return dist1 < 0 || dist2 < 0 ? -1 : dist1 + dist2;
}