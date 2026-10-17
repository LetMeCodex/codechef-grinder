# [Jewels and Stones (STONES)](https://www.codechef.com/problems/STONES)
- **Difficulty Rating**: 1248
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to determine how many of our "stones" are also "jewels". We are given two strings:
1.  `J`: Represents the types of characters that are considered jewels. All characters in `J` are distinct.
2.  `S`: Represents the characters of stones we possess.

We need to count how many characters in string `S` are present in string `J`. The comparison is case-sensitive.

**Example:**
If `J = "aA"` and `S = "aAbc"`, the jewels are 'a' and 'A'.
In `S`, 'a' is a jewel, 'A' is a jewel, 'b' is not, 'c' is not.
The count would be 2.

## Intuition & Mathematical Observation

The core of this problem is to efficiently check, for each character in `S`, if it exists in `J`.

1.  **Naive Approach**: For each character in `S`, iterate through the entire `J` string to see if it matches. If `|J|` is the length of `J` and `|S|` is the length of `S`, this approach would have a time complexity of $O(|S| \cdot |J|)$. Given the constraints ($|J|, |S| \le 100$), this would be $100 \cdot 100 = 10000$ operations per test case, which might pass, but it's not the most efficient.

2.  **Optimized Approach (Hash Set / Boolean Array)**: We need a faster way to check for the presence of a character.
    *   Since the characters are standard ASCII (English letters, digits, etc.), their ASCII values fall within a small, contiguous range (0-127, or 0-255 for extended ASCII).
    *   We can use a boolean array (or a hash set like `std::unordered_set<char>`) to mark which characters are jewels. A boolean array of size 256 (to cover all possible `char` values) is ideal for $O(1)$ average-case lookup.
    *   **Observation**: We only care *if* a character is a jewel, not how many times it appears in `J`. So, a simple `true`/`false` flag for each possible character is sufficient.

The strategy is:
1.  Initialize a boolean array (e.g., `is_jewel[256]`) to all `false`.
2.  Iterate through the `J` string. For each character `c` in `J`, set `is_jewel[c]` to `true`. This pre-processes the jewel types.
3.  Initialize a counter `jewel_count` to 0.
4.  Iterate through the `S` string. For each character `c` in `S`, check `is_jewel[c]`. If it's `true`, increment `jewel_count`.
5.  Print `jewel_count`.

This approach leverages the small and fixed character set to achieve very fast lookups.

## Complexity Analysis

Let:
*   $|J|$ be the length of the string `J`.
*   $|S|$ be the length of the string `S`.
*   $C$ be the size of the character set (e.g., 256 for extended ASCII).
*   $T$ be the number of test cases.

-   **Time Complexity**:
    *   **Initialization**: Creating and initializing the `is_jewel` boolean array takes $O(C)$ time.
    *   **Processing `J`**: Iterating through `J` to mark jewel characters takes $O(|J|)$ time. Each access/assignment to `is_jewel` is $O(1)$.
    *   **Processing `S`**: Iterating through `S` to count jewels takes $O(|S|)$ time. Each lookup in `is_jewel` is $O(1)$.
    *   **Total for one test case**: $O(C + |J| + |S|)$. Since $C$ is a constant (256), this simplifies to $O(|J| + |S|)$.
    *   **Total for $T$ test cases**: $O(T \cdot (|J| + |S|))$.
    *   Given constraints ($|J|, |S| \le 100$, $T \le 100$), the maximum operations would be roughly $100 \cdot (100 + 100) = 20,000$, which is extremely fast and well within typical time limits.

-   **Space Complexity**:
    *   **Storing `J` and `S`**: $O(|J| + |S|)$ to store the input strings.
    *   **`is_jewel` array**: $O(C)$ space for the boolean array. Since $C$ is a constant (256 bytes for `std::vector<bool>` or 256 bits if optimized), this is considered constant space relative to the input string lengths.
    *   **Total**: $O(|J| + |S| + C)$. This simplifies to $O(|J| + |S|)$ as $C$ is a constant.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout, std::endl
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector<bool> (or can use a simple bool array)

// Function to solve a single test case
void solve() {
    std::string J, S;
    std::cin >> J >> S; // Read the jewel string J and stone string S

    // Use a boolean array to mark jewel characters for O(1) lookup.
    // A size of 256 covers all possible values for an unsigned char (0-255),
    // which is safe for all ASCII characters, including English lower and upper case.
    std::vector<bool> is_jewel(256, false); 

    // Populate the is_jewel array: mark all characters present in J as true.
    for (char jewel_char : J) {
        // static_cast<unsigned char> is used for safe indexing,
        // as char can be signed or unsigned depending on the compiler/platform,
        // and negative char values would lead to out-of-bounds access.
        is_jewel[static_cast<unsigned char>(jewel_char)] = true;
    }

    int jewel_count = 0;
    // Iterate through each character in the stone string S.
    for (char c : S) { 
        // Check if the current stone character 'c' is a jewel.
        if (is_jewel[static_cast<unsigned char>(c)]) {
            jewel_count++; // Increment count if it's a jewel
        }
    }

    std::cout << jewel_count << std::endl; // Output the total count of jewels
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Unties cin from cout

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times for each test case
        solve();   // Call the solve function for each test case
    }
    return 0; // Indicate successful execution
}
```