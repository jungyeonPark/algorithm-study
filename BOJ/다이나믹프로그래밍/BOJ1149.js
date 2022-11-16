const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
const D = [];
let cost;
let N;

const DP = () => {
  D[0] = [0, 0, 0]; // r,g,b
  for (let i = 1; i <= N; i++) {
    D[i] = [];
    D[i][0] = Math.min(D[i - 1][1], D[i - 1][2]) + cost[i][0];
    D[i][1] = Math.min(D[i - 1][0], D[i - 1][2]) + cost[i][1];
    D[i][2] = Math.min(D[i - 1][0], D[i - 1][1]) + cost[i][2];
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  N = input[0] * 1;
  cost = input.map((i) => i.split(" ").map((j) => j * 1));
  DP();
  console.log(Math.min(D[N][0], D[N][1], D[N][2]));
  process.exit();
});
