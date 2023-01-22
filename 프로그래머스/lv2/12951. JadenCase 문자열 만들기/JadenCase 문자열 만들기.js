function solution(s) {
    var answer = "";
    s.split(" ").forEach(
        (e) =>
            (answer +=
                e.charAt(0).toUpperCase() +
                e.slice(1, e.length).toLowerCase() +
                " ")
    );
    return answer.slice(0, answer.length - 1);
}