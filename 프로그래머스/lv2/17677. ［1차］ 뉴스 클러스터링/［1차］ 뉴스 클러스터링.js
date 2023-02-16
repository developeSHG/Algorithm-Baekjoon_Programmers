function solution(str1, str2) {
    // 숫자, 공백 제거
    // 특수문자, 괄호, 공백 모두 제거 - 점은 제거 안함
    const reg1 = /[0-9 ]/gim,
        reg2 = /[`.,~!@#$%^&*()_|+\-=?;:'"<>\{\}\[\]\\\/ ]/gim;

    const str = [str1, str2];
    for (const i in str) {
        str[i] = [...str[i]].reduce((acc, el, idx, arr) => {
            if (idx >= arr.length - 1
                || (el + arr[idx + 1]).replace(reg1, "").replace(reg2, "").length !== 2)
                return acc;

            acc.push((el + arr[idx + 1]).toUpperCase());
            return acc;
        }, []);
    }

    const temp = [...str[1]];
    const intersection = str[0].filter(it => {
        if (temp.includes(it)) {
            temp.splice(temp.indexOf(it), 1);
            return true;
        }
        return false;
    }).length;

    return (intersection || !(str[0].length === 0 && str[1].length === 0))
        ? Math.floor((intersection / (str[0].length + str[1].length - intersection)) * 65536) : 65536;
}
