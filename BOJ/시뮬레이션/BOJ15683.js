const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];
let arr;
let vis;
let N, M;
let min = 65;
const cctv = [];
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function visit(cctvNum, dir) {
  const d = dir % 4;
  let x = cctv[cctvNum][1];
  let y = cctv[cctvNum][2];
  while (1) {
    x = x + dx[d];
    y = y + dy[d];
    if (y >= N || y < 0 || x >= M || x < 0) return;
    if (vis[y][x] === 6) return;
    vis[y][x] = 7;
  }
}

function visitDir(cctvNum, dir) {
  const kind = cctv[cctvNum][0];
  switch (kind) {
    case 1: {
      visit(cctvNum, dir);
      return;
    }
    case 2: {
      visit(cctvNum, dir);
      visit(cctvNum, dir + 2);
      return;
    }
    case 3: {
      visit(cctvNum, dir);
      visit(cctvNum, dir + 1);
      return;
    }
    case 4: {
      visit(cctvNum, dir);
      visit(cctvNum, dir + 1);
      visit(cctvNum, dir + 2);
      return;
    }
    default: {
      visit(cctvNum, dir);
      visit(cctvNum, dir + 1);
      visit(cctvNum, dir + 2);
      visit(cctvNum, dir + 3);
    }
  }
}

function answer() {
  for (let i = 0; i < 4 ** cctv.length; i++) {
    vis = arr.map((v) => [...v]);
    let tmp = i;
    for (let j = 0; j < cctv.length; j++) {
      visitDir(j, tmp % 4);
      tmp = Math.floor(tmp / 4);
    }
    let cnt = 0;
    vis.forEach((y) =>
      y.forEach((data) => {
        if (data === 0) cnt++;
      })
    );
    if (min > cnt) min = cnt;
  }
}

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, M] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  arr = input.map((i, idx_y) =>
    i.split(" ").map((a, idx_x) => {
      if (a !== "0" && a !== "6") cctv.push([a * 1, idx_x, idx_y]);
      return a * 1;
    })
  );
  vis = arr.map((v) => [...v]);
  answer();
  console.log(min);
  process.exit();
});
