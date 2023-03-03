function solution(files) {
    return files.map((file) => {
        const HEAD = file.match(/\D+/g)[0],
            NUMBER = file.match(/\d+/g)[0],
            TAIL = file.slice(file.indexOf(NUMBER) + NUMBER.length, file.length);
        return { HEAD: HEAD, NUMBER, NUMBER, TAIL: TAIL };
    }).sort((a, b) => {
        const [A, B] = [a.HEAD.toLowerCase(), b.HEAD.toLowerCase()];
        if (A > B) return 1;
        else if (A === B) return (a.NUMBER * 1) - (b.NUMBER * 1);
        return -1;
    }).map((fileObj) => Object.values(fileObj).join(""));
}