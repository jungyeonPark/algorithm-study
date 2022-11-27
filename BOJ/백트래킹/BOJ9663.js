const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N = 0;
let cnt = 0;
let used = [];

const isUsed = (y, x) => {
  for (let i = 0; i < used.length; i++) {
    let u_y = used[i][0];
    let u_x = used[i][1];
    if (u_y === y) return true;
    if (u_x === x) return true;
    if (Math.abs(u_y - y) === Math.abs(u_x - x)) return true;
  }
  return false;
};

const fn = (n) => {
  if (n === N) {
    cnt++;
    return;
  }
  for (let i = 0; i < N * N; i++) {
    for (let j = 0; j < N; j++) {
      if (isUsed(i, j)) continue;
      // console.log(n, i, j, used);
      used.push([i, j]);
      fn(n + 1);
      used.pop();
    }
  }
};

rl.on("line", (line) => {
  N = line * 1;
}).on("close", () => {
  fn(0);
  console.log(cnt);
  process.exit();
});
