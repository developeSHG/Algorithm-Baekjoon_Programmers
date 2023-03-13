const permutation = (operation, visited, priority, max, expression) => {
    if (operation.length === visited.filter((o) => o).length) {
        const temp = [...expression];
        const tempPriority = [...priority];

        while (tempPriority.length) {
            const op = tempPriority.shift();

            let idx = temp.indexOf(op);
            while (idx !== -1) {
                const sum = eval(temp[idx - 1] + op + temp[idx + 1]);
                temp.splice(idx - 1, 3, sum);

                idx = temp.indexOf(op);
            }
        }
        // console.log(temp);

        return Math.max(max, Math.abs(parseInt(temp)));
    }

    for (let i = 0; i < operation.length; ++i) {
        if (visited[i]) continue;

        (visited[i] = true), priority.push(operation[i]);
        max = permutation(operation, visited, priority, max, expression);
        (visited[i] = false), priority.pop();
    }

    return max;
};

const solution = (expression) =>
    permutation(
        ["+", "-", "*"],
        new Array(3).fill(false),
        [],
        0,
        expression.match(/\d+|[\-\+\*]/g)
    );