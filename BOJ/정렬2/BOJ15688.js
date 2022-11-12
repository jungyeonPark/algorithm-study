// node로는 10초 안에 수행할 수 없는듯.. 시간초과

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const cnt = [];
let N;

for (let i = 0; i <= 2000000; i++) {
  cnt[i] = 0;
}

function countingSort() {
  for (let i = 0; i < N; i++) {
    cnt[input[i] * 1 + 1000000]++; // 이 수는 절댓값이 1,000,000보다 작거나 같은 정수
  }
  for (let i = 0; i <= 2000000; i++) {
    while (cnt[i]--) {
      console.log(i - 1000000);
    }
  }
}

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  N = input.shift();
  countingSort();
  process.exit();
});
