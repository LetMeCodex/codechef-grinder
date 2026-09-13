# Sum it (SUMM)
- **Difficulty Rating**: 308
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if the sum of two given integers, $a$ and $b$, is equal to a third given integer, $c$. We need to process multiple test cases.

## Intuition & Mathematical Observation
The problem statement is very direct. We are given three integers, $a$, $b$, and $c$, and we need to check if the equation $a + b = c$ holds true. There are no complex mathematical concepts or tricks involved. The core of the problem is a simple arithmetic comparison.

The only potential pitfall could be the range of the input integers. If the sum $a+b$ could exceed the capacity of a standard integer type (like `int`), we would need to use a larger data type. The problem statement doesn't explicitly mention constraints, but it's good practice to consider this. In C++, `long long` is a suitable choice for handling potentially large sums.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
  For each test case, we perform a single addition and a single comparison. These operations take constant time. Since there are $t$ test cases, the total time complexity is $O(t)$. However, when analyzing the complexity *per test case*, it's $O(1)$.

- **Space Complexity**: $O(1)$.
  We only use a few variables to store the input integers ($a$, $b$, $c$) and the number of test cases ($t$). The memory usage does not grow with the input size, making it constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    // Disables synchronization with C's stdio and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        long long a, b, c; // Use long long to handle potentially large sums
        cin >> a >> b >> c; // Read the three integers for the current test case

        // Check if the sum of 'a' and 'b' is equal to 'c'
        if (a + b == c) {
            cout << "YES\n"; // If they are equal, print "YES" followed by a newline
        } else {
            cout << "NO\n";  // If they are not equal, print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful execution
}
```