# [Mathison and pangrams (MATPAN)](https://www.codechef.com/problems/MATPAN)
- **Difficulty Rating**: 1127
- **Solved in**: 1 attempt(s)

## Problem Summary

Mathison wants to create a pangram, which is a sentence containing every letter of the English alphabet ('a' through 'z') at least once. He already has an initial text. He knows the cost of buying each individual letter. His goal is to determine the minimum total cost to acquire all the letters he needs to complete his pangram. This means he only needs to buy the letters that are *not* already present in his initial text.

## Intuition & Mathematical Observation

The core idea behind solving this problem is to efficiently identify which letters are missing from Mathison's initial text. Once we know which letters are missing, we simply sum their respective costs to find the minimum total expenditure.

Here's the step-by-step intuition:

1.  **Track Presence**: We need a way to keep track of which letters ('a' through 'z') are present in the given initial text. A boolean array of size 26 is perfect for this. `isPresent[0]` can represent 'a', `isPresent[1]` for 'b', and so on, up to `isPresent[25]` for 'z'. Initialize all entries to `false`.

2.  **Process Initial Text**: Iterate through each character in Mathison's initial text. For each character `c`, mark its corresponding entry in our `isPresent` array as `true`. For example, if `c` is 'a', set `isPresent[0] = true`; if `c` is 'b', set `isPresent[1] = true`, and so forth. This can be done by using `c - 'a'` to get the 0-indexed position.

3.  **Calculate Total Cost**: After processing the entire initial text, iterate through our `isPresent` array from index 0 to 25. For each index `i`:
    *   If `isPresent[i]` is `false` (meaning the letter corresponding to this index is *not* in the initial text), then Mathison needs to buy this letter. Add its price (which is given in a separate array, also indexed 0-25) to a running total cost.

4.  **Summation**: The problem boils down to a simple summation of costs for the missing letters. There are no complex mathematical observations or algorithms required beyond basic array manipulation and conditional summation.

## Complexity Analysis

Let $N$ be the length of Mathison's initial text string.

-   **Time Complexity**:
    *   Reading the 26 prices: $O(26)$, which simplifies to $O(1)$.
    *   Reading the input string: $O(N)$.
    *   Iterating through the input string to mark present letters: We iterate through each of the $N$ characters. For each character, we perform a constant time operation (array access). So, this step takes $O(N)$.
    *   Iterating through the 26 possible letters to sum costs: We iterate 26 times. For each iteration, we perform a constant time operation (array access and addition). So, this step takes $O(26)$, which simplifies to $O(1)$.
    *   Total time complexity per test case: $O(1) + O(N) + O(N) + O(1) = O(N)$.
    *   If there are $T$ test cases, the total time complexity would be $O(T \cdot N)$. Given $N \le 10^5$ and $T \le 10$, this is efficient enough ($10 \cdot 10^5 = 10^6$ operations).

-   **Space Complexity**:
    *   `prices` vector: Stores 26 integers. $O(26)$, which simplifies to $O(1)$.
    *   `s` string: Stores the input text of length $N$. $O(N)$.
    *   `isPresent` boolean vector: Stores 26 booleans. $O(26)$, which simplifies to $O(1)$.
    *   Total space complexity per test case: $O(N)$.
    *   Given $N \le 10^5$, this is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions.
using namespace std; // As per problem instructions.

// Function to solve a single test case
void solve() {
    // Declare a vector to store the prices of the 26 letters ('a' through 'z').
    // prices[0] will store the price of 'a', prices[1] for 'b', and so on.
    vector<int> prices(26);
    for (int i = 0; i < 26; ++i) {
        cin >> prices[i]; // Read each price
    }

    // Declare a string to store Mathison's initial text.
    string s;
    cin >> s; // Read the text

    // Declare a boolean vector to keep track of which letters are already present in the text.
    // isPresent[0] will be true if 'a' is in the text, false otherwise.
    // Similarly for other letters up to 'z'.
    vector<bool> isPresent(26, false); // Initialize all to false (no letters present yet)

    // Iterate through each character in the input string 's'.
    for (char c : s) {
        // For each character 'c', calculate its corresponding index (0 for 'a', 1 for 'b', etc.).
        // Mark that letter as present.
        isPresent[c - 'a'] = true;
    }

    // Initialize total cost to 0.
    // Use long long to prevent potential integer overflow.
    // Max cost: 26 letters * 1,000,000 (max price) = 26,000,000.
    // This fits in a 32-bit signed int, but long long is safer and good practice.
    long long totalCost = 0;

    // Iterate through all 26 possible letters (from 'a' to 'z').
    for (int i = 0; i < 26; ++i) {
        // If the letter corresponding to index 'i' is NOT present in the initial text,
        // then Mathison needs to buy it. Add its price to the total cost.
        if (!isPresent[i]) {
            totalCost += prices[i];
        }
    }

    // Print the calculated total cost for the current test case, followed by a newline.
    cout << totalCost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams.
    cin.tie(NULL); // Untie cin from cout.

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) { // Loop 't' times, solving each test case.
        solve();
    }

    return 0; // Indicate successful execution.
}
```