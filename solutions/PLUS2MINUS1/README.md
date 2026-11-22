# [Plus 2 or Minus 1 (PLUS2MINUS1)](https://www.codechef.com/problems/PLUS2MINUS1)
- **Difficulty Rating**: 1098
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the total number of distinct integer values that a variable `X` can take. Initially, `X` is `0`. We are allowed to perform at most `Y` operations. Each operation can either change `X` to `X + 2` or `X` to `X - 1`. We need to output this count for several test cases.

## Intuition & Mathematical Observation

Let's analyze the possible values of `X` based on the number of operations performed.

Suppose we perform exactly `k` operations, where `0 \le k \le Y`.
Let `p` be the number of times we apply the `X = X + 2` operation, and `m` be the number of times we apply the `X = X - 1` operation.
From the definition, the total number of operations is `p + m = k`.
The final value of `X` will be `2p - m` (since `X` starts at `0`).

We can express `m` in terms of `k` and `p`: `m = k - p`.
Substituting this into the expression for `X`:
`X = 2p - (k - p) = 3p - k`.

Since `p` represents the number of `+2` operations out of `k` total operations, `p` can range from `0` (all operations are `-1`) to `k` (all operations are `+2`).
For a fixed `k`, the possible values of `X` are:
*   If `p = 0`: `X = 3(0) - k = -k`
*   If `p = 1`: `X = 3(1) - k = 3 - k`
*   ...
*   If `p = k`: `X = 3(k) - k = 2k`

Thus, for exactly `k` operations, `X` can take any value in the set `{-k, -k+3, -k+6, ..., 2k}`. Notice that all these values are congruent to `-k \pmod 3`.

Since we can perform *at most* `Y` operations, `k` can be any integer from `0` to `Y`. We are interested in the union of all possible values `X` can take for `k \in [0, Y]`.

Let's determine the overall minimum and maximum possible values `X` can reach:
*   The minimum value is achieved by performing `Y` operations, all of which are `X = X - 1`. This results in `X = -Y` (when `k=Y, p=0`).
*   The maximum value is achieved by performing `Y` operations, all of which are `X = X + 2`. This results in `X = 2Y` (when `k=Y, p=Y`).

So, all reachable values of `X` must lie within the range `[-Y, 2Y]`. The total number of integers in this range is `2Y - (-Y) + 1 = 3Y + 1`.

Now, we need to determine if all integers in `[-Y, 2Y]` are reachable.

**Special Case: Y = 0**
If `Y = 0`, no operations can be performed. `X` remains `0`.
The set of distinct values is `{0}`. The count is `1`.
Our general formula `3Y` would give `0`, which is incorrect. Hence, `Y=0` is a special case.

**Case: Y >= 1**
Let's test with small values of `Y`:
*   **Y = 1**:
    *   `k=0`: `X=0`
    *   `k=1`: `X \in \{-1, 2\}` (from `3p-1` with `p=0,1`)
    *   The union of reachable values is `{-1, 0, 2}`. The count is `3`.
    *   The range `[-Y, 2Y]` is `[-1, 2]`, which contains `{-1, 0, 1, 2}`. The value `1` is missing.
*   **Y = 2**:
    *   `k=0`: `X=0`
    *   `k=1`: `X \in \{-1, 2\}`
    *   `k=2`: `X \in \{-2, 1, 4\}` (from `3p-2` with `p=0,1,2`)
    *   The union of reachable values is `{-2, -1, 0, 1, 2, 4}`. The count is `6`.
    *   The range `[-Y, 2Y]` is `[-2, 4]`, which contains `{-2, -1, 0, 1, 2, 3, 4}`. The value `3` is missing.

It appears that for `Y \ge 1`, exactly one value in the range `[-Y, 2Y]` is unreachable: `2Y - 1`.
Let's prove that `2Y - 1` is unreachable for `Y \ge 1`.
Suppose `2Y - 1` is reachable. Then `2Y - 1 = 3p - k` for some `0 \le p \le k \le Y`.

From `2Y - 1 = 3p - k`, we can write `3p = 2Y - 1 + k`.
This implies that `2Y - 1 + k` must be a multiple of 3.

Also, since `p \le k`, we have `(2Y - 1 + k) / 3 \le k`.
Multiplying by 3 (which is positive, so inequality direction is preserved):
`2Y - 1 + k \le 3k`
Rearranging the terms:
`2Y - 1 \le 2k`
Dividing by 2:
`Y - 1/2 \le k`

Since `k` must be an integer, this implies `k \ge Y`.
Combining this with the constraint `k \le Y` (because we can perform at most `Y` operations), it forces `k` to be exactly `Y`.

Now, substitute `k = Y` back into the condition that `2Y - 1 + k` must be a multiple of 3:
`2Y - 1 + Y = 3Y - 1`.
Let's check `3Y - 1 \pmod 3`:
`3Y - 1 \equiv 0 - 1 \pmod 3 \equiv -1 \pmod 3 \equiv 2 \pmod 3`.
Since `3Y - 1` is congruent to `2 \pmod 3`, it is not a multiple of 3.
Therefore, `2Y - 1` cannot be formed with `k=Y` operations.
Since `k` must be `Y` for `2Y-1` to potentially be reachable, and it cannot be formed with `Y` operations, `2Y-1` is indeed unreachable.

It can be shown that all other `3Y` integers in the range `[-Y, 2Y]` are reachable.
Thus, for `Y \ge 1`, the number of distinct values `X` can take is `(Total integers in range) - (Unreachable integers) = (3Y + 1) - 1 = 3Y`.

**Conclusion:**
*   If `Y = 0`, the answer is `1`.
*   If `Y \ge 1`, the answer is `3 * Y`.

## Complexity Analysis

*   **Time Complexity**: The solution involves reading the number of test cases `T`, and for each test case, reading `Y` and performing a constant number of arithmetic operations and an `if-else` check. Therefore, the time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few integer variables (`T`, `Y`, `result`) to store input and output values. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)

// Using namespace std; is common in competitive programming to avoid writing std:: repeatedly
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL);                   // Unties cin from cout, so cin doesn't flush cout

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int Y; // Variable to store the maximum number of moves for the current test case
        cin >> Y; // Read the value of Y

        long long result; // Use long long for result to be absolutely safe,
                          // although for Y up to 10^6, 3*Y (3*10^6) fits within a standard int.
                          // It's good practice to use long long for calculations that might exceed int limits.

        if (Y == 0) {
            // If no moves can be performed, X remains 0.
            // Only 1 distinct value: {0}.
            result = 1;
        } else { // For Y >= 1
            // As derived in the intuition, for Y >= 1, the number of distinct values is 3 * Y.
            // This covers Y=1 (3 values: -1, 0, 2) and Y>=2 (e.g., Y=2 gives 6 values).
            // The range of values is [-Y, 2Y], which contains 3Y+1 integers.
            // The value 2Y-1 is always unreachable for Y >= 1.
            // Therefore, the number of distinct values is (3Y+1) - 1 = 3Y.
            result = 3LL * Y; // Use 3LL to ensure the multiplication is performed using long long.
                              // This prevents potential overflow if Y was very large (e.g., close to INT_MAX)
                              // and the result would exceed INT_MAX before being assigned to a long long.
        }
        cout << result << "\n"; // Output the calculated result for the current test case, followed by a newline
    }

    return 0; // Indicate successful execution of the program
}

```