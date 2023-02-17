function solution(msg) {
    const alphabet = "abcdefghijklmnopqrstuvwxyz".toUpperCase();
    const container = [...alphabet].reduce((accumulator, value, index) => {
        return { ...accumulator, [value]: ++index };
    }, {});

    const answer = [];
    while (msg.length) {
        let i, w;
        for (i = msg.length; i > 0; --i) {
            w = msg.slice(0, i);
            if (container.hasOwnProperty(w)) {
                answer.push(container[w]);
                break;
            }
        }
        msg = msg.slice(i);
        container[w + msg[0]] = Object.keys(container).length + 1
    }

    return answer;
}