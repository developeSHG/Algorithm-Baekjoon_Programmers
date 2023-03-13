const permutation = (operation, visited, priority, max, expression) => {
    if (operation.length === visited.filter((o) => o).length) {
        const [tempExp, tempPrior] = [[...expression], [...priority]];

        while (tempPrior.length) {
            const op = tempPrior.shift();

            let idx = tempExp.indexOf(op);
            while (idx !== -1) {
                const sum = eval(tempExp[idx - 1] + op + tempExp[idx + 1]);
                tempExp.splice(idx - 1, 3, sum);

                idx = tempExp.indexOf(op);
            }
        }

        return Math.max(max, Math.abs(parseInt(tempExp)));
    }

    for (let i = 0; i < operation.length; ++i) {
        if (visited[i]) continue;

        (visited[i] = true), priority.push(operation[i]);
        max = permutation(operation, visited, priority, max, expression);
        (visited[i] = false), priority.pop();
    }

    return max;
};

const solution = (expression) => permutation(["+", "-", "*"], new Array(3).fill(false), [], 0, expression.match(/\d+|[\-\+\*]/g));
