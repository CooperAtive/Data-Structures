'use strict';
/*jshint -W055 */

var ListNode = require('./ListNode').ListNode;
var LinkedList = function LinkedList(){
    var self = this;
    this.listSize = 0;

    function constructor() { }

    //Sorts list in ascending order
    constructor.prototype.push = function(element) {
        var node = new ListNode(element);
        if (this.empty() || this.head.value >= node.value) {
            node.next = this.head;
            this.head = node;
        }
        else{
            var current = this.head;
            while (current.next && current.next.value < node.value){
                    current = current.next;
                }
                node.next = current.next;
                current.next = node;
        }
        self.listSize++;
    };

    constructor.prototype.pop = function(pos) {
        if (pos >= this.size()) return false;
        if (pos === 0) {
            var temp = this.head.value;
            this.head = this.head.next;
            return temp;
        }
        var previous = this.head, //keep a pointer to previous node
        current;
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

    constructor.prototype.empty = function() {
        if (this.head === undefined) return true;
        return false;
    };

    return new constructor();
};

module.exports.LinkedList = LinkedList;
