function solution(s) {
    var answer = [-1];

    for (let i = 1; i < s.length; ++i){
        let index = s.lastIndexOf(s[i], i-1);

        if (-1 < index)
            index = i - index;

        answer.push(index);
    }

    return answer;
}