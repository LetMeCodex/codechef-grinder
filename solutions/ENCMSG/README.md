# [Encoding Message (ENCMSG)](https://www.codechef.com/problems/ENCMSG)
- **Difficulty Rating**: 1027
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to encode a given string `S` of length `N`, which consists of lowercase English letters. The encoding process involves two distinct steps:

1.  **Swap Adjacent Characters**: Swap characters in pairs. For example, the first character is swapped with the second, the third with the fourth, and so on. If the string length `N` is odd, the last character remains in its original position.
2.  **Replace Characters**: After the swapping, each character `c` in the modified string is replaced with its "opposite" character in the English alphabet. This means 'a' becomes 'z', 'b' becomes 'y', 'c' becomes 'x', and so forth, until 'z' becomes 'a'.

We need to output the final encoded string for each test case.

## Intuition & Mathematical Observation

Let's break down the two steps of the encoding process:

### Step 1: Swapping Adjacent Characters

This step is a straightforward iteration. We need to iterate through the string and swap characters at `s[i]` and `s[i+1]`. Since we are swapping pairs, we should increment our loop counter by 2 in each step.

*   We can use a `for` loop starting from `i = 0`.
*   The loop condition should ensure that `i+1` is a valid index. So, `i` should go up to `n-2` (or `n-1` if we use `i < n - 1` and `i += 2`).
*   Inside the loop, `std::swap(s[i], s[i+1])` performs the required swap.
*   If `N` is odd, the last character `s[N-1]` will naturally be skipped by this loop structure, as `i` will never reach `N-1` if `N-1` is odd (e.g., for `N=5`, `i` goes `0, 2`, skipping `4`). This correctly handles the condition for odd length strings.

**Example**: For `S = "abcde"` (N=5)
*   `i = 0`: `s[0]` ('a') and `s[1]` ('b') are swapped. String becomes `"bacde"`.
*   `i = 2`: `s[2]` ('c') and `s[3]` ('d') are swapped. String becomes `"badce"`.
*   `i = 4`: Loop condition `i < n - 1` (i.e., `4 < 4`) is false. Loop terminates.
*   Final string after step 1: `"badce"`.

### Step 2: Replacing Characters with their "Opposites"

This step requires a mapping from an original character to its opposite. Let's observe the pattern:
*   'a' (ASCII 97) maps to 'z' (ASCII 122)
*   'b' (ASCII 98) maps to 'y' (ASCII 121)
*   'c' (ASCII 99) maps to 'x' (ASCII 120)

Notice that the sum of the ASCII values of an original character and its opposite is constant:
*   `'a' + 'z' = 97 + 122 = 219`
*   `'b' + 'y' = 98 + 121 = 219`
*   `'c' + 'x' = 99 + 120 = 219`

This leads to a simple mathematical formula for the replacement. If `original_char` is the character to be replaced, and `new_char` is its opposite, then:
`original_char + new_char = 'a' + 'z'`
Therefore, `new_char = 'a' + 'z' - original_char`.

This formula can be applied to each character in the string after the first step.

**Example**: For `S = "badce"` (after step 1)
*   `s[0] = 'b'`: `'a' + 'z' - 'b' = 'y'`. String becomes `"yadce"`.
*   `s[1] = 'a'`: `'a' + 'z' - 'a' = 'z'`. String becomes `"yzdce"`.
*   `s[2] = 'd'`: `'a' + 'z' - 'd' = 'w'`. String becomes `"yzwe"`.
*   `s[3] = 'c'`: `'a' + 'z' - 'c' = 'x'`. String becomes `"yzwxe"`.
*   `s[4] = 'e'`: `'a' + 'z' - 'e' = 'v'`. String becomes `"yzwxv"`.
*   Final encoded string: `"yzwxv"`.

The solution code directly implements these two steps using standard C++ string manipulation and character arithmetic. Fast I/O is also enabled for efficiency.

## Complexity Analysis

*   **Time Complexity**:
    *   The outer `while (t--)` loop runs `T` times, where `T` is the number of test cases.
    *   Inside each test case:
        *   Reading `n` and the string `s` takes `O(N)` time, where `N` is the length of the string.
        *   The first `for` loop for swapping characters iterates `N/2` times. Each `std::swap` operation takes `O(1)` time. So, this step takes `O(N)` time.
        *   The second `for` loop for replacing characters iterates `N` times. Each character replacement (arithmetic operation) takes `O(1)` time. So, this step also takes `O(N)` time.
        *   Printing the final string takes `O(N)` time.
    *   Therefore, for a single test case, the total time complexity is `O(N)`.
    *   For `T` test cases, the overall time complexity is $O(T \cdot N)$. Given `N` up to 1000 and `T` up to 100, $100 \times 1000 = 10^5$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   The primary space usage is for storing the input string `s`, which requires `O(N)` space.
    *   All operations are performed in-place on the string `s`, and no additional data structures whose size depends on `N` are created.
    *   Thus, the overall space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::swap

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n;
        std::cin >> n; // Read the length of the string
        std::string s;
        std::cin >> s; // Read the string

        // Step 1: Swap characters in pairs
        // Iterate with a step of 2 to process pairs (s[i], s[i+1])
        // The loop condition i < n - 1 ensures that i+1 is always a valid index.
        // If n is odd, the last character is naturally skipped and remains in place.
        for (int i = 0; i < n - 1; i += 2) {
            std::swap(s[i], s[i + 1]);
        }

        // Step 2: Replace characters with their 'opposite' in the alphabet
        // 'a' becomes 'z', 'b' becomes 'y', ..., 'z' becomes 'a'
        // The mapping is based on the observation that char_code(original) + char_code(new) = char_code('a') + char_code('z')
        // So, char_code(new) = char_code('a') + char_code('z') - char_code(original)
        for (int i = 0; i < n; ++i) {
            s[i] = 'a' + ('z' - s[i]);
        }

        std::cout << s << "\n"; // Print the encoded string followed by a newline
    }
    return 0; // Indicate successful execution
}

```