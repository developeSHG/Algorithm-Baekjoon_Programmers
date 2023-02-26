function solution(number, k) {
    return [...number]
        .reduce((stack, el, idx) => {
            while (stack && stack.at(-1) < el && k > 0) {
                stack.pop();
                --k;
            }
            stack.push(el);
            
            if (k > 0 && idx === number.length - 1) stack.splice(stack.length - k, k);
            return stack;
        }, [])
        .join("");
}
