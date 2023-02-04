function solution(cacheSize, cities) {
    const queue = [];
    let runTime = 0;

    for (data of cities) {
        if (queue.includes(data.toLowerCase())) {
            queue.splice(
                queue.findIndex((e) => e.toLowerCase() === data.toLowerCase()),
                1
            );
            runTime++;
        } else {
            if (queue.length >= cacheSize) queue.shift();
            runTime += 5;
        }
        if (cacheSize > 0) queue.push(data.toLowerCase());

        // if (queue.length >= cacheSize)
        //     runTime += 5;
    }

    return runTime;
}
