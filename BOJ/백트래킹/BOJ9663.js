const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N = 0;
let cnt = 0;
const used_y = []; // 열
const used_rd = []; // 오른쪽 대각선
const used_ld = []; // 왼쪽 대각선

// NxN에서 퀸을 N개 두려면 한 행에 한개씩 있을 수 밖에 없으므로 n을 행으로 둔다
const fn = (n) => {
  if (n === N) {
    cnt++;
    return;
  }
  for (let i = 0; i < N; i++) {
    if (used_y[i] | used_rd[n + i] | used_ld[n - i + N]) continue;
    used_y[i] = true;
    used_rd[n + i] = true;
    used_ld[n - i + N] = true; // 음수를 만들지 않기 위해 N을 더함 (절댓값으로 하면 다른 값까지 영향을 줌)
    fn(n + 1);
    used_y[i] = false;
    used_rd[n + i] = false;
    used_ld[n - i + N] = false;
  }
};

rl.on("line", (line) => {
  N = line * 1;
}).on("close", () => {
  fn(0);
  console.log(cnt);
  process.exit();
});
