function solution(arr1, arr2) {
    return arr1.reduce((acc, eArr1) => {
        const temp = [];
        let cnt = 0;
        while (cnt < arr2[0].length) {
            let val = 0;
            for (let i = 0; i < eArr1.length; ++i)
                val += eArr1[i] * arr2[i][cnt];

            temp.push(val);
            ++cnt;
        }
        acc.push(temp);
        return acc;
    }, []);
}