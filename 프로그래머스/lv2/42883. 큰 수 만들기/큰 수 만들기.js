function solution(number, k) {
    return [...number]
        .reduce((stack, el, idx) => {
            while (stack && stack.at(-1) < el && k > 0) {
                stack.pop();
                --k;
            }
            stack.push(el);
            return (k > 0 && idx === number.length - 1) ? stack.slice(0, stack.length - k) : stack;
        }, []).join("");
}
