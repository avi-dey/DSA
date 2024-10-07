
# Understanding `n = n & (n - 1)` in Bit Manipulation

The expression `n = n & (n - 1);` is a common bit manipulation trick that **clears the lowest set bit** (i.e., the rightmost `1` bit) in an integer `n`. 

## Explanation:
- `n - 1` flips all the bits after (and including) the rightmost `1` bit in `n`.
- When `n` is bitwise AND-ed with `n - 1`, it results in turning off the rightmost `1` bit of `n`.

## Example:
Let's take a few examples to see how it works:

### Example 1:
- Suppose `n = 12` (binary: `1100`).
- `n - 1` would be `11` (binary: `1011`).
- `n & (n - 1)` would then be:
    ```
    1100 (n)
    1011 (n - 1)
    ----
    1000 (result)
    ```
- Result: `1000` (which is `8` in decimal).
- Here, the rightmost `1` bit in `1100` was cleared.

### Example 2:
- Suppose `n = 10` (binary: `1010`).
- `n - 1` would be `9` (binary: `1001`).
- `n & (n - 1)` would then be:
    ```
    1010 (n)
    1001 (n - 1)
    ----
    1000 (result)
    ```
- Result: `1000` (which is `8` in decimal).
- The rightmost `1` bit in `1010` was cleared.

## Use Cases:
- **Counting the number of set bits (Hamming weight):** This trick is often used in a loop to count the number of `1` bits in a number. Each time `n = n & (n - 1);` is executed, the number of `1` bits decreases by `1` until `n` becomes `0`.
- **Checking if a number is a power of 2:** A number `n` is a power of 2 if it has only one `1` bit in its binary representation. So, `n` is a power of 2 if `n & (n - 1)` results in `0`.

This trick is efficient because it directly targets and clears the lowest set bit, making it a powerful tool in bit manipulation tasks.
