function LinkedList(){

    var head = {};

    function constructor() { }

    constructor.prototype.push = function(element) {
        if(this.head === null){
            this.head.value = element;
            this.head.next = null;
        }
        else {
            var newHead = {value: element, next: this.head};
            this.head = newHead;
        }
    };

    constructor.prototype.pop = function(pos) {
        var current = this.head.next;
        var prev = this.head;
        var count = 1;
        while(current){
            if (pos === 1){
                this.head = this.head.next;
                break;
            }
            if (count === pos) {

            }
        }
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
        var size = 0;
        var current = this.head;
        while(current){
            size++;
            current = current.next;
        }
        return size;
    };

    constructor.prototype.empty = function(){
        if (this.head) return false;
        return true;
    };

    return new constructor();
}


var myList = new LinkedList();

myList.push(1);
myList.push(2);
myList.push(3);
console.log("myList: " + myList);
console.log("myList.size: " + myList.size());
console.log(myList.isElement(3));
console.log(myList.isElement(4));
console.log(myList.pop(1));
console.log(myList);

