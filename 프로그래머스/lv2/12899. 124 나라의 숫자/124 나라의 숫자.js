function solution(n) {
  var answer = "", array1_2_4 = new Array(4, 1, 2);

  while(n) {
    answer = array1_2_4[n % 3] + answer;
    n = Math.floor((n - 1) / 3);
  }
  return answer;
}