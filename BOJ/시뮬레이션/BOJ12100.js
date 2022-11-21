const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let arr;
let N;
const dx = [1, 0, -1, 0];
const dy = [0, -1, 0, 1];

const combine = (n) => {
  const x = dx[n];
  const y = dy[n];
  while (1) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        arr[i + x][j + y] = arr[i][j]; // 범위 벗어났을때 처리
      }
    }
  }
};

const answer = () => {
  for (let i = 0; i < 4 ** 5; i++) {
    let tmp = i;
    arr = input.map((i) => [...i]);
    for (let j = 0; j < 5; j++) {
      combine(tmp % 4);
      tmp = Math.floor(tmp / 4);
    }
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  N = input.shift() * 1;
  input = input.map((i) => i.split(" ").map((j) => j * 1));
  answer();
  process.exit();
});
