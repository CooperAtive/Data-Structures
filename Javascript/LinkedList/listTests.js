'use strict';
/*jshint -W098 */
/*jshint expr: true*/

var LinkedList = require('./LinkedList').LinkedList;
var reverseList = require('./reverseList').reverseList;
var mergeLists = require('./mergeLists').mergeLists;
var myList1 = new LinkedList();

var chai = require('chai');
var expect = chai.expect;
var should = chai.should();

describe('LinkedList', function(){
    var list;
    var list2;
    beforeEach(function() {
        list = new LinkedList();
        list.push(3);
        list.push(1);
        list.push(2);
        list2 = new LinkedList();
        list2.push(4);
        list2.push(6);
        list2.push(5);
    });

    describe('constructor', function() {
        it('exists', function() {
            expect(list).to.be.ok;
        });
    });

    describe('push', function(){
        it('pushes elements in sorted order', function() {
            expect(JSON.stringify(list)).to.be.eql(JSON.stringify({head:{value:1, next:{value:2,next:{value: 3}}}}));
        });
    });

    describe('size', function(){
        it('list to have size 3', function() {
            expect(list.size()).to.be.eql(3);
        });
    });

    describe('mergeLists', function(){
        it('can be merged into one list in sorted order', function() {
            var list3 = mergeLists(list, list2);
            expect(list3.size()).to.be.eql(6);
            expect(list3.pop(5)).to.be.eql(6);
            expect(list3.pop(3)).to.be.eql(4);
        });
    });

    describe('pop', function(){
        it('pop removes element at given index and returns its value', function() {
            expect(list.pop(1)).to.be.eql(2);
            expect(list.size()).to.be.eql(2);
        });
    });

});
