const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
const input = [];
let A, B;
let ans = 0;

const func = () => {
  for (let i = 0; i < N; i++) {
    ans += A[i] * B[N - i - 1];
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  N = input.shift() * 1;
  [A, B] = input.map((i) =>
    i
      .split(" ")
      .map((j) => j * 1)
      .sort((a, b) => a - b)
  );
  func();
  console.log(ans);
  process.exit();
});
