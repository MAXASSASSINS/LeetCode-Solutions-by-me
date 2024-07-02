/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let prev = -1;
    let curr = -1;
    
    while(true){
        if(prev === -1){
            prev = 0;
            yield 0;
        }
        else if(curr === -1){
            curr = 1;
            yield 1;
        }
        else{
            let val = curr + prev;
            prev = curr;
            curr = val;
            yield val;
        }
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */