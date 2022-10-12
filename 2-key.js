'use strict';

const generateKey = (length, possible) => {
  const arrayOfPossible = possible.split('');
  const arrayPassword = new Array(length);
  for (let i = 0; i <= length; i++) {
    let n = Math.floor(Math.random() * arrayOfPossible.length);
    arrayPassword[i] = arrayOfPossible[n];
    }
  return arrayPassword.join('');
};
const characters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ0123456789';
const key = generateKey(16, characters);
console.log(key);