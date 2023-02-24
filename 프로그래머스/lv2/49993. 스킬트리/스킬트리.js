function solution(skill, skill_trees) {
    return skill_trees.reduce((acc, el) => [...el].filter(w => skill.includes(w)).reduce((state, e, i) => (!state) ? false : (skill[i] === e), true) ? ++acc : acc, 0);
}
