const compose = (...fns) => {
  const handlers = [];
  const composed = (x) => {
    try {
      const res = fns.reverse().reduce((v, f) => f(v), x);
      return res;
    } catch (error) {
      handlers.forEach((handler) => handler(error));
      return undefined;
    }
  };
  composed.on = (name, handler) => {
    if (name === 'error') {
      handlers.push(handler);
    }
  };
  return composed;
};

// Usage

const inc = (x) => ++x;
const twice = (x) => x * 2;
const cube = (x) => x ** 3;

const f = compose(inc, twice, cube);
const res = f(5);
console.log(res);

const f2 = compose(inc, 7, cube);
f2.on('error', (error) => {
  console.log('Everything goes according to plan');
});
const res2 = f2(5);
console.log(res2);
