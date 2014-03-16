'use strict';

var LinkedList = require('./LinkedList').LinkedList;

var mergeLists = function mergeLists(list1, list2) {
    //if one list or both is empty return the non-empty list or null
    list1 = list1.head;
    list2 = list2.head;
    if (!list1 || !list2) return list1 ? list1 : list2;
    //otherwise go to recursive mergeHelper
    return mergeHelper(new LinkedList(), list1, list2);
};

function mergeHelper (acc, list1, list2) {
    if (!list1 || !list2) {
        if (!list1){
            while(list2){
                acc.push(list2.value);
                list2 = list2.next;
            }
        }
        else {
            while(list1){
                acc.push(list1.value);
                list1 = list1.next;
            }
        }
        return acc;
    }
    if (list1.value < list2.value) {
        acc.push(list1.value);
        return mergeHelper(acc, list1.next, list2);
    }

    else {
        acc.push(list2.value);
        return mergeHelper(acc, list1, list2.next);
    }
}

module.exports.mergeLists = mergeLists;
