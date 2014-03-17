"use strict";
/*jshint -W055 */
/*jshint -W098 */

/*
var BST = function BST(){

    var root;
    function constructor(){
        this.root = {};
    }

    constructor.prototype.insert = function(node, value){
        console.log(node);
        if (node || node === null){
            console.log("made it here");
            node = new TreeNode(value);
        }
        if (value <= node){
            console.log("less than");
            this.insert(node.left, value);
        }
        if (value > node) {
            console.log("greater than");
            this.insert(node.right, value);
        }
    };

    constructor.prototype.rangeSearch = function(min, max){

    };
    return new constructor();
};
*/

var TreeNode = require("./TreeNode").TreeNode;

var BST = function BST() {

    var root;

    function constructor() {
        this.root = new TreeNode(null);
    }

    constructor.prototype.insert = function(node, value) {
        if (node.value === null) {
            node.value = value;
            return true;
        }
        if (node.value > value) {
            if(node.left === null)
                node.left = new TreeNode(null);
            return this.insert(node.left, value);
        }
        if (node.value <= value) {
            if(node.right === null)
                node.right = new TreeNode(null);
            return this.insert(node.right, value);
        }
    };

    constructor.prototype.arrayToBST = function(array) {
        var middle = Math.floor(array.length/2);
        this.insert(this.root, array[middle]);
        for (var i = 1; i < middle+1; i++){
            this.insert(this.root, array[middle + i]);
            this.insert(this.root, array[middle - i]);
        }
    };

    constructor.prototype.rangeSearchBST = function (node, min, max) {
        var acc = {
            acc:[]
            };
        this.rangeSearchBST_h(acc, node, min, max);
        return acc.acc;
    };

    constructor.prototype.rangeSearchBST_h = function (acc, node, min, max) {
        if (node.left && node.left.value >= min)
            this.rangeSearchBST_h(acc, node.left, min, max);
        acc.acc.push(node.value);
        if (node.right && node.right.value <= max)
            this.rangeSearchBST_h(acc, node.right, min, max);
        return;

    };

    return new constructor();
};

var array = [1,5,6,22,34,46,48,51,63,69,72,83,95];
var bst = new BST();
bst.arrayToBST(array);
var cooler = bst.rangeSearchBST(bst.root, 7, 64);
console.log(JSON.stringify(cooler));
