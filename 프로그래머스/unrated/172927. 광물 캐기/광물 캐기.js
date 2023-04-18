// 완전 탐색으로도 풀 수 있지만, 그리디로 해결
// 1. 자원을 5개씩 묶는다.
// 2. 묶는 자원 별로 각 광물끼리 수를 저장한다.
// 3. 비용이 큰 순서대로 정렬하고, 다이아 곡괭이 -> 철 곡괭이 -> 돌 곡괭이 순으로 광물을 캐면 된다.
function solution(picks, minerals) {
    let answer = 0;

    const bundle = Math.min(picks.reduce((acc, e) => acc + e, 0) * 5, minerals.length); // 광석을 캐는 실제 범위
    const arr = minerals.reduce((acc, e, idx) => { // 5개씩 그룹화
        if (idx >= bundle) return acc;

        const i = ~~(idx / 5); // 5개씩 묶는 형태
        acc[i] = acc[i] || [0, 0, 0];
        ++acc[i][["diamond", "iron", "stone"].indexOf(e)];
        return acc;
    }, []);

    // 다이아 광물이 제일 많은 순이 최우선
    // 그 다음으로, 다이아 광물이 같다면 철 광물이 최우선
    // 결론은 비용이 가장 많이 드는 순으로 정렬한다. (다이아 곡괭이부터 쓸것이기 때문에)
    arr.sort((a, b) => b[0] - a[0] || b[1] - a[1]);

    arr.forEach((e) => {
        for (let i = 0; i < picks.length; ++i) {
            if (!picks[i]) continue; // 곡괭이 수가 0인 것은 pass

            e.forEach((el, idx) => {
                if (idx < i) answer += Math.pow(5, i - idx) * el; // 광물이 곡괭이보다 속성이 높다면, 그 차이만큼 5의 거듭제곱으로 피로도 누적
                else answer += el;
            })
            --picks[i];

            return; // 곡괭이를 썻으니, 다음 광물묶음에 새로운 곡괭이로 체크하기위해 바로 return
        }
    });

    return answer;
}