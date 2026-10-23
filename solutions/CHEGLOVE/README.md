# [Chef and Glove (CHEGLOVE)](https://www.codechef.com/problems/CHEGLOVE)
- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `N` fingers and `N` sheaths for a glove. The lengths of his fingers are given as an array `F`, and the lengths of the sheaths are given as an array `S`. A finger `F_i` can fit into a sheath `S_j` if and only if `F_i <= S_j`.

Chef can wear the glove in two ways:
1.  **Front**: Each finger `F_i` must fit into the corresponding sheath `S_i`. That is, `F_i <= S_i` for all `i` from `1` to `N`.
2.  **Back**: Each finger `F_i` must fit into the sheath `S_{N-i+1}`. That is, `F_1` fits into `S_N`, `F_2` into `S_{N-1}`, and so on, until `F_N` fits into `S_1`. This means `F_i <= S_{N-i+1}` for all `i` from `1` to `N`.

The task is to determine which ways Chef can wear the glove and print the result:
-   "both" if he can wear it both ways.
-   "front" if he can wear it only the front way.
-   "back" if he can wear it only the back way.
-   "none" if he cannot wear it either way.

## Intuition & Mathematical Observation

The problem asks us to check two independent conditions and then combine their results.

1.  **Checking for "front"**:
    We need to verify if `F_i <= S_i` for all `i` from `0` to `N-1` (using 0-based indexing for arrays). We can iterate through the finger lengths and sheath lengths simultaneously. If we find even one instance where `F_i > S_i`, then Chef cannot wear the glove the "front" way. If the loop completes without finding such an instance, then he can wear it the "front" way.

2.  **Checking for "back"**:
    We need to verify if `F_i <= S_{N-1-i}` for all `i` from `0` to `N-1`. This means `F_0` must fit into `S_{N-1}`, `F_1` into `S_{N-2}`, and so on, until `F_{N-1}` fits into `S_0`. We can iterate through the finger lengths `F_i` and compare them with the sheath lengths `S_j` where `j` is `N-1-i`. If we find even one instance where `F_i > S_{N-1-i}`, then Chef cannot wear the glove the "back" way. If the loop completes, he can wear it the "back" way.

After performing these two checks, we will have two boolean flags, say `can_wear_front` and `can_wear_back`. The final output is determined by the combination of these flags:
-   If `can_wear_front` is true AND `can_wear_back` is true: print "both".
-   Else if `can_wear_front` is true: print "front".
-   Else if `can_wear_back` is true: print "back".
-   Else (neither is true): print "none".

This approach is straightforward and directly translates the problem conditions into code.

## Complexity Analysis

-   **Time Complexity**:
    For each test case:
    -   Reading `N` finger lengths takes $O(N)$ time.
    -   Reading `N` sheath lengths takes $O(N)$ time.
    -   Checking `can_wear_front` involves a loop that runs `N` times, performing constant time operations (comparison, array access) in each iteration. This takes $O(N)$ time.
    -   Checking `can_wear_back` also involves a loop that runs `N` times, performing constant time operations. This takes $O(N)$ time.
    -   The final conditional checks and printing take $O(1)$ time.
    Therefore, for a single test case, the total time complexity is $O(N) + O(N) + O(N) + O(N) + O(1) = O(N)$.
    Given `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    For each test case:
    -   A `std::vector<long long> fingers` is used to store `N` finger lengths, requiring $O(N)$ space.
    -   A `std::vector<long long> sheaths` is used to store `N` sheath lengths, requiring $O(N)$ space.
    -   Other variables (`t`, `n`, loop counters, boolean flags) use $O(1)$ space.
    Therefore, the total space complexity for a single test case is $O(N) + O(N) = O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed for this solution, but good practice for competitive programming

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n;
        cin >> n; // Read the number of fingers/sheaths

        // Declare vectors to store finger and sheath lengths
        vector<long long> fingers(n);
        vector<long long> sheaths(n);

        // Read finger lengths
        for (int i = 0; i < n; ++i) {
            cin >> fingers[i];
        }

        // Read sheath lengths
        for (int i = 0; i < n; ++i) {
            cin >> sheaths[i];
        }

        // --- Check if Chef can wear the glove the "front" way ---
        bool can_wear_front = true;
        for (int i = 0; i < n; ++i) {
            // If any finger is longer than its corresponding sheath,
            // then it's not possible to wear it the front way.
            if (fingers[i] > sheaths[i]) {
                can_wear_front = false;
                break; // No need to check further
            }
        }

        // --- Check if Chef can wear the glove the "back" way ---
        bool can_wear_back = true;
        for (int i = 0; i < n; ++i) {
            // If any finger is longer than its corresponding reversed sheath,
            // then it's not possible to wear it the back way.
            // sheaths[n - 1 - i] gives the sheath at the reversed position.
            // E.g., for i=0, it's sheaths[n-1]; for i=1, it's sheaths[n-2], etc.
            if (fingers[i] > sheaths[n - 1 - i]) {
                can_wear_back = false;
                break; // No need to check further
            }
        }

        // --- Determine and print the result based on the checks ---
        if (can_wear_front && can_wear_back) {
            cout << "both\n";
        } else if (can_wear_front) {
            cout << "front\n";
        } else if (can_wear_back) {
            cout << "back\n";
        } else {
            cout << "none\n";
        }
    }
    return 0; // Indicate successful execution
}
```