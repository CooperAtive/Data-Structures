'use strict';
/*
function listReverse(list){
    var stack = [];
    while(list.tail){
        stack.push(list.head);
        list = list.tail;
    }
    stack.push(list.head);
    var finalList = {};
    var currentList = finalList;
    while (stack.length) {
        currentList.head = stack.pop();
        currentList.tail = {};
        currentList = currentList.tail;
    }
    currentList.tail = null;
    return finalList;
}
*/

var recursiveReverse = function recursiveReverse(acc, list) {
    if (list === null) return acc;
    return recursiveReverse({head: list.head, tail: acc}, list.tail);
};


module.exports.reverseList = recursiveReverse;
