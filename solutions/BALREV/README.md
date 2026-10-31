# [Balanced Reversals (BALREV)](https://www.codechef.com/problems/BALREV)
- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the lexicographically smallest binary string that can be obtained from a given binary string `S` of length `N`. The allowed operation is to choose any two adjacent characters `S[i]` and `S[i+1]` and reverse the substring `S[i...i+1]`. This operation can be performed any number of times.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the effect of the allowed operation. Reversing an adjacent pair `S[i]` and `S[i+1]` is equivalent to swapping `S[i]` and `S[i+1]`. For example, if `S = "010"`, choosing `i=0` and reversing `S[0...1]` (which is "01") results in "100". This is the same as swapping `S[0]` and `S[1]`.

A fundamental property in computer science is that if you can swap any two adjacent elements in a sequence, you can effectively move any element to any position. This is the principle behind algorithms like Bubble Sort. Since we can perform this operation any number of times, it means we can arrange the characters of the string `S` in any arbitrary order we desire. In other words, we can sort the characters of the string.

To obtain the lexicographically smallest string from a collection of characters, we should arrange them in non-decreasing order. For a binary string containing only '0's and '1's:
1.  '0' is lexicographically smaller than '1'.
2.  Therefore, to make the string as small as possible, all '0's must come before all '1's.

The number of '0's and '1's in the string remains constant throughout the operations, as we are only rearranging them, not changing their values or counts.

So, the strategy is:
1.  Count the total number of '0's in the input string. Let this be `count0`.
2.  The total number of '1's will then be `N - count0`.
3.  The lexicographically smallest string will consist of `count0` zeros followed by `count1` ones.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and the string `a`: $O(N)$
    *   Counting `count0`: The loop iterates through the string once, which takes $O(N)$ time.
    *   Calculating `count1`: $O(1)$
    *   Printing `count0` zeros and `count1` ones: This involves printing `N` characters in total, taking $O(N)$ time.
    *   Overall for one test case: $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing `N`, `count0`, `count1`: $O(1)$
    *   Storing the input string `a`: $O(N)$
    *   The output string is constructed and printed directly without being stored in a separate data structure.
    *   Overall: $O(N)$ due to storing the input string.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Use the standard namespace to avoid prefixing std:: to every standard library component.
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the length of the string
    string a;
    cin >> a; // Read the binary string

    int count0 = 0;
    // Iterate through the string to count the number of '0's
    for (char c : a) {
        if (c == '0') {
            count0++;
        }
    }

    // The number of '1's is simply the total length N minus the count of '0's
    int count1 = n - count0;

    // To achieve the lexicographically smallest string, all '0's must come first,
    // followed by all '1's.
    // Print '0' count0 times
    for (int i = 0; i < count0; ++i) {
        cout << '0';
    }

    // Print '1' count1 times
    for (int i = 0; i < count1; ++i) {
        cout << '1';
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```