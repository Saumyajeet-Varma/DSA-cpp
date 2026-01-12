# 146. LRU Cache

> Medium

Design a **data structure** that follows the constraints of a **Least Recently Used (LRU) cache**.  
Implement the `LRUCache` class:

- `LRUCache(int capacity)` initializes the LRU cache with **positive size** `capacity`.
- `int get(int key)` returns the value of the `key` if the key exists in the cache, otherwise returns `-1`.
- `void put(int key, int value)` updates the value of the `key` if the `key` exists.  
  Otherwise, adds the `key-value` pair to the cache.  
  If the number of keys exceeds the `capacity` after the insertion, **evict** the **least recently used** key.

### Example:
- Input: `["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"], [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]`
- Output: `[null, null, null, 1, null, -1, null, -1, 3, 4]`

### Constraints:
- `1 <= capacity <= 3000`
- `0 <= key <= 10⁴`
- `0 <= value <= 10⁵`
- At most `2 * 10⁵` calls will be made to `get` and `put`
