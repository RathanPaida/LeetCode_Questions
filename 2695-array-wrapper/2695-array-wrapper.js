class ArrayWrapper {
    /**
     * @param {number[]} nums
     */
    constructor(nums) {
        this.nums = nums;
    }
    
    /**
     * @return {number}
     */
    valueOf() {
        // Calculate and return the sum of the array's elements
        return this.nums.reduce((sum, num) => sum + num, 0);
    }
    
    /**
     * @return {string}
     */
    toString() {
        // Return the array formatted as a string enclosed in brackets
        return `[${this.nums.join(',')}]`;
    }
}