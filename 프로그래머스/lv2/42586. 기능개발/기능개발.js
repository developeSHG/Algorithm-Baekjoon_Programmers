function solution(progresses, speeds) {
    return progresses.map((el, idx) => Math.ceil((100 - el) / speeds[idx])).reduce((queue, el) => {
        (queue.length < 1) ? queue.push([el]) : (queue[queue.length - 1][0] >= el) ? queue[queue.length - 1].push(el) : queue.push([el]);
        return queue;
    }, []).map((arr) => arr.length);
}