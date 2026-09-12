# [Bidding (AUCTION)](https://www.codechef.com/problems/AUCTION)
- **Difficulty Rating**: 330
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a simple auction scenario involving three participants: Alice, Bob, and Charlie. Each participant submits a bid, and it's guaranteed that all three bids are distinct. The task is to determine and output the name of the person who wins the auction. The winner is, by definition, the one who submits the highest bid.

## Intuition & Mathematical Observation

The core of this problem lies in identifying the maximum value among three distinct integers. Since the bids are guaranteed to be distinct, there will always be a unique highest bid.

Our intuition is straightforward:
1.  Read the three bids, let's say `A` for Alice, `B` for Bob, and `C` for Charlie.
2.  Compare these bids to find the largest one.
    *   If `A` is greater than both `B` and `C`, then Alice has the highest bid and wins.
    *   Else if `B` is greater than both `A` and `C`, then Bob has the highest bid and wins.
    *   Otherwise (if neither Alice nor Bob has the highest bid), it logically follows that Charlie must have the highest bid (since all bids are distinct and one must be the maximum).

This can be implemented using simple `if-else if-else` conditional statements. No complex algorithms or data structures are required for this basic comparison task.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading three integers, a few comparisons (at most 2-3), and printing one string. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `A`, `B`, `C`) to store the number of test cases and the bids for the current test case. The memory usage does not scale with the input values or the number of test cases (beyond the loop counter). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, C; // Declare integer variables for Alice's, Bob's, and Charlie's bids.
        cin >> A >> B >> C; // Read the three bids for the current test case.

        // Determine the winner based on the highest bid.
        // Since A, B, C are distinct, there will always be a unique highest bid.
        if (A > B && A > C) {
            // If Alice's bid is greater than both Bob's and Charlie's, Alice wins.
            cout << "Alice\n";
        } else if (B > A && B > C) {
            // Else if Bob's bid is greater than both Alice's and Charlie's, Bob wins.
            cout << "Bob\n";
        } else {
            // Otherwise (if neither Alice nor Bob has the highest bid), Charlie must have the highest bid.
            cout << "Charlie\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```