const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const arr = [];
let T;

const DP = () => {
  let max = 0;
  input.forEach((a) => (max = a > max ? a : max));
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for (let i = 4; i <= max; i++) {
    let cnt = 0;
    for (let j = 1; j <= 3; j++) {
      cnt += arr[i - j];
    }
    arr[i] = cnt;
  }
};

rl.on("line", (line) => {
  input.push(line * 1);
}).on("close", () => {
  T = input.shift();
  DP();
  input.forEach((i) => console.log(arr[i]));
  process.exit();
});
