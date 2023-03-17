class Tree {
    constructor(n) {
        this.tree = new Array(n + 1);
        this.min = n;
    }

    setConnect(v1, v2) {
        this.connect(v1, v2);
        this.connect(v2, v1);
    }

    connect(v, target) {
        const connects = this.tree[v] || [];
        connects.push(target);
        this.tree[v] = connects;
    }

    setDiff(v1, v2) {
        const len = this.getCount(v1, v2);
        this.min = Math.min(this.min, Math.abs(this.tree.length - 1 - len * 2));
    }

    getCount(v, except) {
        return this.tree[v].reduce((acc, cur) => {
            if (cur === except) return acc;
            return acc + this.getCount(cur, v);
        }, 1);
    }
}

function solution(n, wires) {
    const tree = new Tree(n);
    wires.forEach(([v1, v2]) => tree.setConnect(v1, v2));
    wires.forEach(([v1, v2]) => tree.setDiff(v1, v2));
    return tree.min;
}