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
let combination = [];
let min = 250000;

const backTraking = (count) => {
  if (count === M) {
    combination.push([...selected]);
    return;
  }
  for (let i = 0; i < chicken.length; i++) {
    if (isUsed[i]) continue;
    selected[count] = i;
    isUsed[i] = 1;
    backTraking(count + 1);
    isUsed[i] = 0;
  }
};

const calcDistance = (house, chicken) => {
  const [h_x, h_y] = house;
  const [c_x, c_y] = chicken;
  const x = Math.abs(h_x - c_x);
  const y = Math.abs(h_y - c_y);
  return x + y;
};

const answer = () => {
  backTraking(0);
  for (let i = 0; i < combination.length; i++) {
    let city_min = 0;
    for (let j = 0; j < house.length; j++) {
      let house_min = 2500;
      for (let k = 0; k < M; k++) {
        if (house_min > calcDistance(house[j], chicken[combination[i][k]])) {
          house_min = calcDistance(house[j], chicken[combination[i][k]]);
        }
      }
      city_min += house_min;
    }
    if (min > city_min) min = city_min;
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
  answer();
  console.log(min);

  process.exit();
});
