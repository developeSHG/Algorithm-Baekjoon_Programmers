function solution(s) {
    s = s.replace(/{/g, "").replace(/},/g, " ").replace(/}/g, "").split(" ").sort((a, b) => a.length > b.length ? 1 : -1);
    return s.reduce((acc, el) => {
        el = el.split(",");

        if (acc.length < el.length) {
            acc.forEach((v) => {
                el = el.filter((o) => o !== v);
            });
            acc.push(el.join());
        }
        else if (acc.length > el.length) {
            el.forEach((v) => {
                acc = acc.filter((o) => o !== v);
                acc.unshift(v);
            });
        }
        return acc;
    }, s[0].split(",")).map(Number);
}