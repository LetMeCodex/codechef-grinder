# Finding Square Roots (FSQRT)

- **Difficulty Rating**: 668
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the integer part of the square root of a given non-negative integer $N$. We are given $T$ test cases, and for each test case, we need to read an integer $N$ and output its integer square root.

## Intuition & Mathematical Observation

The core of this problem is to compute the square root of a number and then extract its integer part. Mathematically, for a given non-negative number $N$, we are looking for the largest integer $x$ such that $x^2 \le N$. This is precisely the definition of the floor of the square root of $N$, i.e., $\lfloor \sqrt{N} \rfloor$.

Most programming languages provide a built-in function to compute the square root of a number. In C++, the `sqrt()` function from the `<cmath>` (or `<bits/stdc++.h>`) library computes the square root and returns it as a floating-point type (usually `double`).

Since we need the *integer* part of the square root, we can leverage the fact that casting a floating-point number to an integer type (like `long long` in C++) truncates the decimal part. For non-negative numbers, truncation is equivalent to taking the floor. For example, `(long long)3.9` becomes `3`, and `(long long)3.0` becomes `3`. This directly gives us the desired integer part of the square root.

The problem statement guarantees that $N \ge 1$, so we don't need to worry about negative inputs or the square root of zero specifically (though the approach would still work for $N=0$).

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case.
    The `sqrt()` function typically has a time complexity that is considered constant for practical purposes, as it's implemented using highly optimized hardware instructions or algorithms that don't scale with the magnitude of the input number in a significant way for typical integer ranges. Since we perform this operation once per test case, the time complexity per test case is $O(1)$. For $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$ per test case.
    The solution uses a few variables to store the input number, the result, and the loop counter. The amount of memory used does not depend on the size of the input number $N$. Therefore, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        long long n; // Variable to store the input number.
        cin >> n; // Read the input number N.

        // The problem statement guarantees N >= 1.
        // We need to find the integer part of the square root.
        // The sqrt function from cmath (included via bits/stdc++.h)
        // returns a double representing the square root of n.
        // Casting this double to a long long will truncate the decimal part.
        // For non-negative numbers, truncation is equivalent to taking the floor,
        // which gives us the largest integer whose square is less than or equal to n.
        long long result = sqrt(n);

        // Output the calculated integer square root followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution.
}
```