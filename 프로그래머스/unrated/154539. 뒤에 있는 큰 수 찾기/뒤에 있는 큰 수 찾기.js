solution = (numbers) => {
    return Array(numbers.length)
        .fill(-1)
        .reduce((stack, el, idx, arr) => {
            while (stack && numbers[stack.at(-1)] < numbers[idx])
                arr[stack.pop()] = numbers[idx];
            stack.push(idx);
            return idx === numbers.length - 1 ? arr : stack;
        }, []);
};