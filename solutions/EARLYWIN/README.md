# [Early Certificates (EARLYWIN)](https://www.codechef.com/problems/EARLYWIN)
- **Difficulty Rating**: 595
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the **Longest Common Prefix (LCP)** of two given strings, `A` and `B`. We are provided with the lengths of the strings, `N` and `M`, respectively, followed by the strings themselves. The task is to output the longest string `S` such that `S` is a prefix of both `A` and `B`.

## Intuition & Mathematical Observation

The concept of a "common prefix" implies that the characters must match from the very beginning of both strings, character by character, in the same order. The "longest" common prefix means we continue this comparison for as long as possible.

Our intuition should be to:
1.  Start comparing the first character of string `A` with the first character of string `B`.
2.  If they match, this character is part of the common prefix. Move to the next character in both strings.
3.  If they do not match, or if we reach the end of either string (meaning one string is shorter than the other and we've exhausted its characters), then the common prefix ends at the character *before* the mismatch or end of string.
4.  The longest possible common prefix cannot be longer than the shorter of the two input strings. For example, if `A` has length 5 and `B` has length 3, the LCP can be at most 3 characters long.

There are no complex mathematical observations required; it's a direct application of the definition of a common prefix. We simply iterate and collect matching characters until a mismatch or an end of string is encountered.

## Complexity Analysis

*   **Time Complexity**: $O(N+M)$ per test case.
    *   Reading the lengths `N`, `M` and the strings `A`, `B` takes $O(N+M)$ time.
    *   The `for` loop iterates at most `min(N, M)` times. In each iteration, we perform a constant number of operations (character comparison `A[i] == B[i]` and string concatenation `result += A[i]`).
    *   String concatenation `result += A[i]` for `std::string` in C++ is amortized $O(1)$. Over the entire loop, if the LCP has length `L`, the total cost of building `result` is $O(L)$. Since $L \le \min(N, M)$, this is $O(\min(N, M))$.
    *   Printing the `result` string takes $O(\min(N, M))$ time.
    *   Combining these, the dominant factor is reading the input strings and iterating through them, which is $O(N+M)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot (N+M))$.

*   **Space Complexity**: $O(N+M)$ per test case.
    *   Storing the input strings `A` and `B` requires $O(N)$ and $O(M)$ space, respectively, totaling $O(N+M)$.
    *   The `result` string stores the longest common prefix. In the worst case (e.g., `A = "abc"`, `B = "abcd"`), `result` can be as long as `min(N, M)`. Thus, it requires $O(\min(N, M))$ space.
    *   Overall, the space complexity is dominated by storing the input strings, resulting in $O(N+M)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, algorithm

// Use the standard namespace for convenience as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, M;
    cin >> N >> M; // Read the lengths of the two strings
    string A, B;
    cin >> A >> B; // Read the two strings

    string result = ""; // Initialize an empty string to store the longest common prefix
    
    // The longest possible common prefix cannot be longer than the shorter of the two strings.
    // We iterate up to this limit.
    int limit = min(N, M); 

    // Loop through characters from the beginning of both strings
    for (int i = 0; i < limit; ++i) {
        // Compare characters at the current index 'i'
        if (A[i] == B[i]) {
            // If characters match, append this character to our result string
            result += A[i];
        } else {
            // If characters do not match, the common prefix ends here.
            // We break out of the loop as no further characters will be common.
            break;
        }
    }
    
    // Output the determined longest common prefix, followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard I/O.
    // `cin.tie(NULL)` prevents `cout` from being flushed before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop 'T' times, once for each test case
        solve(); // Call the solve function to process the current test case
    }

    return 0; // Indicate successful program execution
}
```