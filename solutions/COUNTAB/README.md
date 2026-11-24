# [Counting Characters (COUNTAB)](https://www.codechef.com/problems/COUNTAB)
- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process a given string `S` of length `N`. This string `S` is guaranteed to consist only of the characters 'a' and 'b'. Our task is to count the total occurrences of 'a' and 'b' in the string and then print these two counts, separated by a space. This operation needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The problem is a straightforward counting task. Since the string `S` contains only 'a' and 'b', we can iterate through the string character by character. For each character encountered:
1. If the character is 'a', we increment a counter specifically for 'a'.
2. If the character is 'b' (which is the only other possibility), we increment a counter specifically for 'b'.

After iterating through all characters in the string, the final values of these two counters will represent the total occurrences of 'a' and 'b' respectively. There are no complex mathematical observations or tricky edge cases beyond simply iterating and counting.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading the integer `N` takes $O(1)$ time.
    *   Reading the string `S` of length `N` takes $O(N)$ time.
    *   The `for` loop iterates `N` times, once for each character in the string `S`. Inside the loop, checking `c == 'a'` and incrementing a counter are $O(1)$ operations. Thus, the loop contributes $O(N)$ to the time complexity.
    *   Printing the two counts takes $O(1)$ time.
    *   Combining these, the total time complexity for a single test case is $O(1) + O(N) + O(N) + O(1) = O(N)$.
    *   Since there are `T` test cases, the overall time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of the string across all test cases.

*   **Space Complexity**: $O(N)$
    *   Storing the integer `N` and the two counters (`count_a`, `count_b`) requires $O(1)$ space.
    *   Storing the input string `S` of length `N` requires $O(N)$ space.
    *   Therefore, the dominant factor for space complexity is storing the input string, making the total space complexity $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string S

    int count_a = 0; // Initialize count for 'a'
    int count_b = 0; // Initialize count for 'b'

    // Iterate through each character in the string S
    for (char c : S) {
        if (c == 'a') {
            count_a++; // Increment count_a if the character is 'a'
        } else {
            // Since the problem states S consists only of 'a' and 'b',
            // if it's not 'a', it must be 'b'.
            count_b++; // Increment count_b if the character is 'b'
        }
    }

    // Print the counts of 'a' and 'b' separated by a space, followed by a newline
    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```