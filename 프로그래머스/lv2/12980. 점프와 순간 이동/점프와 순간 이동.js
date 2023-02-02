function solution(n) {
    var acc = 0;
    if (n == 1)
        return 1;
    if (Math.floor(n % 2) === 1)
        acc++;
    
    while (n !== 1) {
        if (Math.floor(n / 2) % 2 === 1)
            acc++;
        n = Math.floor(n / 2);
    }
    
    return acc;
}
