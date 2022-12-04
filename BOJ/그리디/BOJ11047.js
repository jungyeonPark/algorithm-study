const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, K;
let input = [];
let ans = 0;

const func = () => {
  let tmp = K;
  // 다음에 올 동전이 배수 관계이므로 나눌 수 있는 가장 큰 수부터 차례로 개수를 세면 됨
  for (let i = N - 1; i >= 0; i--) {
    if (tmp === 0) return;
    ans += Math.floor(tmp / input[i]);
    tmp = tmp % input[i];
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, K] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  input = input.map((i) => i * 1);
  func();
  console.log(ans);
  process.exit();
});
