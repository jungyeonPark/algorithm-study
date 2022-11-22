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
let ans = 0;
// let ansArr;

const combine = (i, j, n) => {
  const x = dx[n];
  const y = dy[n];
  let tmp_i = i;
  let tmp_j = j;
  let isCombinded = false;
  while (1) {
    if (tmp_i + y >= N || tmp_i + y < 0 || tmp_j + x >= N || tmp_j + x < 0) {
      break;
    } else if (
      arr[tmp_i + y][tmp_j + x] !== arr[tmp_i][tmp_j] &&
      arr[tmp_i + y][tmp_j + x] > 0
    )
      break;
    else if (arr[tmp_i + y][tmp_j + x] === -1) {
      arr[tmp_i + y][tmp_j + x] = arr[tmp_i][tmp_j];
      arr[tmp_i][tmp_j] = 0;
      break;
    } else if (isCombinded && arr[tmp_i + y][tmp_j + x] === arr[tmp_i][tmp_j])
      break;
    else if (
      !isCombinded &&
      arr[tmp_i + y][tmp_j + x] > 0 &&
      arr[tmp_i + y][tmp_j + x] === arr[tmp_i][tmp_j]
    ) {
      arr[tmp_i + y][tmp_j + x] = arr[tmp_i][tmp_j] * 2;
      arr[tmp_i][tmp_j] = -1; // 이번 이동에 합쳐진 숫자가 2번 합쳐지지 않도록
      isCombinded = true; // 지금 합쳐진 숫자가 2번 합쳐지지 않도록
    } else {
      arr[tmp_i + y][tmp_j + x] = arr[tmp_i][tmp_j];
      arr[tmp_i][tmp_j] = 0;
    }
    tmp_i += y;
    tmp_j += x;
  }
};

const combineDir = (n) => {
  if (n === 0) {
    for (let i = 0; i < N; i++) {
      for (let j = N - 1; j >= 0; j--) {
        combine(i, j, n);
      }
      arr = arr.map((k) => k.map((l) => (l === -1 ? 0 : l)));
    }
  }
  if (n === 1) {
    for (let j = 0; j < N; j++) {
      for (let i = 0; i < N; i++) {
        combine(i, j, n);
      }
      arr = arr.map((k) => k.map((l) => (l === -1 ? 0 : l)));
    }
  }
  if (n === 2) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        combine(i, j, n);
      }
      arr = arr.map((k) => k.map((l) => (l === -1 ? 0 : l)));
    }
  }
  if (n === 3) {
    for (let j = 0; j < N; j++) {
      for (let i = N - 1; i >= 0; i--) {
        combine(i, j, n);
      }
      arr = arr.map((k) => k.map((l) => (l === -1 ? 0 : l)));
    }
  }
};

const answer = () => {
  for (let i = 0; i < 4 ** 5; i++) {
    let tmp = i;
    arr = input.map((i) => [...i]);
    for (let j = 0; j < 5; j++) {
      // console.log(tmp % 4);
      combineDir(tmp % 4);
      // console.log(arr);
      tmp = Math.floor(tmp / 4);
    }
    for (let k = 0; k < N; k++) {
      for (let l = 0; l < N; l++) {
        if (ans < arr[k][l]) {
          ans = arr[k][l];
          // ansArr = arr.map((a) => [...a]);
        }
      }
    }
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  N = input.shift() * 1;
  input = input.map((i) => i.split(" ").map((j) => j * 1));
  answer();
  console.log(ans);
  process.exit();
});
