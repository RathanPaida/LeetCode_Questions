/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for(i in obj){
        return false;
    }
    return true;
};