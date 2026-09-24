# [Candies (CNDY)](https://www.codechef.com/problems/CNDY)
- **Difficulty Rating**: 1018
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given set of `2N` candy prices can be split into two arrays, each of size `N`, such that all candy prices within *each* of these two arrays are distinct.

For example, if `N=2`, we have `2N=4` candies. We need to split them into two arrays, `Array A` (size 2) and `Array B` (size 2). If the candies are `[1, 2, 1, 3]`, a valid split would be `Array A = [1, 2]` and `Array B = [1, 3]`. Both arrays have distinct elements. If the candies were `[1, 1, 1, 2]`, it would be impossible because the price `1` appears three times.

## Intuition & Mathematical Observation

Let's analyze the condition: "all candies within *each* of these two arrays have distinct prices."

Consider any specific candy price, say `X`.
*   If we put `X` into `Array A`, we cannot put another `X` into `Array A`.
*   Similarly, if we put `X` into `Array B`, we cannot put another `X` into `Array B`.

This implies that for any given price `X`, it can appear at most once in `Array A` AND at most once in `Array B`.
Therefore, across both arrays combined (which represents our original `2N` candies), any specific candy price `X` can appear a maximum of `1 (for Array A) + 1 (for Array B) = 2` times.

If any candy price `X` appears **more than twice** among the initial `2N` candies, it is impossible to satisfy the condition.
*   For instance, if `X` appears 3 times: We can place one `X` in `Array A` and one `X` in `Array B`. The third `X` has nowhere to go without violating the distinctness rule in either `Array A` or `Array B`.
*   If `X` appears 4 or more times, the situation is even worse.

Conversely, if every candy price appears at most twice among the `2N` candies, is it always possible to make such a split? Yes.
*   If a price `P` appears once: We can assign it to either `Array A` or `Array B`.
*   If a price `P` appears twice: We must assign one `P` to `Array A` and the other `P` to `Array B`. This is perfectly fine, as `Array A` will have one `P` and `Array B` will have one `P`, satisfying the distinctness rule for both.

Since we have `2N` candies in total, and each set needs `N` candies, and each unique candy price contributes at most 2 to the total count, we can always distribute them to form two arrays of size `N` with distinct elements. The problem only asks if it's *possible*, not to construct the arrays.

Thus, the problem simplifies to a frequency counting task:
1.  Count the occurrences of each candy price among the `2N` given candies.
2.  If any candy price has a frequency greater than 2, then it's impossible to make the split, and the answer is "No".
3.  Otherwise (if all candy prices appear 0, 1, or 2 times), it is possible, and the answer is "Yes".

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `T` (number of test cases) takes $O(1)$ time.
    *   The main loop iterates `2N` times to read all candy prices. Inside the loop, `counts[price]++` is performed. For `std::map`, insertion or access and update operations take $O(\log K)$ time, where `K` is the number of unique elements currently in the map. In the worst case, all `2N` prices are unique, so `K` can be up to `2N`. Thus, this part takes $O(2N \log (2N))$ time.
    *   After populating the map, we iterate through its elements. In the worst case, there are `2N` unique prices. Iterating through `K` elements of a map takes $O(K)$ time. So, this part takes $O(2N)$ time.
    *   Combining these, the total time complexity for a single test case is $O(2N \log (2N) + 2N) = O(N \log N)$.
    *   Given `N <= 100`, `N log N` is very small (e.g., `100 * log2(100) approx 100 * 6.64 = 664`), making this solution highly efficient.

*   **Space Complexity**:
    *   The `std::map<int, int> counts` stores the frequency of each unique candy price. In the worst case, all `2N` candy prices are distinct, meaning the map will store `2N` key-value pairs.
    *   Therefore, the space complexity is $O(K)$, where `K` is the number of unique candy prices. In the worst case, $K = 2N$. So, $O(N)$.
    *   Given `N <= 100`, `2N` is at most `200`. Storing 200 integer pairs is a negligible amount of memory.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Not strictly needed for this solution, but often useful
#include <map>      // Used for frequency counting (std::map)

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of cities

    // Use a map to store the frequency of each candy price
    // Key: candy price (int), Value: count of occurrences (int)
    std::map<int, int> counts; 

    // Read 2N candy prices and update their frequencies
    for (int i = 0; i < 2 * n; ++i) {
        int price;
        std::cin >> price;
        counts[price]++; // Increment the count for the current price
    }

    // Flag to track if a valid split is possible
    bool possible = true;

    // Iterate through the frequency map
    // For each unique price and its count:
    for (auto const& pair : counts) { // C++11 range-based for loop (C++17 structured binding could be used for clarity)
        int count = pair.second; // Get the count of the current price
        
        // If any price appears more than twice, it's impossible to split
        // into two arrays where each has distinct elements.
        if (count > 2) {
            possible = false; // Set flag to false
            break;            // No need to check further, we found a violation
        }
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```