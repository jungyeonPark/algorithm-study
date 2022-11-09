const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let N, r, c;

function answer(N, r, c) {
  if (N === 0) return 0;
  const half = 2 ** (N - 1);

  if (r < half && c < half) return answer(N - 1, r, c);
  if (r < half && c >= half) return half * half + answer(N - 1, r, c - half);
  if (r >= half && c < half)
    return 2 * half * half + answer(N - 1, r - half, c);
  return 3 * half * half + answer(N - 1, r - half, c - half);
}

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  const i = input.split(" ");
  N = i[0];
  r = i[1];
  c = i[2];
  console.log(answer(N, r, c));
  process.exit();
});
