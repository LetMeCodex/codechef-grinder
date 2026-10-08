# [Utkarsh and Placement tests (UTKPLC)](https://www.codechef.com/problems/UTKPLC)
- **Difficulty Rating**: 886
- **Solved in**: 1 attempt(s)

## Problem Summary

Utkarsh has a list of three preferred courses, given in decreasing order of preference (e.g., 'A', 'B', 'C' means 'A' is most preferred, 'B' is second, 'C' is third). He receives offers for two courses. He will choose the course that is highest on his preference list among the two courses he received offers for. We need to determine which course Utkarsh will choose.

**Input:**
- The first line contains `t`, the number of test cases.
- For each test case:
    - Three characters `first`, `second`, `third` representing his preferred courses in decreasing order.
    - Two characters `offer1`, `offer2` representing the courses he received offers for.

**Output:**
- For each test case, print the character representing the course Utkarsh chooses.

## Intuition & Mathematical Observation

The problem states that Utkarsh chooses the most preferred course among the ones he received offers for. This implies a simple greedy approach:

1.  **Check his top preference:** If his most preferred course (`first`) is among the two offers (`offer1` or `offer2`), he will definitely choose it. There's no need to check further, as it's his highest preference.
2.  **Check his second preference:** If his top preferred course (`first`) is *not* offered, then he moves to his second preferred course (`second`). If `second` is among the two offers, he will choose it. This is because `first` wasn't available, and `second` is now the highest preference available.
3.  **Default to his third preference:** If neither his top preferred course (`first`) nor his second preferred course (`second`) is offered, then by elimination, his third preferred course (`third`) must be the highest preferred course available among the offers. Therefore, he will choose `third`. The problem guarantees that a choice will be made, implying that one of his preferred courses will always be among the offers in a way that this logic holds.

This logic can be directly translated into a series of `if-else if-else` statements.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, we read a fixed number of characters (3 preferences, 2 offers) and perform a constant number of comparisons and an output operation. This takes constant time. If there are `t` test cases, the total time complexity is $O(t)$.

-   **Space Complexity**: $O(1)$.
    We only store a few character variables (`first`, `second`, `third`, `offer1`, `offer2`) for each test case. The amount of memory used does not grow with the input values (other than the number of test cases `t`).

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <string>   // Not strictly needed for this problem, but often useful
#include <vector>   // Not strictly needed for this problem
#include <algorithm> // Not strictly needed for this problem
#include <set>      // Not strictly needed for this problem

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        char first, second, third; // Variables to store the three preferred courses
        std::cin >> first >> second >> third; // Read the preferred courses

        char offer1, offer2; // Variables to store the two offered courses
        std::cin >> offer1 >> offer2; // Read the offered courses

        // Apply the preference logic:
        // 1. Check if the most preferred course (first) is offered.
        if (offer1 == first || offer2 == first) {
            std::cout << first << "\n"; // If yes, choose 'first'
        } 
        // 2. If 'first' is not offered, check if the second most preferred course (second) is offered.
        else if (offer1 == second || offer2 == second) {
            std::cout << second << "\n"; // If yes, choose 'second'
        } 
        // 3. If neither 'first' nor 'second' is offered, then 'third' must be the highest available preference.
        else {
            std::cout << third << "\n"; // Choose 'third'
        }
    }

    return 0; // Indicate successful execution
}

```