const pipe = (...fns) => {
  fns.forEach((fn) => {
    if (typeof fn !== 'function') {
      throw new Error();
    }
  });
  return ((x) => fns.reduce((v, f) => f(v), x));
};
const inc = (x) => ++x;
const twice = (x) => x * 2;
const cube = (x) => x ** 3;

const f = pipe(inc, twice, cube);
const res = f(5);
console.log(res);
const f2 = pipe(inc, 7, cube);
const res2 = f2(5);

console.log(res2);
