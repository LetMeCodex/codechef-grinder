# [Chef and Secret Ingredients (CHEFING)](https://www.codechef.com/problems/CHEFING)
- **Difficulty Rating**: 1376
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has $N$ dishes, and each dish is made up of a list of ingredients. An ingredient is considered "special" if it is present in *all* $N$ dishes. All ingredients are represented by lowercase English letters ('a' through 'z'). The task is to find the total count of such special ingredients.

For example, if there are two dishes:
1. "apple" (ingredients: a, p, l, e)
2. "apply" (ingredients: a, p, l, y)
The ingredients common to both are 'a', 'p', 'l'. So, there are 3 special ingredients.

## Intuition & Mathematical Observation

The problem asks us to find the intersection of ingredient sets across $N$ dishes. Since ingredients are limited to lowercase English letters ('a' through 'z'), there are only 26 possible unique ingredients. This small, fixed number of possibilities is a strong indicator that a **bitmask** approach would be highly efficient.

Here's the intuition:
1.  **Represent Ingredients with Bits**: We can map each lowercase letter to a unique bit position. For instance, 'a' can correspond to bit 0, 'b' to bit 1, ..., and 'z' to bit 25. A 32-bit integer is sufficient to store the presence/absence of all 26 ingredients.
2.  **Mask for Each Dish**: For each dish, we can create a bitmask that represents all the unique ingredients present in that specific dish. If an ingredient `c` is in the dish, we set the `(c - 'a')`-th bit in its mask.
3.  **Finding Common Ingredients**: To find ingredients common to *all* dishes, we can maintain a `common_mask`.
    *   Initially, `common_mask` should represent that *all* 26 ingredients are potentially special. This means all bits from 0 to 25 are set.
    *   For each dish, after computing its `current_dish_mask`, we update `common_mask` by performing a bitwise AND operation: `common_mask = common_mask & current_dish_mask`.
    *   The bitwise AND operation ensures that a bit remains set in `common_mask` only if it was *already* set (meaning the ingredient was common to all previous dishes) AND it is *also* set in the `current_dish_mask` (meaning the ingredient is present in the current dish). If an ingredient is missing from *any* dish, its corresponding bit will be cleared in `common_mask` and will never be set again.
4.  **Counting Special Ingredients**: After processing all $N$ dishes, the `common_mask` will have bits set only for those ingredients that were present in *every single dish*. The final step is to count the number of set bits in this `common_mask`. C++ provides a convenient built-in function `__builtin_popcount` (a GCC extension) for this purpose.

This approach is efficient because bitwise operations are extremely fast, and the number of bits (26) is very small.

## Complexity Analysis

Let $T$ be the number of test cases, $N$ be the number of dishes per test case, and $L_{max}$ be the maximum length of an ingredient string (dish name).

-   **Time Complexity**:
    *   For each test case:
        *   We iterate $N$ times (once for each dish).
        *   Inside this loop, for each dish string $S$:
            *   Reading the string takes $O(|S|)$ time.
            *   Building `current_dish_mask` involves iterating through each character of $S$. This takes $O(|S|)$ operations, where each operation (bit setting) is $O(1)$.
            *   Updating `common_mask` with a bitwise AND is an $O(1)$ operation.
        *   After the loop, counting set bits using `__builtin_popcount` is an $O(1)$ operation for a fixed-size integer (like 32-bit or 64-bit).
    *   Therefore, the time complexity per test case is $O(N \cdot L_{max})$.
    *   The total time complexity across all test cases is $O(T \cdot N \cdot L_{max})$.
    *   Given constraints: $T \le 100$, $N \le 100$, $L_{max} \le 100$.
        Maximum operations: $100 \cdot 100 \cdot 100 = 10^6$, which is well within typical time limits for competitive programming problems.

-   **Space Complexity**:
    *   `N`, `common_mask`, `current_dish_mask`, `special_ingredients_count` all take $O(1)$ space (fixed-size integers).
    *   The string `S` to store the current dish's ingredients takes $O(L_{max})$ space. This space is reused for each dish.
    *   Therefore, the total space complexity is $O(L_{max})$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <string>   // Required for using std::string to read dish names
// #include <bits/stdc++.h> // A common competitive programming header that includes many standard libraries

// The solve function encapsulates the logic for a single test case.
void solve() {
    int N; // Declare an integer variable N to store the number of dishes
    std::cin >> N; // Read the value of N from standard input

    // Initialize common_mask. This bitmask will keep track of ingredients
    // that are present in ALL dishes processed so far.
    // Initially, we assume all 26 lowercase English letters ('a' through 'z')
    // are potentially special ingredients.
    // (1 << 26) creates an integer with the 26th bit set (0-indexed, so bit 25 is 'z').
    // Subtracting 1 makes all bits from 0 to 25 set.
    // For example, if we only had 3 letters, (1 << 3) - 1 would be 7 (binary 111).
    int common_mask = (1 << 26) - 1; 

    // Loop N times, once for each dish
    for (int i = 0; i < N; ++i) {
        std::string S; // Declare a string variable S to store the current dish's ingredients
        std::cin >> S; // Read the dish string from standard input

        // current_dish_mask will store the unique ingredients present in the current dish S.
        // It's initialized to 0, meaning no ingredients are present yet.
        int current_dish_mask = 0;
        
        // Iterate through each character (ingredient) in the current dish string S
        for (char c : S) {
            // Set the bit corresponding to the character 'c'.
            // 'a' corresponds to bit 0, 'b' to bit 1, ..., 'z' to bit 25.
            // The bitwise OR operator (`|=`) ensures that if a character appears
            // multiple times in the string, its corresponding bit is set only once.
            current_dish_mask |= (1 << (c - 'a'));
        }

        // Update common_mask by performing a bitwise AND with current_dish_mask.
        // This operation finds the intersection of ingredients.
        // Only bits that are set in *both* common_mask (ingredients common to previous dishes)
        // AND current_dish_mask (ingredients in the current dish) will remain set.
        // If an ingredient was common to previous dishes but is NOT in the current dish,
        // its corresponding bit will be cleared in common_mask.
        common_mask &= current_dish_mask;
    }

    // After processing all N dishes, common_mask will contain bits set only for
    // ingredients that were present in ALL N dishes.
    // We need to count these set bits to find the number of special ingredients.
    // __builtin_popcount is a GCC extension that efficiently counts the number of set bits
    // (population count) in an integer.
    int special_ingredients_count = __builtin_popcount(common_mask);
    
    // Print the result for the current test case, followed by a newline character.
    std::cout << special_ingredients_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // std::cin.tie(NULL) prevents std::cout from flushing before each std::cin operation,
    // which can further speed up I/O in interactive problems or problems with mixed I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases
    std::cin >> T; // Read the number of test cases from standard input
    
    // Loop T times, calling the solve() function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```