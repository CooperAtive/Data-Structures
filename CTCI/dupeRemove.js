function dupeRemove(arr) {
  if (!arr) return;
  var length = arr.length;
  if (length < 2) return arr;
  var pivot = 1;

  for (var i = 1; i < length; i++) {
    for (var j = 0; j < pivot; j++) {
      if (arr[i] === arr[j]) break;
      if (j === pivot) { //no dupe found because we didn't break above
        str[i] = str[j];
        pivot++;
      }
    }
    return arr.slice(0, pivot);
  }
}

var testArr = [2, 2, 3, 4, 5, 5, 2];
console.log(dupeRemove(testArr));

