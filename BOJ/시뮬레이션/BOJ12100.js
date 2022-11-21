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
  for (let i = 0; i < N; i++) {
    // n에 따라 순서 변경 필요
    for (let j = 0; j < N; j++) {
      let tmp_i = i,
        tmp_j = j;
      while (1) {
        if (tmp_i + x >= N || tmp_i + x < 0 || tmp_j + y >= N || tmp_j + y < 0)
          break;
        else if (arr[tmp_i + x][tmp_j + y] === arr[tmp_i][tmp_j]) {
          arr[tmp_i + x][tmp_j + y] = arr[tmp_i][tmp_j] * 2;
        } else if (arr[tmp_i + x][tmp_j + y] > 0) break;
        else arr[tmp_i + x][tmp_j + y] = arr[tmp_i][tmp_j];
        console.log(arr[tmp_i + x][tmp_j + y], arr[tmp_i][tmp_j]);
        arr[tmp_i][tmp_j] = 0;
        tmp_i += x;
        tmp_j += y;
      }
    }
  }
};

const answer = () => {
  for (let i = 0; i < 1; i++) {
    let tmp = i;
    arr = input.map((i) => [...i]);
    for (let j = 0; j < 5; j++) {
      combine(tmp % 4);
      tmp = Math.floor(tmp / 4);
    }
    console.log(arr);
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
