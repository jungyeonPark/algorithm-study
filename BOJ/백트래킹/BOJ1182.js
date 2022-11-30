const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, S;
let input = [];
const used = [];
let cnt = 0;
let sum = 0;

const func = (n, start) => {
  if (n !== 0 && sum === S) cnt++;
  if (n === N) return;
  for (let i = start; i < N; i++) {
    if (used[i]) continue;
    used[i] = true;
    sum += input[i];
    func(n + 1, i + 1);
    used[i] = false;
    sum -= input[i];
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, S] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  input = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  func(0, 0);
  console.log(cnt);
  process.exit();
});
