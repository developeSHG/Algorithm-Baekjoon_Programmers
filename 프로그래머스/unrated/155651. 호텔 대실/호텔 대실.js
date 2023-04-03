function solution(book_time) {
    let rooms = 0;
    let [livinig, empty] = [[], []];
    const GetTime = (n) => Number(n[0]) * 60 + Number(n[1]);

    book_time = book_time.map(([entrance, leave]) => [
        GetTime(entrance.split(":")),
        GetTime(leave.split(":")),
    ]);
    book_time;

    book_time = book_time.sort((a, b) => a[0] - b[0]);
    book_time;

    book_time.forEach(([entrance, leave]) => {
        if (rooms === 0) {
            livinig.push([rooms++, leave]);
            return;
        }

        livinig = livinig.filter(([num, livingLeave]) => {
            return livingLeave + 10 > entrance
                ? true
                : (function () {
                      empty.push(num);
                      return false;
                  })();
        });

        if (!empty.length) {
            livinig.push([++rooms, leave]);
        } else livinig.push([empty.pop(), leave]);

    });

    return rooms;
}