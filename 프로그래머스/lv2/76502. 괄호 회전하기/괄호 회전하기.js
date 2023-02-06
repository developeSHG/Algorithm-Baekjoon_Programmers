const solution = (s) => {
    const obj = {
        "[": "]",
        "(": ")",
        "{": "}",
    };
    return [...s].reduce((acc, el, idx) => {
        const stack = [el];
        for (let i = 1; i < s.length; ++i) {
            const a = (idx + i) % s.length;

            if (Object.keys(obj).find((key) => key === s[a])) stack.push(s[a]);
            else if (Object.values(obj).find((value) => value === s[a]) 
                     && obj[stack[stack.length - 1]] === s[a]) stack.pop();
            else return acc;
        }
        
        return (stack.length ? acc : ++acc);
    }, 0);
};
