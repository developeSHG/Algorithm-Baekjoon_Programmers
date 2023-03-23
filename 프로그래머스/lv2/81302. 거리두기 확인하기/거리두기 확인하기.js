function solution(places) {
    return places.reduce((acc, data) => {
        // 굳이 완전 탐색을 써서 모든 경로를 찾아 itv를 비교하는 것보단,
        // itv가 2인 데이터인것들만 추출해서 그 사이 경로에 X가 있는지 체크하는 게 더 효율적이라 판단.

        const peoples = []; // P인 데이터만 담아둘 배열
        data.forEach((el, i) => {
           [...el].forEach((el, j) => {
               if (el === "P") peoples.push([i, j]);
           })
        });

        const between = []; // 간격이 2인 인덱스들만 담아서, 중간에 X가 있는지 체크할 배열
        for (let i = 0; i < peoples.length - 1; ++i) {
            for (let j = i + 1; j < peoples.length; ++j) {
                const itv = Math.abs(peoples[i][0] - peoples[j][0]) + Math.abs(peoples[i][1] - peoples[j][1]);
                if (itv === 1) { // 간격이 1이면 더 검사할 필요없이 거리두기가 안된걸로 판단해서 로직 종료.
                    acc.push(0);
                    return acc;
                } else if (itv === 2) between.push([peoples[i], peoples[j]]);
            }
        }

        for (const [pivot, dest] of between) {
            // pivot을 기준으로 dest 와의 방향을 판단.
            // between에 데이터를 삽입할 때, 왼쪽 상단부터 순차적으로 저장했기 때문에 dest로의 방향은 무조건 +임.

            const line = pivot[0] === dest[0] || pivot[1] === dest[1] ? true : false; // X를 체크해야할 자리가 2개인지, 1개인지 알기위해 같은 line인지 체크
            const [betX, betY] = [pivot[0] + (dest[0] - pivot[0]) / 2, pivot[1] + (dest[1] - pivot[1]) / 2];

            if (line && (data[betX][betY] !== "X")
                || !line && ([data[dest[0]][pivot[1]], data[pivot[0]][dest[1]]].some((o) => o !== "X"))) {
                acc.push(0);
                return acc;
            }
        }

        acc.push(1);
        return acc;
    }, []);
}