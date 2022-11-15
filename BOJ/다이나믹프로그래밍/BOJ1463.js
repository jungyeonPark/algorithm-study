const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input;
const arr = [];

const DP = () => {
  arr[0] = 0;
  arr[1] = 0;
  for (let i = 2; i <= input; i++) {
    arr[i] = arr[i - 1];
    if (i % 3 === 0) arr[i] = arr[i] < arr[i / 3] ? arr[i] : arr[i / 3];
    if (i % 2 === 0) arr[i] = arr[i] < arr[i / 2] ? arr[i] : arr[i / 2];
    arr[i]++;
  }
};

rl.on("line", (line) => {
  input = line * 1;
}).on("close", () => {
  DP();
  console.log(arr[input]);
  process.exit();
});
