function solution(word) {
    const res = {};
    let idx = 0;
    const alphabet = ['A', 'E', 'I', 'O', 'U'];

    (dfs = (now, cnt) => {
        if (cnt > 5) return;
        res[now] = idx++;
        if (now === word) return;

        for (let i = 0; i < 5; ++i) {
            next = now + alphabet[i];
            dfs(next, cnt + 1);
        }
    })('', 0);
    return res[word];
}
