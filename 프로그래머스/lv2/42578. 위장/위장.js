function solution(clothes) {
    var answer = 1;
    const map = new Map();

    clothes.forEach((pair) => map.set(pair[1], map.get(pair[1]) ? map.get(pair[1]) + 1 : 1));

    for (const [key, value] of map.entries()) answer *= (value + 1); // 아무것도 안입은 경우가 있어서 + 1
    return --answer;
}