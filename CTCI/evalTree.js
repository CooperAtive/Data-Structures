function evalExp(obj){
    if (obj.val) return obj.val;
    if (obj.op === '+') return evalExp(obj.o1) + evalExp(obj.o2);
    return evalExp(obj.o1) * evalExp(obj.o2);
}

var obj = { op: '+', o1: {op: '*', o1: {val: 3}, o2: {val: 2}}, o2: {val: 4}};

function evalExp2(obj){
    return (obj.val) ? obj.val : (obj.op === '+') ? evalExp2(obj.o1) + evalExp2(obj.o2) : evalExp2(obj.o1) * evalExp2(obj.o2);
}

console.log(evalExp(obj));
console.log(evalExp2(obj));
