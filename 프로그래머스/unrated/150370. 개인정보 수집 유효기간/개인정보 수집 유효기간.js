function solution(today, terms, privacies) {
    var answer = [];

    const [y, m, d] = today.split(".").map(Number);
    let db = {};

    function cal(day, u) {
        const [y1, m1, d1] = day.split(".").map(Number);
        let a = y - y1,
        b = m - m1,
        c = d - d1;

        return ((a * 12 + b - u) * 28 + c) >= 0;
    }

    for (let i of terms) {
        let [a, b] = i.split(" ");
        db[a] = Number(b);
    }

    for (let i = 0; i < privacies.length; ++i) {
        let [k, v] = privacies[i].split(" ");
        
        if (cal(k, db[v]))
            answer.push(i + 1);
    }

    return answer;
}