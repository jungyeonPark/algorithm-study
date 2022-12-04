const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
let input = [];
let cnt = 0;

const func = () => {
  let tmp = 0;
  for (let i = 0; i < N; i++) {
    if (tmp <= input[i][0]) {
      cnt++;
      tmp = input[i][1];
    }
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  N = input.shift() * 1;
  input = input
    .map((i) => i.split(" ").map((j) => j * 1))
    .sort((a, b) => {
      // "시작하자마자 끝나는 회의" 때문에 끝나는 시간이 같다면 시작하는 시간이 작은 순으로 정렬해야 함
      if (a[1] === b[1]) return a[0] - b[0];
      else return a[1] - b[1];
    });
  func();
  console.log(cnt);
  process.exit();
});
