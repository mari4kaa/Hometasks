const range = (StartNumber, EndNumber) => {
  const len = ((EndNumber - StartNumber + 1) / 2);
  const array = new Array(len);
  let n = 0;
  for (let i = StartNumber; i <= EndNumber; i++) {
    if (i % 2 !== 0) {
      array[n++] = i;
    }
  }
  console.log(array);
};
range(15, 30);
