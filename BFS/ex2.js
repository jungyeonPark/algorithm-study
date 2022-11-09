const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let vis = [];
let n, m;
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let Q = [];

function answer() {
  Q.push({ x: 0, y: 0 });
  vis[0][0] = 1;
  while (Q.length > 0) {
    const cur = Q.shift();
    for (let dir = 0; dir < 4; dir++) {
      let nx = cur.x + dx[dir];
      let ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (input[nx][ny] === 0 || vis[nx][ny] >= 1) continue;
      vis[nx][ny] = vis[cur.x][cur.y] + 1;
      Q.push({ x: nx, y: ny });
    }
  }
  console.log(vis[n - 1][m - 1]);
}

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  for (let i = 0; i < input.length; i++) {
    if (i === 0) {
      input[i] = input[i].split(" ");
    } else {
      input[i] = input[i].split("");
    }
    vis.push([]);
    for (let j = 0; j < input[i].length; j++) {
      input[i][j] *= 1;
      vis[i][j] = 0;
    }
  }
  n = input[0][0];
  m = input[0][1];
  input.shift();
  vis.shift();
  answer();
  process.exit();
});
