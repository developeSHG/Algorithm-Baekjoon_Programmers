function solution(fees, records) {
    records = records.reduce(
        (acc, el) => {
            const record = el.split(" ");
            acc[record[2]].push(record[0] + " " + record[1]);
            return acc;
        },
        { IN: [], OUT: [] }
    );

    parking = records.IN.reduce((acc, el) => {
        const inRecord = el.split(" ");
        const outRecords = records.OUT.reduce(
            (out, e) => {
                const outRecord = e.split(" ");
                if (
                    outRecord[1] === inRecord[1] &&
                    outRecord[0] > inRecord[0] &&
                    out.length <= 1
                )
                    out.unshift(outRecord[0]);
                return out;
            },
            ["23:59"]
        );

        inTime = inRecord[0].split(":");
        outTime = outRecords[0].split(":");

        acc[parseInt(inRecord[1])] =
            (isNaN(acc[parseInt(inRecord[1])])
                ? 0
                : acc[parseInt(inRecord[1])]) +
            (parseInt(outTime[0]) * 60 + parseInt(outTime[1])) -
            (parseInt(inTime[0]) * 60 + parseInt(inTime[1]));

        return acc;
    }, {});

    return Object.values(parking).map((el) =>
        fees[0] < el
            ? fees[1] + Math.ceil((el - fees[0]) / fees[2]) * fees[3]
            : fees[1]
    );
}