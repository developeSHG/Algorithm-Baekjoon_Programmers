function solution(s) {
    let convert = 0,
        erase = 0;

    while (s !== "1") {
        erase += s.split("0").length - 1;
        s = s.replace(/0/g, "");
        ++convert;

        s = s.length.toString(2);
    }

    return [convert, erase];
}
