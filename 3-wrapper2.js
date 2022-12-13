'use strict';

const contract = (fn, ...types) => (...args) => {
  for (let i = 1; i < args.length; i++) {
    let arg = args[i];
    const type = types[i].name.toLowerCase();
    if (type !== typeof arg) {
      throw new TypeError('Invalid type of argument');
    }
  }
  const res = fn(...args);
  const typeRes = types[args.length - 1].name.toLowerCase();
  if (typeof res !== typeRes) {
    throw new TypeError('Invalid type of result');
  }
  return res;
}
const add = (a, b, c, d) => a + b + c + d;
const addNumbers = contract(add, Number, Number, Number, Number, Number);
const resNum = addNumbers(2, 3, 4, 5);
console.dir(resNum);

const concat = (s1, s2) => s1 + s2;
const concatStrings = contract(concat, String, String, String);
const resStr = concatStrings('Hello ', 'world!');
console.dir(resStr);