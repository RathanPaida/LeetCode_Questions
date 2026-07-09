/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const dictionary = {};    
    for (let obj of arr1) {
        dictionary[obj.id] = obj;
    }    
    for (let obj of arr2) {
        if (dictionary[obj.id]) {
            dictionary[obj.id] = { ...dictionary[obj.id], ...obj };
        } else {
            dictionary[obj.id] = obj;
        }
    }
    return Object.values(dictionary).sort((a, b) => a.id - b.id);
};