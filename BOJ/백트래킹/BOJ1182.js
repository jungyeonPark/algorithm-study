const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, S;
let input = [];
let cnt = 0;

const func = (n, sum) => {
  if (n === N) {
    sum === S && cnt++;
    return;
  }
  func(n + 1, sum);
  func(n + 1, sum + input[n + 1]);
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
  for (let i = 0; i < N; i++) {
    func(i, input[i]);
  }
  console.log(cnt);
  process.exit();
});
