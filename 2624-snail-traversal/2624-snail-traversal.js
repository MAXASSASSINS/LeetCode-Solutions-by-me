/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if(rowsCount * colsCount !== this.length) return [];
    
    let result = [];
    for(let i = 0; i < rowsCount; i++){
        let temp = [];
        temp.length = colsCount;
        result.push(temp);
    }
    
    for(let i = 0; i < this.length;){
        let col = Math.floor(i / rowsCount);
        if(col % 2 == 0){
            for(let j = 0; j < rowsCount; j++){
                result[j][col] = this[i];
                i++;
            }
        }
        else{
            for(let j = rowsCount - 1; j >= 0; j--){
                result[j][col] = this[i];
                i++;
            }
        }
    }
    
    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */