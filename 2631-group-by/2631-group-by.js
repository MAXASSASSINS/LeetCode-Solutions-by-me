/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const obj = {};
    
    this.forEach(x => {
        let key = fn(x);
        if(key in obj)
            obj[key].push(x);
        else
            obj[key] = [x];
    })
    
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */