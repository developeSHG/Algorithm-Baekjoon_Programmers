const combination = (idx, start, data, n, str, obj) => {
    if (start === n) {
        const str_tmp = data.join("");
        obj[str_tmp] = ((obj[str_tmp]) || 0) + 1;
        return obj;
    }

    for (let i = idx; i < str.length; ++i) {
        data[start] = str[i];
        obj = combination(i + 1, start + 1, data, n, str, obj);
    }
    return obj;
}

function solution(orders, course) {
    orders = orders.map(el => [...el].sort().join(""));
    return course.reduce((acc, n) => {
        let [pivot, arr] = [0, []];
        const result = orders.reduce((obj, str) => combination(0, 0, [], n, str, obj), {});

        Object.entries(result).forEach(([key, value]) => {
            if (value < 2 || value < pivot) return;
            
            if (value > pivot) {
                pivot = value;
                arr.length = 0;
            }    
            arr.push(key);
        });
        return acc.concat(arr);
    }, []).sort();
}
