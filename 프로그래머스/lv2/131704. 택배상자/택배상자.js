function solution(order) {
    let [result, box] = [0, 1];
    const stack = [];

    for (find of order) {
        while (true) {
            if (box === find) {
                ++box;
                break;
            } else if (stack.at(-1) === find) {
                stack.pop();
                break;
            } else {
                if (box < order.length) stack.push(box++);
                else return result;
            }
        }
        ++result;
    }

    return result;
}
