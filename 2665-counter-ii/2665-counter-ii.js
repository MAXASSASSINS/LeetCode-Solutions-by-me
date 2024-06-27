/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    function increment(){
        init++;
        return init;
    }
    function decrement(){
        init--;
        return init;
    }
    function reset(){
        init = val;
        return init;
    }
    return {
        increment, 
        decrement,
        reset
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */