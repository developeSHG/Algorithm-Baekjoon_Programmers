function solution(word) {
    const alphabet = ['A', 'E', 'I', 'O', 'U'];

    const dfs = (cur, cnt, complete) => {
        cur += alphabet[0];

        if (cur.length > alphabet.length) {
            cur = cur.slice(0, cur.length - 1).split('');

            for (let i = cur.length - 1; i >= 0; --i) {
                if (complete > i)
                    break;

                if (i === complete && cur[complete] === alphabet[alphabet.length - 1]) {
                    ++complete;
                    if (i + 1 < cur.length) cur[i + 1] = alphabet[alphabet.length - 1];
                    break;
                }

                if ((alphabet.indexOf(cur[i]) + 1) % alphabet.length === 0) {
                    cur[i] = 'z';
                }
                else {
                    cur[i] = alphabet[(alphabet.indexOf(cur[i]) + 1)];
                    break;
                };
            }
            cur = cur.filter((e) => e !== 'z').join().replaceAll(',', '');
        }

        if (cur === word)
            return cnt + 1;

        return dfs(cur, cnt + 1, complete);
    };

    return dfs('', 0, 0);
}
