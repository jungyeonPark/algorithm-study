const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let arr;
let N;
let ans = 0;

const rotate = () => {
  const tmpArr = arr.map((a) => [...a]);
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      arr[j][N - i - 1] = tmpArr[i][j];
    }
  }
};

const merge = (dir) => {
  while (dir--) rotate(); // 4방향을 각각 구하지 않고 배열 자체를 회전시킨다
  for (let i = 0; i < N; i++) {
    const tilted = [];
    for (let t = 0; t < N; t++) {
      tilted.push(0);
    }
    const merged = [];
    let idx = 0;
    for (let j = 0; j < N; j++) {
      if (arr[i][j] === 0) continue;
      else if (tilted[idx] === 0) {
        tilted[idx] = arr[i][j];
        continue;
      } else if (!merged[idx] && arr[i][j] === tilted[idx]) {
        merged[idx] = true;
        tilted[idx++] = arr[i][j] * 2;
      } else {
        tilted[++idx] = arr[i][j];
      }
    }
    arr[i] = [...tilted];
  }
};

const answer = () => {
  for (let i = 0; i < 4 ** 5; i++) {
    let tmp = i;
    arr = input.map((i) => [...i]);
    for (let j = 0; j < 5; j++) {
      merge(tmp % 4);
      tmp = Math.floor(tmp / 4);
    }
    for (let k = 0; k < N; k++) {
      for (let l = 0; l < N; l++) {
        if (ans < arr[k][l]) {
          ans = arr[k][l];
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
