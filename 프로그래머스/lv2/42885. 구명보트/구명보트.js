function solution(people, limit) {
    var answer = 0;

    people.sort((a, b) => b - a);
    for (let i = 0, j = people.length - 1; i <= j; ++i) {
        if (limit >= people[i] + people[j]) {
            ++answer;
            --j;
        } else ++answer;
    }

    return answer;
}
