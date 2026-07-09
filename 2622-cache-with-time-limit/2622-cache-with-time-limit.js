var TimeLimitedCache = function() {
    // We use a Map to store key -> { value, timerId }
    this.cache = new Map();
};

/** * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const hasKey = this.cache.has(key);
    
    // If the key already exists, cancel its pending expiration timer
    if (hasKey) {
        clearTimeout(this.cache.get(key).timerId);
    }
    
    // Create a new expiration timer
    const timerId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    
    // Store the value and the timerId together
    this.cache.set(key, { value, timerId });
    
    return hasKey;
};

/** * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cache.has(key)) {
        return this.cache.get(key).value;
    }
    return -1;
};

/** * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */