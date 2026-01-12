# 150. Evaluate Reverse Polish Notation

> Medium

You are given an array of strings `tokens` that represents an **arithmetic expression in Reverse Polish Notation**.  
Evaluate the expression and *return the value* of the expression.

Valid operators are `+`, `-`, `*`, and `/`.  
Each operand may be an integer or another expression.  
The division between two integers should **truncate toward zero**.

### Example:
- Input: `tokens = ["2","1","+","3","*"]`  
- Output: `9`  
- Explanation: `((2 + 1) * 3) = 9`

- Input: `tokens = ["4","13","5","/","+"]`  
- Output: `6`  
- Explanation: `(4 + (13 / 5)) = 6`

- Input: `tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]`  
- Output: `22`  
- Explanation: `((10 * (6 / ((9 + 3) * -11))) + 17) + 5`


### Constraints:
- `1 <= tokens.length <= 10⁴`
- `tokens[i]` is either an operator (`"+","-","*","/"`) or an integer in the range `-200 <= tokens[i] <= 200`
