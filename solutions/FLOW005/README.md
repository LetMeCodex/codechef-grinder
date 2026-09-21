# [Smallest Numbers of Notes (FLOW005)](https://www.codechef.com/problems/FLOW005)
- **Difficulty Rating**: 839
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of currency notes required to make a given sum `N`. We are provided with a set of standard Indian currency denominations: Rs. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 50, and Rs. 100. We need to process `T` independent test cases, where for each test case, we read an integer `N` and output the smallest number of notes.

## Intuition & Mathematical Observation

This is a classic change-making problem. The goal is to minimize the total count of notes. For standard currency systems like the one provided (1, 2, 5, 10, 50, 100), a **greedy approach** works optimally.

The greedy strategy is as follows:
1.  Start with the largest available denomination (Rs. 100).
2.  Calculate how many notes of this denomination can be used without exceeding the current remaining sum `N`.
3.  Add this count to our total notes.
4.  Subtract the value of these notes from `N` to get the new remaining sum.
5.  Move to the next largest denomination (Rs. 50) and repeat the process.
6.  Continue this process for all denominations in decreasing order (100, 50, 10, 5, 2, 1) until the remaining sum `N` becomes zero.

**Why does the greedy approach work for these denominations?**
The greedy approach is optimal for a currency system if, for any amount `X`, taking the largest possible denomination `D` (such that `D <= X`) and then optimally solving for `X - D` always yields the overall optimal solution. This property holds for "canonical" coin systems. The given denominations (1, 2, 5, 10, 50, 100) form such a system.

For example, if we need to make Rs. 199:
*   We take one Rs. 100 note. Remaining sum: 99. Notes: 1.
*   We take one Rs. 50 note. Remaining sum: 49. Notes: 2.
*   We take four Rs. 10 notes. Remaining sum: 9. Notes: 6.
*   We take one Rs. 5 note. Remaining sum: 4. Notes: 7.
*   We take two Rs. 2 notes. Remaining sum: 0. Notes: 9.
*   Total notes: 9.

This strategy ensures that we use the largest possible value notes first, which inherently minimizes the total count of notes because larger notes cover more value with a single unit.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a fixed number of arithmetic operations (division and modulo) corresponding to the 6 distinct denominations. This is a constant number of operations per test case. If there are `T` test cases, the total time complexity will be $O(T \times \text{number of denominations})$. Since the number of denominations is a small constant (6), the time complexity simplifies to $O(T)$.

*   **Space Complexity**: The solution uses a few integer variables (`T`, `N`, `notes_count`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of `N` or the number of test cases `T` (beyond storing `T` itself). Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <bits/stdc++.h> 

// It's good practice to use specific headers if possible, but for competitive programming,
// <bits/stdc++.h> is commonly used as a convenience.
// For this problem, <iostream> would be sufficient.

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the total number of testcases.
    cin >> T; // Read the number of testcases.

    // Loop through each testcase.
    while (T--) {
        int N; // Variable to store the input sum N.
        cin >> N; // Read the sum N for the current testcase.

        int notes_count = 0; // Initialize a counter for the total number of notes.

        // The problem asks for the smallest number of notes.
        // For standard currency denominations (1, 2, 5, 10, 50, 100),
        // a greedy approach works optimally.
        // We start with the largest denomination and take as many as possible,
        // then move to the next largest, and so on.

        // Denomination: Rs. 100
        notes_count += N / 100; // Add the number of 100-rupee notes.
        N %= 100;               // Update N to the remaining amount after taking 100-rupee notes.

        // Denomination: Rs. 50
        notes_count += N / 50;  // Add the number of 50-rupee notes.
        N %= 50;                // Update N.

        // Denomination: Rs. 10
        notes_count += N / 10;  // Add the number of 10-rupee notes.
        N %= 10;                // Update N.

        // Denomination: Rs. 5
        notes_count += N / 5;   // Add the number of 5-rupee notes.
        N %= 5;                 // Update N.

        // Denomination: Rs. 2
        notes_count += N / 2;   // Add the number of 2-rupee notes.
        N %= 2;                 // Update N.

        // Denomination: Rs. 1
        // At this point, N will be either 0 or 1.
        notes_count += N / 1;   // Add the number of 1-rupee notes.
        // N %= 1; // This line is not strictly necessary as N will become 0,
                  // and no further calculations depend on N.

        // Display the smallest number of notes for the current testcase,
        // followed by a newline character.
        cout << notes_count << "\n";
    }

    return 0; // Indicate successful execution.
}
```