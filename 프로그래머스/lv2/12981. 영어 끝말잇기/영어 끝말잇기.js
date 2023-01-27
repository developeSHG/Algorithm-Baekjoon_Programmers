function solution(n, words) {
    let lastWord = words[0].charAt(0),
        idx = 0;
    const from = [];

    for (const word of words) {
        if (word.charAt(0) !== lastWord || from[word])
            return [(idx % n) + 1, Math.floor(idx / n) + 1];

        lastWord = word.slice(-1);
        ++idx;
        from[word] = true;
    }

    return [0, 0];
}