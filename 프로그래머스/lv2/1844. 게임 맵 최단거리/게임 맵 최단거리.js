function solution(maps) {
    return (bfs = (startY, startX) => {
        const [height, width] = [maps.length, maps[0].length],
            [queue, valueVisit] = [[], maps.map(i => i.map(v => 0))];
        const directionY = [0, 0, -1, 1],
            directionX = [-1, 1, 0, 0];

        queue.push([startY, startX]);
        valueVisit[startY][startX] = maps[startY][startX];

        while (queue.length) {
            const [y, x] = queue.shift();

            for (let i = 0; i < 4; i++) {
                const [nextY, nextX] = [y + directionY[i], x + directionX[i]];
                
                if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height) continue;
                if (!maps[nextY][nextX]) continue;
                if (valueVisit[nextY][nextX] && valueVisit[y][x] + maps[nextY][nextX] >= valueVisit[nextY][nextX]) continue;

                valueVisit[nextY][nextX] = maps[nextY][nextX] + valueVisit[y][x];
                queue.push([nextY, nextX]);
            }
        }

        return valueVisit[height - 1][width - 1] === 0 ? -1 : valueVisit[height - 1][width - 1];
    })(0, 0);
}