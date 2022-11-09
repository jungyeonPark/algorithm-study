const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input, inputArr;
let a, b, m;

function pow(a, b, m) {
  if (b === 1) return a % m;
  let val = pow(a, parseInt(b / 2), m);
  val = (val * val) % m;
  if (b % 2 === 0) return val;
  return (val * a) % m;
}

rl.on("line", function (line) {
  input = line;
}).on("close", function () {
  inputArr = input.split(" ");
  a = inputArr[0] * 1;
  b = inputArr[1] * 1;
  m = inputArr[2] * 1;
  console.log(pow(a, b, m));
  process.exit();
});
