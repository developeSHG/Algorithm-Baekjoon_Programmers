function solution(book_time) {
    let [rooms, livinig, empty] = [0, [], []];
    const GetTime = (n) => Number(n[0]) * 60 + Number(n[1]);

    book_time = book_time.map(([entrance, leave]) => [GetTime(entrance.split(":")), GetTime(leave.split(":"))]).sort((a, b) => a[0] - b[0]);

    book_time.forEach(([entrance, leave]) => {
        livinig = livinig.filter(([num, livingLeave]) => {
            return livingLeave + 10 > entrance 
            ? true : (function () {
                empty.push(num);
                return false;
            })();
        });

        !empty.length ? livinig.push([++rooms, leave]) : livinig.push([empty.pop(), leave]);
    });
    return rooms;
}