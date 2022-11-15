const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const arr = [];
let cnt;

const DP = () => {
  arr[0] = [, 0, 0];
  arr[1] = [, input[1], 0];

  for (let i = 2; i <= cnt; i++) {
    arr[i] = [];
    arr[i][1] =
      (arr[i - 2][1] > arr[i - 2][2] ? arr[i - 2][1] : arr[i - 2][2]) +
      input[i];
    arr[i][2] = arr[i - 1][1] + input[i];
  }
};

rl.on("line", (line) => {
  input.push(line * 1);
}).on("close", () => {
  cnt = input[0];
  DP();
  console.log(arr[cnt][1] > arr[cnt][2] ? arr[cnt][1] : arr[cnt][2]);
  process.exit();
});
