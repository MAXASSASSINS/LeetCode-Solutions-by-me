/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let chunks = [];
    let i = 0;
    while(arr.length > 0){
        let temp = arr.splice(0, size);
        chunks.push(temp);
        i += size - 1;
    }
    
    return chunks;
};
