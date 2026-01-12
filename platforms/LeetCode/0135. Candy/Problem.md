# 135. Candy

> Hard

There are `n` children standing in a line. You are given an integer array `ratings` where `ratings[i]` represents the **rating of the ith child**.  
You must distribute **candies** to the children subject to the following rules:
- Each child must have **at least one** candy.
- Children with a **higher rating** than an adjacent child must receive **more candies** than that neighbor.

Return *the minimum number of candies* you must distribute to satisfy the rules.

### Example:
- Input: `ratings = [1,0,2]`  
- Output: `5`  
- Explanation: One optimal distribution is `[2,1,2]`.

- Input: `ratings = [1,2,2]`  
- Output: `4`  
- Explanation: One optimal distribution is `[1,2,1]`.

### Constraints:
- `n == ratings.length`
- `1 <= n <= 2 * 10⁴`
- `0 <= ratings[i] <= 2 * 10⁴`
