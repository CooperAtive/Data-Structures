var LinkedList = function LinkedList(){

    var head = {};
    this.listSize = 0;
    var self = this;
    function constructor() { }

    constructor.prototype.push = function(element) {
        if(this.head === null){//if the list is empty
            this.head.value = element; //set the heads value
            this.head.next = null;
        }
        else {//otherwise push a new head and set *next to current head
            var newHead = {value: element, next: this.head};
            this.head = newHead;
        }
        self.listSize++;
    };

    constructor.prototype.pop = function(pos) {
        if (pos >= this.size()) return false;
        var previous = this.head, //keep a pointer to previous node
            current;
        if (pos === 0 ) { //if you want to delete head
            this.head = this.head.next; //set head to head.next
            return previous.value;
        }
        for (var i = 0; i < pos - 1; i++){
            previous = previous.next; //pos - 1 indexed node
        }
        current = previous.next; //pos indexed node
        previous.next = current.next; //reset pointers to remove current node
        self.listSize--;
        return current.value; //return the value
    };

    constructor.prototype.isElement = function(element) {
        var current = this.head;
        while(current){
            if (current.value === element) return true;
            current = current.next;
        }
        return false;
    };

    constructor.prototype.size = function() {
        return self.listSize;
    };

    constructor.prototype.empty = function(){
        if (this.head === undefined) return true;
        return false;
    };

    constructor.prototype.sort = function(list){
        if (!list || list.size() < 2) return list;
        var previous = this.head, //keep a pointer to previous node
            current = previous.next;
        while(current){
            if (previous.value > current.value){

            }
        }
    };

    return new constructor();
};


var myList = new LinkedList();
console.log(myList.empty());
myList.push(1);
myList.push(2);
myList.push(3);
myList.push(4); //[4, 3, 2, 1]
console.log(JSON.stringify(myList));//print the list
console.log("myList.size: " + myList.size());//print the size
console.log(myList.isElement(3));//returns true
console.log(myList.isElement(6));//returns false
console.log(myList.pop(3));//returns 1 (4 is the head in this implementation)
//[4, 3, 2]
console.log(JSON.stringify(myList));//prints list with (4, 3, 2) as the values
console.log(myList.pop(0));//check edge case for removing head returns 4
//[3, 2]
console.log(JSON.stringify(myList));//prints list with (3, 2) as the values
myList.push(4);
//[4, 3, 2]
console.log(myList.pop(1));//test removing inner node, returns 3
//[4, 2]
console.log(myList.pop(7));//test removing out of bounds node, returns false
//[4, 2]
console.log(JSON.stringify(myList));//prints list with (4, 2) as the values
module.exports.LinkedList = LinkedList;
