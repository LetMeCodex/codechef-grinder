# [Construct String (CONSTR)](https://www.codechef.com/problems/CONSTR)
- **Difficulty Rating**: 1307
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the lexicographically smallest string `S` from which a given string `U` can be generated. The generation process involves a single operation: any character `X` in a string can be replaced by `XXX`. This operation can be applied any number of times.

For example, if `S = "a"`, it can generate `U = "a"`, `U = "aaa"`, `U = "aaaaa"`, and so on. If `S = "ab"`, it can generate `U = "ab"`, `U = "aaab"`, `U = "abbb"`, `U = "aaabbb"`, etc. We need to find the shortest possible `S` that can generate `U`, and among those, the lexicographically smallest one. Since the characters in `S` directly correspond to characters in `U` and their relative order is preserved, minimizing length will automatically lead to the lexicographically smallest `S` (as we'll be picking the characters from `U` in order).

## Intuition & Mathematical Observation

Let's analyze the effect of the operation `X -> XXX` on a single character `X` in `S`.
1.  **Zero operations**: `X` remains `X`. Length = 1.
2.  **One operation**: `X` becomes `XXX`. Length = 3.
3.  **Two operations**: If we replace the middle `X` of `XXX` with `XXX`, we get `X(XXX)X`, which is `XXXXX`. Length = 5.
4.  **In general**: Each operation increases the length of the block of identical characters by 2. Starting from a length of 1, applying `k` operations results in a block of length `1 + 2k`. This means a single character `X` in `S` can generate any block of `X`s with an **odd** length (1, 3, 5, ...).

Now, consider how `U` is structured. `U` is a sequence of blocks of identical characters (e.g., `aaabbcdddd`). We can process `U` block by block. For each block of character `c` with length `L`:

*   **Case 1: `L` is odd.**
    Since a single character `c` in `S` can generate any odd-length block of `c`s, we only need one `c` in `S` to form this block in `U`. To minimize the length of `S`, we should add exactly one `c` to `S`.

*   **Case 2: `L` is even.**
    A single character `c` in `S` can *only* generate odd-length blocks. Therefore, an even-length block of `c`s in `U` cannot be formed from a single `c` in `S`. It must be formed from at least two `c`s in `S`.
    If `S` contains `cc` (two consecutive `c`s), the first `c` can generate an odd-length block `L1 = 1 + 2k1`, and the second `c` can generate an odd-length block `L2 = 1 + 2k2`. The combined length `L1 + L2 = (1 + 2k1) + (1 + 2k2) = 2 + 2(k1 + k2)`. This sum is always an even number.
    Thus, two `c`s in `S` can generate any even-length block of `c`s in `U`. To minimize the length of `S`, we should add exactly two `c`s to `S`.

This strategy ensures that for each block in `U`, we add the minimum necessary characters to `S`. Since the blocks are processed sequentially, this also guarantees the lexicographically smallest `S`.

**Example:** Let `U = "aaabbbcccdd"`
1.  **Block "aaa"**: Character 'a', length 3 (odd). Add 'a' to `S`. `S = "a"`
2.  **Block "bbb"**: Character 'b', length 3 (odd). Add 'b' to `S`. `S = "ab"`
3.  **Block "ccc"**: Character 'c', length 3 (odd). Add 'c' to `S`. `S = "abc"`
4.  **Block "dd"**: Character 'd', length 2 (even). Add 'dd' to `S`. `S = "abcdd"`

The final string `S` is `"abcdd"`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    We iterate through the input string `U` exactly once. The outer `while` loop advances a pointer `i` through `U`. The inner `while` loop (which counts consecutive characters) advances a pointer `j` from `i` to the end of the current block. After the inner loop, `i` is updated to `j`, effectively moving `i` to the start of the next block. Thus, each character of `U` is visited a constant number of times. Appending characters to `s_res` takes amortized $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given $N \le 10^5$ and $T \le 10$, this is $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**: $O(N)$ per test case.
    We store the input string `U`, which takes $O(N)$ space. We also construct the result string `s_res`. In the worst case (e.g., `U = "aabbcc..."`), `s_res` can have a length equal to `N`. Therefore, `s_res` takes $O(N)$ space. All other variables use $O(1)$ space.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Not strictly needed for this problem, but often useful
#include <algorithm> // Not strictly needed for this problem, but often useful

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of string U
    std::string u;
    std::cin >> u; // Read the string U

    std::string s_res = ""; // Initialize an empty string to build S
    int i = 0; // Pointer to iterate through string U

    // Iterate through U, processing it block by block of identical characters
    while (i < n) {
        char current_char = u[i]; // Get the character of the current block
        int count = 0; // Count of consecutive occurrences of current_char

        // Count how many times current_char appears consecutively
        int j = i;
        while (j < n && u[j] == current_char) {
            count++;
            j++;
        }

        // Logic to determine how many characters to add to S_res based on block length:
        // A single character 'c' in S can be expanded to any block of 'c's of odd length (1, 3, 5, ...).
        // This is because each operation 'X -> XXX' increases the length of the string by 2.
        // Starting from length 1 (no operations), all reachable lengths are 1 + 2k.
        //
        // If the current block length 'count' is odd:
        // It can be generated from a single 'current_char' in S.
        // To minimize S, we add only one 'current_char'.
        if (count % 2 == 1) {
            s_res.push_back(current_char);
        } 
        // If the current block length 'count' is even:
        // It cannot be generated from a single 'current_char' in S (as single chars only produce odd lengths).
        // It must be generated from at least two 'current_char's in S.
        // For example, if S has "cc", the first 'c' can become 'c' (length 1) and the second 'c' can become 'ccc' (length 3).
        // This results in "cccc" (length 4).
        // In general, two characters in S, say S_k and S_{k+1}, both being 'c', can generate a block of 'c's of total length L_k + L_{k+1},
        // where L_k and L_{k+1} are odd. The sum of two odd numbers is always even.
        // Thus, any even length block can be formed from two characters in S.
        // To minimize S, we add exactly two 'current_char's.
        else { // count % 2 == 0
            s_res.push_back(current_char);
            s_res.push_back(current_char);
        }
        
        // Move the pointer 'i' to the start of the next block
        i = j; 
    }
    std::cout << s_res << "\n"; // Output the constructed string S
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}
```