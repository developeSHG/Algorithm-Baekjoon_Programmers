function solution(n, m, section) {
    return section.reduce((acc, el) => {
        if (acc[0] <= el) {
            ++acc[1];
            acc[0] = el + m;
        }
        return acc;
    }, [0, 0])[1];
}