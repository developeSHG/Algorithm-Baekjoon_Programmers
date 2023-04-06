function solution(weights) {
    let count = 0;

    const dp = weights.reduce((obj, el) => {
        if (obj[el]) count += obj[el]; // 중복되는 거리에 있는 것들 카운팅.
        obj[el] = ++obj[el] || 1;
        return obj;
    }, {});

    const [arr, itvDp] = [Object.keys(dp), {}];

    // 2 ~ 4 긴갹에 있는 것들 체크 (곱한것을 누적하는 형식)
    for (let i = 2; i <= 4; ++i) {
        arr.forEach((el) => {
            const val = i * el;

            if (itvDp[val]) count += dp[el] * itvDp[val];
            itvDp[val] = itvDp[val] + dp[el] || dp[el];
        });
    }

    return count;
}