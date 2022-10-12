const square = (x) => x * x;
const cube = (x) => x * x * x;

const average = (a, b) => (a + b) / 2;

const calculate = () => {
  const array = new Array(10);
  let n = 0;
  for (let i = 0; i <= 9; i++) {
    array[n++] = average(square(i), cube(i));
  }
  console.log(array);
};
calculate();
