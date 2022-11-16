const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
const D = [];

const DP = () => {
  D[0] = 0;
  D[1] = 1;
  D[2] = 2;
  for (let i = 3; i <= input; i++) {
    // D[i]의 시작은 두가지 뿐이다 : 1. 2x1이 한개가 올 때. 2. 1x2가 두개가 올 때(1x2를 놓으면 아래에는 반드시 1x2를 놔야 하므로)
    // 1번의 경우에는 D[i-1], 2번의 경우에 1x2두개를 놓으면 2x2가 되므로 D[i-2] 결국 피보나치 수열이 됨
    D[i] = (D[i - 1] + D[i - 2]) % 10007; // 미리 나눠야 오버플로우 생기지 않음
  }
};

rl.on("line", (line) => {
  input = line * 1;
}).on("close", () => {
  DP();
  console.log(D[input]);
  process.exit();
});
