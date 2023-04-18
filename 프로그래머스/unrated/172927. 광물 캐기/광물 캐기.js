function solution(picks, minerals) {
    let answer = 0;

    const bundle = Math.min(picks.reduce((acc, e) => acc + e, 0) * 5, minerals.length);
    const arr = minerals.reduce((acc, e, idx) => {
        if (idx >= bundle) return acc;

        const i = ~~(idx / 5);
        acc[i] = acc[i] || [0, 0, 0];
        ++acc[i][["diamond", "iron", "stone"].indexOf(e)];
        return acc;
    }, []);

    arr.sort((a, b) => b[0] - a[0] || b[1] - a[1]);

    arr.forEach((e) => {
        for (let i = 0; i < picks.length; ++i) {
            if (!picks[i]) continue;

            if (i === 0)
                e.forEach((el) => answer += el);
            else {
                e.forEach((el, idx) => {
                    if (idx < i) answer += Math.pow(5, i - idx) * el;
                    else answer += el;
                })
            }

            --picks[i];
            return;
        }
    });

    return answer;
}
