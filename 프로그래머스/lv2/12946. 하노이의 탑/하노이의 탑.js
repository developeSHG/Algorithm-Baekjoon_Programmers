function solution(n) {
  let answer = [];

  // 하노이의 탑 공식
  // 1. A기둥의 (n-1)번째 원판을 B기둥으로 이동시킨다.
  // 2. A기둥의 n번째 원판을 C기둥으로 이동시킨다.
  // 3. B기둥의 (n-1)번째 원판을 C기둥으로 이동시킨다.
    
  const hanoi = (n, start, mid, end) => { 
    if (n === 1) answer.push([start,end]); // 원반이 하나만 남는다면, 시작점에서 끝점으로만 옮기고 재귀를 끝낸다.
    else {
      hanoi(n-1, start, end, mid); // n-1개의 원반을 start(1번)에서 mid(2번)으로 옮기고 = (mid에 원판들을 옮겨놔야, n을 end로 옮기기 때문에)
      answer.push([start, end]); // 남아있는 n번째 원반을 start(1번)에서 end(3번)으로 옮긴다.
      hanoi(n-1, mid, start, end); // 마지막으로 mid(2번)으로 옮겼던 n-1개 원반을 end(3번)으로 옮긴다.
    }
  }
  
  hanoi(n, 1, 2, 3); // 1번은 시작점, 2번은 경유지, 3번은 도착점.   시작점, 도착점, 경유지는 상황에 따라 변화한다.
  return answer
}