//시간초과, 메모리초과...
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let N, M;
const chicken = [];
const house = [];
const isUsed = [];
let selected = [];
let min = 250000;

const calcDistance = (house, chicken) => {
  const [h_x, h_y] = house;
  const [c_x, c_y] = chicken;
  const x = Math.abs(h_x - c_x);
  const y = Math.abs(h_y - c_y);
  return x + y;
};

const backTraking = (count) => {
  if (count === M) {
    let city_min = 0;
    for (let j = 0; j < house.length; j++) {
      let house_min = 2500;
      for (let k = 0; k < M; k++) {
        let distance = calcDistance(house[j], chicken[selected[k]]);
        if (house_min > distance) {
          house_min = distance;
        }
      }
      city_min += house_min;
    }
    if (min > city_min) min = city_min;
    return;
  }
  for (let i = 0; i < chicken.length; i++) {
    if (isUsed[i]) continue;
    isUsed[i] = 1;
    selected[count] = i;
    backTraking(count + 1);
    isUsed[i] = 0;
  }
};

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  [N, M] = input
    .shift()
    .split(" ")
    .map((i) => i * 1);
  input.forEach((i, i_idx) =>
    i.split(" ").map((j, j_idx) => {
      if (j === "1") house.push([i_idx, j_idx]);
      if (j === "2") chicken.push([i_idx, j_idx]);
    })
  );
  backTraking(0);
  console.log(min);

  process.exit();
});
