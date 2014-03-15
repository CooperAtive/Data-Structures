var LinkedList = require('./LinkedList').LinkedList;
//assuming pre-sorted lists

var myList1 = new LinkedList();
myList1.push(31);
myList1.push(15);
myList1.push(10);
var myList2 = new LinkedList();
myList2.push(66);
myList2.push(59);
myList2.push(2);

function mergeLists (list1, list2) {
    //if one list or both is empty return the non-empty list or null
    list1 = list1.head;
    list2 = list2.head;
    if (!list1 || !list2) return list1 ? list1 : list2;
    //otherwise go to recursive helper
    return helper(new LinkedList(), list1, list2);
}

function helper (acc, list1, list2) {
    if (list1.empty() || !list2) {
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
        return helper(acc, list1.next, list2);
    }

    else {
        acc.push(list2.value);
        return helper(acc, list1, list2.next);
    }
}



//establish pointers to the first node in each list
//if they are equal, build up list with that value, iterate both
//else, return the greater one, iterate the list of the greater one
//if there is no next node for either list, return the rest of the
//non-empty list immediately
console.log(JSON.stringify(mergeLists(myList1, myList2)));


