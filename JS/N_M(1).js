const input = [4, 4];
const N = input[0];
const M = input[1];

const visited  = new Array(N);
let output = [];
let result = '';

function dfs(cnt) {
  if (cnt === M) {
    result += `${output.join(' ')}\n`;
    return;
  }

  for (let i = 0; i < N; ++i) {
    if (visited[i] === true) continue;
    visited[i] = true;
    output.push(i + 1);
    dfs(cnt + 1);
    output.pop();
    visited[i] = false;
  }
}

dfs(0);
console.log(result.trim());