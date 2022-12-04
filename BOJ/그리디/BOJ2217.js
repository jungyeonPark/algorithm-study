const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
let input = [];
let ans = 0;

const func = () => {
  for (let i = 0; i < N; i++) {
    if (ans > input[i] * (N - i)) continue;
    ans = input[i] * (N - i);
  }
};

rl.on("line", (line) => {
  input.push(line * 1);
}).on("close", () => {
  N = input.shift();
  input = input.sort((a, b) => a - b);
  func();
  console.log(ans);
  process.exit();
});
