const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let n, m;
const isUsed = [];
const answer = [];

function recursion(c) {
  if (c === m) {
    let ans = "";
    answer.map((i) => (ans += `${i} `));
    console.log(ans);
    ans = "";
    return;
  }
  for (let i = 1; i <= n; i++) {
    if (isUsed[i]) continue;
    answer[c] = i;
    isUsed[i] = 1;
    recursion(c + 1);
    isUsed[i] = 0;
  }
}

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  const arr = input.split(" ");
  n = arr[0] * 1;
  m = arr[1] * 1;
  for (let i = 0; i <= n; i++) {
    isUsed.push(0);
  }
  for (let i = 0; i < m; i++) {
    answer.push(0);
  }
  recursion(0);
  process.exit();
});
