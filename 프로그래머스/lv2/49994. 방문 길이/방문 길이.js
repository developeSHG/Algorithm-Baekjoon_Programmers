const solution = (dirs) => {
    const [x, y, BOUNDARY] = [0, 1, 5];
    const inArea = (command, pos) =>
        (command === 'L' && pos[x] > -BOUNDARY)
        || (command === 'R' && pos[x] < BOUNDARY)
        || (command === 'D' && pos[y] > -BOUNDARY)
        || (command === 'U' && pos[y] < BOUNDARY)

    return [...dirs].reduce((acc, command) => {
        if (!inArea(command, acc.pos)) return acc;

        const prev = [...acc.pos];
        (command === 'L') ? --acc.pos[x] : (command === 'R') ? ++acc.pos[x] : 0;
        (command === 'D') ? --acc.pos[y] : (command === 'U') ? ++acc.pos[y] : 0;

        if (!acc.history[[prev, acc.pos]] && !acc.history[[acc.pos, prev]]) {
            acc.history[[prev, acc.pos]] = acc.history[[acc.pos, prev]] = true;
            ++acc.move;
        }
        return acc;
    }, { pos: [0, 0], history: {}, move: 0 }).move;
}