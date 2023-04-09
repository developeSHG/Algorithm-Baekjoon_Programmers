function solution(sequence, k) {
    let [s, e, sum] = [0, 0, sequence[0]];
    const answer = [];

    while (s < sequence.length - 1) {
        if ([sequence[s], sequence[e]].every((v) => v === k)) return [s, e];

        // (알고리즘 패턴) 슬라이딩 윈도우 패턴
        // 값이 크면 ++s(앞제거), 값이 작으면 ++e(뒤추가), 정답이면 ++s, ++e
        if (sum >= k || e >= sequence.length - 1) (sum -= sequence[s]), ++s;
        else if (sum <= k && e < sequence.length - 1) ++e, (sum += sequence[e]);

        if (sum == k) answer.push([s, e]);
    }

    return answer.sort(([a, b], [c, d]) => (b - a) - (d - c))[0];
}