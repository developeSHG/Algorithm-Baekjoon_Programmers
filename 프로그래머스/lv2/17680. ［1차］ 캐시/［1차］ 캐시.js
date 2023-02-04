function solution(cacheSize, cities) {
    const queue = [];
    let runTime = 0;

    cities.forEach(data => {
        if (queue.includes(data.toLowerCase())) {
            queue.splice(queue.findIndex((e) => e === data.toLowerCase()), 1);
            runTime++;
        } else {
            if (queue.length >= cacheSize) queue.shift();
            runTime += 5;
        }
        if (cacheSize > 0) queue.push(data.toLowerCase());
    });

    return runTime;
}
