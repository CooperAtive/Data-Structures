function spaceReplace(string) {
  var length = string.length;
  var result = '';
  for (var i = 0; i < length; i++) {
    if (string[i] === " ") {result += "%20";}
    else {result += string[i];}
  }
  return result;
}
var string = "dum dum dum d u m"
console.log("Before: " + string);
console.log("After: " + spaceReplace(string));