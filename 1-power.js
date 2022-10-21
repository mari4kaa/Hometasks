function power(exp, n) {
  let result = 1;
  for (let i = 1; i <= exp; i++) {
    result *= n;
  }
  return result;
}
const square = (n) => power(2, n);
function cube(n) {
  return power(3, n);
}
const powerCube = cube.bind(power);
console.log(power(4, 2));
console.log(square(6));
console.log(cube(2));
console.log(powerCube(2));
