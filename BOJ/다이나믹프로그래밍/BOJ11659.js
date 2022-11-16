const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const D = [];
const answer = [];
let N, M, arr;

const DP = () => {
  D[0] = arr[0];
  for (let i = 1; i <= N; i++) {
    D[i] = D[i - 1] + arr[i];
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, M] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  arr = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  arr.unshift(0);
  DP();
  input.forEach((i) => {
    let j = i.split(" ");
    answer.push(D[j[1]] - D[j[0] - 1]);
  });
  console.log(answer.join("\n"));
  process.exit();
});
