const array = [true, 'hello', 5, 12, -200, false, false, 'word', true, 'something', 356, { n: 40 }, undefined];
const hash = {};
for (let i = 0; i < array.length; i++) {
  const element = array[i];
  const h = typeof (element);
  if (hash[h] == null) {
    hash[h] = 0;
  }
  hash[h]++;
}
console.dir(hash);
