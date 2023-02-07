function solution(clothes) {
    var answer = 1;
    const map = new Map();

    clothes.forEach((pair) => map.set(pair[1], (map.get(pair[1]) ? map.get(pair[1]) : 1) + 1));

    for (const [key, value] of map.entries()) answer *= value;
    return --answer;
}