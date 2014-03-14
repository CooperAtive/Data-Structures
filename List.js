var list =
    { head: 1,
        tail: { head: 2,
            tail: { head: 3,
                tail: { head: 4,
                    tail: { head: 5,
                        tail: null
                    }
                }
            }
        }
};

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

console.log(JSON.stringify(listReverse(list)));


