'use strict';
/*jshint -W055 */
/*jshint -W098 */

var TreeNode = require('./TreeNode').TreeNode;

var BST = function BST(){

    function constructor(){ }

    constructor.prototype.insert = function(root, value){
        if (root === null){
            root = new TreeNode(value);
        }
        if (value < root){
            root.left = this.insert(root.left, value);
        }
        if (value > root) {
            this.root.right = this.insert(this.right, value);
        }
    };

    constructor.prototype.rangeSearch = function(min, max){

    };
    return new constructor();
};
var node = new TreeNode(1);
console.log(node);
var array = [1, 2, 3, 4];
var bst = new BST();
for (var i = 0; i < array.length; i++){
    bst.insert(array[i]);
}
console.log(JSON.stringify(bst));
