const iterate = (myObj, callback) => {
  for(const key in myObj) {
    callback(key, myObj[key]);
  }
}
const obj = { a: 1, b: 2, c: 3 };
iterate(obj, (key, value) => {
  console.log({ key, value });
});