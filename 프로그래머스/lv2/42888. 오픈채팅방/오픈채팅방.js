const Show = {
    Enter: "님이 들어왔습니다.",
    Leave: "님이 나갔습니다."
};

function solution(record) {
    const nicknName = {};
    const output = [];

    record.forEach((e) => {
        const [execution, id, name] = e.split(' ');

        if (["Enter", "Change"].includes(execution)) nicknName[id] = name;
        if (["Enter", "Leave"].includes(execution)) output.push([execution, id]);
    });
    return output.map(([execution, id]) => `${nicknName[id]}${Show[execution]}`);
}
