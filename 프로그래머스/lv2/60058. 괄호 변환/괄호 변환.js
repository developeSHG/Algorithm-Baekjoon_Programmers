function solution(p) {
    if (p === '') return '';

    let [u, v, open, close] = ['', '', 0, 0];
    for (i in p) {
        (p[i] === '(') ? ++open : ++close;

        if (open === close) {
            u = p.slice(0, i * 1 + 1);
            v = p.slice(i * 1 + 1);
            break;
        }
    }

    let [upright, check] = [true, 0];
    for (w of u) {
        (w === '(') ? ++check : --check;
        if (!(upright = (check < 0) ? false : true)) break;
    }
    return (upright) ? u + solution(v) : `(${solution(v)})${u.slice(1, u.length - 1).replace(/\(|\)/g, a => a === "(" ? ")" : "(")}`;
}