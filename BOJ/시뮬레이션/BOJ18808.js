const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const arr = [];
let sticker;
let N, M, K; // 세로,가로,스티커 개수
let r, c;

const shiftInput = () => {
  return input
    .shift()
    .split(" ")
    .map((i) => i * 1);
};

const rotate = () => {
  const stickerTmp = [];
  for (let i = 0; i < c; i++) {
    stickerTmp[i] = [];
    for (let j = 0; j < r; j++) {
      stickerTmp[i][j] = 0;
    }
  }
  for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
      stickerTmp[j][r - i - 1] = sticker[i][j];
    }
  }
  sticker = stickerTmp.map((s) => [...s]);
  let tmp = r;
  r = c;
  c = tmp;
};

const stick = (x, y) => {
  for (let i = y; i < y + r; i++) {
    for (let j = x; j < x + c; j++) {
      if (i >= N || j >= M || arr[i][j] + sticker[i - y][j - x] > 1)
        return false;
    }
  }
  for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
      if (sticker[i][j]) arr[y + i][x + j] = 1;
    }
  }
  return true;
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, M, K] = shiftInput();

  for (let i = 0; i < N; i++) {
    arr[i] = [];
    for (let j = 0; j < M; j++) {
      arr[i][j] = 0;
    }
  }
  for (let i = 0; i < K; i++) {
    [r, c] = shiftInput();
    sticker = [];
    for (let i = 0; i < r; i++) {
      sticker[i] = shiftInput();
    }
    for (let i = 0; i < 4; i++) {
      i > 0 && rotate(i);
      for (let y = 0; y < N; y++) {
        for (let x = 0; x < M; x++) {
          if (stick(x, y)) {
            y = N;
            i = 4;
            break;
          }
        }
      }
    }
  }
  let ans = 0;
  arr.forEach((i) => i.forEach((j) => j === 1 && ans++));
  console.log(ans);
  process.exit();
});
