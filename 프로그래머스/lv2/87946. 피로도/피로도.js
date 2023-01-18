function solution(k, dungeons) {
    const length = dungeons.length;
    const visited = Array(length).fill(false);
    let answer = 0;
    let temp = 0;

    const dfs = (currentK, cnt) => {
        for(let i = 0; i < length; i++) {
            // 해당 던전을 아직 방문하지 않았고
            // 던전의 최소 피로도가 현재 피로도보다 작거나 같으면
            if(!visited[i] && currentK >= dungeons[i][0]) {
            	// 해당 던전 방문표시
                visited[i] = true;
                // 재귀~
                dfs(currentK - dungeons[i][1], cnt + 1);
                // 추후 다시 방문해야 하므로 방문 표시 해제
                visited[i] = false;
            }
        }
        // 최대 던전 수 갱신
        answer = Math.max(answer, cnt);
        return;
    }

    dfs(k, 0);

    return answer;
}