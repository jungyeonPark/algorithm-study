// 그리디인 척 하는 DP
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, K;
let input = [];
const DP = [];

const func = () => {
  for (let i = 0; i <= K; i++) {
    DP[i] = 0;
  }
  for (let i = 1; i <= K; i++) {
    let max = DP[i - 1]; // 물건 무게를 합해서 i값이 딱 떨어지지 않을 수 있으니까 이전 최대값을 초기값으로 설정
    for (let j = 0; j < N; j++) {
      if (i === 4) console.log(max); // 같은 물건을 선택한 경우 처리 필요
      if (input[j][0] <= i) {
        max =
          max < input[j][1] + DP[i - input[j][0]]
            ? input[j][1] + DP[i - input[j][0]]
            : max;
      }
    }
    DP[i] = max;
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, K] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  input = input.map((i) => i.split(" ").map((j) => j * 1));
  func();
  console.log(DP);
  process.exit();
});
