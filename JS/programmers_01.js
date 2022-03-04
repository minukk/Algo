function solution(progresses, speeds) {
  let answer = [];

  let result = [];
  for (let i = 0; i < progresses.length; i++) {
    result.push(Math.ceil((100 - progresses[i]) / speeds[i]));
  }

  let day = 1;
  let minDay = result[0];
  if (result.length === 1) {
    answer.push(1);
  }
  for (let i = 1; i < result.length; i++) {
    if (minDay < result[i]) {
      answer.push(day);
      day = 1;
      minDay = result[i];
    } else {
      day++;
    }
    if (result.length - 1 === i) {
      answer.push(day);
    }
  }

  return answer;
}
