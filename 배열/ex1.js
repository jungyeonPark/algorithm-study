const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;

function answer(input) {
  let a = [];
  for (let i = 0; i < 26; i++) {
    a.push(0);
  }
  for (let i = 0; i < input.length; i++) {
    const index = input[i].charCodeAt(0) - 97;
    a[index]++;
  }
  console.log(a.join(" "));
}

rl.on("line", function (line) {
  input = line;
}).on("close", function () {
  answer(input);
  process.exit();
});
