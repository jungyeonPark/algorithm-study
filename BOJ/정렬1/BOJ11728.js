// BOJ 11728

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let N; // 배열 A크기
let M; // 배열 B의 크기
let A;
let B;
const answer = [];

function mergeSort() {
  let aIdx = 0,
    bIdx = 0;
  for (let i = 0; i < N + M; i++) {
    if (aIdx === N) answer[i] = B[bIdx++];
    else if (bIdx === M) answer[i] = A[aIdx++];
    else answer[i] = A[aIdx] <= B[bIdx] ? A[aIdx++] : B[bIdx++];
  }
}

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  [N, M] = input[0].split(" ").map((i) => i * 1);
  A = input[1].split(" ").map((i) => i * 1);
  B = input[2].split(" ").map((i) => i * 1);
  mergeSort();
  console.log(answer.join(" "));
  process.exit();
});
