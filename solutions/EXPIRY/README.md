# [Expiring Bread (EXPIRY)](https://www.codechef.com/problems/EXPIRY)
- **Difficulty Rating**: 440
- **Solved in**: 1 attempt(s)

## Problem Summary
Eikooc has $N$ loaves of bread. Each loaf of bread expires after $M$ days. Eikooc can eat at most $K$ loaves of bread per day. We need to determine if Eikooc can eat all $N$ loaves of bread before they expire.

## Intuition & Mathematical Observation
The core of the problem lies in comparing the total amount of bread Eikooc has with the total amount she can consume within the expiry period.

Each loaf of bread expires after $M$ days. This means Eikooc has a window of $M$ days to eat any given loaf.
Eikooc can eat at most $K$ loaves per day.

Therefore, over the course of $M$ days, the maximum number of loaves Eikooc can eat is the product of the number of days and the maximum loaves she can eat per day.
Maximum loaves Eikooc can eat in $M$ days = $M \times K$.

If the total number of loaves Eikooc has ($N$) is less than or equal to the maximum number of loaves she can eat within the expiry period ($M \times K$), then she can eat all the bread. Otherwise, she cannot.

So, the condition to check is: $N \le M \times K$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations and a comparison. These operations take constant time, regardless of the input values of $N$, $M$, and $K$. The number of test cases $T$ also doesn't affect the complexity per test case, as each test case is solved in constant time.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like $N$, $M$, $K$, $T$, and the result. This memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

using namespace std; // Allows using standard library elements like cin, cout without the std:: prefix

// Function to solve a single test case
void solve() {
    int N, M, K;
    // Read the number of loaves (N), days to expiry (M), and loaves per day (K)
    cin >> N >> M >> K;

    // Calculate the maximum total loaves Eikooc can eat within M days.
    // She eats up to K loaves per day for M days.
    int max_eatable_loaves = M * K;

    // Compare the total loaves Eikooc has (N) with the maximum she can eat.
    // If N is less than or equal to max_eatable_loaves, she can eat all bread.
    if (N <= max_eatable_loaves) {
        cout << "Yes\n"; // Output "Yes" followed by a newline
    } else {
        // Otherwise, she cannot eat all bread before it expires.
        cout << "No\n"; // Output "No" followed by a newline
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```