const solution = (k, dungeons) => {
    let answer = 0;
    const visit = Array.from({ length: dungeons.length }, (_) => false);

    const dfs = (k, cnt) => {
        for (const i in dungeons) {
            const [need, consume] = dungeons[i];

            if (!visit[i] && k >= need) {
                visit[i] = true;
                dfs(k - consume, cnt + 1);
                visit[i] = false;
            }
        }
        answer = Math.max(answer, cnt);
    };

    dfs(k, 0);

    return answer;
};