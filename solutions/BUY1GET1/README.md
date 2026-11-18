# [Buy1-Get1 (BUY1GET1)](https://www.codechef.com/problems/BUY1GET1)
- **Difficulty Rating**: 1191
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum cost to buy a collection of jewels. We are given a string `S` where each character represents a jewel of a specific type. The buying rule is "Buy 1 Get 1 Free" for jewels of the *same type*. This means if you buy one jewel of type 'A', you get another jewel of type 'A' for free. If you need an odd number of jewels of a certain type, the last one must be bought individually. We need to find the total minimum cost to acquire all jewels listed in the string `S`.

## Intuition & Mathematical Observation

The core of the problem lies in the "same type" constraint for the "Buy 1 Get 1 Free" offer. This immediately tells us that the cost for jewels of one type is completely independent of the cost for jewels of another type. Therefore, we can process each distinct jewel type separately and sum up their individual minimum costs.

Let's consider a single type of jewel, say 'A', and suppose we need `N` jewels of type 'A'.
1.  **Count Frequencies**: The first step is to count how many jewels of each type are present in the input string `S`.
2.  **Calculate Cost per Type**: For each jewel type with a count `N`:
    *   **If `N` is even**: Say `N = 2k`. We can form `k` pairs of jewels. For each pair, we buy one and get one free. So, we pay for `k` jewels. The cost is `k = N / 2`.
    *   **If `N` is odd**: Say `N = 2k + 1`. We can form `k` pairs of jewels (costing `k`). One jewel will be left over. This single jewel must be bought individually, costing 1. So, the total cost for this type is `k + 1`. Using integer division, this can be expressed as `(N / 2) + 1`.

    Combining both cases, the cost for `N` jewels of a single type can be elegantly expressed as `(N / 2) + (N % 2)`.
    *   If `N` is even, `N % 2` is 0, so cost is `N / 2`.
    *   If `N` is odd, `N % 2` is 1, so cost is `N / 2 + 1`.

The overall algorithm will be:
1.  Initialize a frequency map (or array) to store counts for each character.
2.  Iterate through the input string `S`, incrementing the count for each character encountered in the frequency map.
3.  Initialize `total_cost = 0`.
4.  Iterate through the frequency map. For each jewel type with a count `N > 0`:
    *   Add `(N / 2) + (N % 2)` to `total_cost`.
5.  Print `total_cost`.

## Complexity Analysis

*   **Time Complexity**: $O(|S|)$
    *   Reading the input string `S` takes $O(|S|)$ time.
    *   Populating the frequency map involves iterating through the string `S` once. For each character, updating its count in the frequency map is an $O(1)$ operation. Thus, this step takes $O(|S|)$ time.
    *   Iterating through the frequency map (which has a fixed size of 256 for ASCII characters) to calculate the total cost takes $O(1)$ time (specifically, $O(256)$).
    *   Therefore, the dominant factor is iterating through the input string, making the total time complexity $O(|S|)$.

*   **Space Complexity**: $O(|S|)$
    *   Storing the input string `S` requires $O(|S|)$ space.
    *   The frequency map (`std::vector<int> freq(256)`) uses a fixed amount of memory (256 integers), which is constant and does not depend on the length of the input string. This is considered $O(1)$ additional space.
    *   Thus, the total space complexity is dominated by the input string storage, resulting in $O(|S|)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    std::string s;
    std::cin >> s; // Read the jewel string

    // Use a vector as a frequency map for ASCII characters.
    // Size 256 covers all possible char values (0-255).
    // Initialize all counts to 0.
    std::vector<int> freq(256, 0); 
    
    // Populate the frequency map by iterating through the input string
    for (char c : s) {
        // Cast char to unsigned char to safely use it as an index.
        // This prevents issues if 'char' is signed and holds a negative value,
        // which would lead to out-of-bounds access for the 'freq' array.
        freq[static_cast<unsigned char>(c)]++;
    }

    int total_cost = 0;
    // Iterate through the frequency counts.
    // We only care about characters that actually appeared in the string (count > 0).
    // Iterating through all 256 possible counts is efficient enough given the small constant size.
    for (int count : freq) {
        if (count > 0) {
            // Calculate cost for this color:
            // For N jewels of a specific color:
            // N/2 pairs can be acquired using the Buy1-Get1 offer, costing N/2.
            // If N is odd, there will be one jewel left over, which must be bought individually, costing 1.
            // So, the cost for 'count' jewels of a single color is (count / 2) + (count % 2).
            total_cost += (count / 2) + (count % 2);
        }
    }
    std::cout << total_cost << "\n"; // Output the minimum total cost for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // which can speed up interactive programs or programs with mixed I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful program execution
}
```