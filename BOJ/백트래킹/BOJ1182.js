const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, S;
let input = [];
let cnt = 0;
let sum = 0;

const func = (n) => {
  console.log(sum);
  if (n !== 0 && sum === S) cnt++;
  if (n === N) return;
  for (let i = 0; i < N; i++) {
    sum += input[i];
    func(n + 1);
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
  func(0);
  console.log(cnt);
  process.exit();
});
