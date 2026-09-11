# [Credit score (CREDSCORE)](https://www.codechef.com/problems/CREDSCORE)
- **Difficulty Rating**: 459
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given credit score `X` is sufficient to access CRED programs. The condition for accessing these programs is that the credit score must be 750 or greater. We need to read an integer `X` from the input and print "YES" if `X >= 750`, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given a single input, the credit score `X`. The requirement for accessing CRED programs is clearly stated: the score must be at least 750. This translates directly into a mathematical inequality: `X >= 750`.

Therefore, the core logic of the solution is to evaluate this inequality. If it holds true, the output should be "YES". If it does not hold true (meaning `X < 750`), the output should be "NO". There are no complex mathematical transformations or observations needed; it's a direct application of a comparison operator.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading a single integer and performing a single comparison. These operations take constant time, regardless of the magnitude of the input integer `X`.

- **Space Complexity**: $O(1)$
The solution uses a single integer variable `X` to store the input. The memory required for this variable is constant and does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the credit score.
    
    // Read the credit score X from standard input.
    cin >> X;

    // Check if the credit score X is 750 or more.
    // According to the problem statement, a score of 750 or more is required
    // to access CRED programs.
    if (X >= 750) {
        // If the condition is met, print "YES" followed by a newline.
        cout << "YES\n";
    } else {
        // Otherwise (if X is less than 750), print "NO" followed by a newline.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}
```