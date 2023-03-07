function solution(numbers) {
    return numbers.map((e) => {
        const binary = e.toString(2).split("");

        if (binary.at(-1) === '0')
            binary[binary.length - 1] = '1';
        else if (!binary.some((v) => v === '0')) {
            binary[0] = '0';
            binary.unshift('1');
        }
        else {
            for (let i = binary.length - 1; i > 0; --i) {
                if (binary[i] === '1' && binary[i - 1] === '0') {
                    binary[i - 1] = '1';
                    binary[i] = '0';
                    break;
                }
            }
        }

        return parseInt(binary.join(""), 2);
    });
}