function solution(maps) {
    const answer = [],
        [row, col] = [maps.length, maps[0].length],
        [dirX, dirY] = [[0, 0, -1, 1], [-1, 1, 0, 0]],
        visited = Array.from(Array(row),() => new Array(col).fill(false));

    const dfs = (x, y) => {
        let food = maps[x][y] * 1;
        visited[x][y] = true;

        for (let i = 0; i < 4; ++i) {
            const [destX, destY] = [x + dirX[i], y + dirY[i]];
            if (destX < 0 || destX >= row || destY < 0 || destY >= col) continue;
            if (isNaN(maps[destX][destY]) || visited[destX][destY]) continue;
             
            food += dfs(destX, destY);
        }
        return food;
    };

    maps.forEach((map, x) => {
        [...map].forEach((el, y) => {
            if (isNaN(el) || visited[x][y]) return;
            
            answer.push(dfs(x, y));
        });
    });
    return answer.length ? answer.sort((a, b) => a - b) : [-1];
}