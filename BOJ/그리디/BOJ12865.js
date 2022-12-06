// 그리디인 척 하는 DP
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, K;
let input = [];
let ans = 0;

const DP = (n, bag) => {
  if (n === N) {
    if (ans < bag[1]) ans = bag[1];
    return;
  }
  DP(n + 1, [bag[0], bag[1]]);
  if (bag[0] + input[n][0] <= K)
    DP(n + 1, [bag[0] + input[n][0], bag[1] + input[n][1]]);
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, K] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  input = input.map((i) => i.split(" ").map((j) => j * 1));
  for (let i = 0; i < N; i++) {
    DP(i, [0, 0]);
  }
  console.log(ans);
  process.exit();
});
