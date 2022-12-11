// 그리디인 척 하는 DP
// 냅색 알고리즘
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, K;
let input = [];
const DP = [];

const func = () => {
  for (let i = 0; i <= N; i++) {
    DP.push([]);
    for (let j = 0; j <= K; j++) {
      DP[i][j] = 0; // 1번부터 i까지의 물건을 사용해서 j무게를 만들 때 가치의 최대값
    }
  }
  for (let i = 1; i <= N; i++) {
    for (let j = 0; j <= K; j++) {
      DP[i][j] = DP[i - 1][j]; // 이전 최대값을 초기값으로 설정
      // j - input[i][0] 번 인덱스를 음수로 만들지 않기 위함
      if (j - input[i][0] >= 0) {
        DP[i][j] =
          DP[i][j] < input[i][1] + DP[i - 1][j - input[i][0]] // 여기가 핵심: j - input[i]무게의 최댓값 + input[i]무게와 이전 최대값을 비교
            ? input[i][1] + DP[i - 1][j - input[i][0]]
            : DP[i][j];
      }
    }
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
  input.unshift([0, 0]); // 1 index로 맞춤
  func();
  console.log(DP[N][K]);
  process.exit();
});
