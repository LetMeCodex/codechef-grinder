# [Perfect Trio (PERFECTTRIO)](https://www.codechef.com/problems/PERFECTTRIO)
- **Difficulty Rating**: 455
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given group of three people forms a "perfect trio". We are provided with three integers, $A, B, C$, representing the ages of the three people. A group is defined as a perfect trio if the age of one person is equal to the sum of the ages of the other two people. We need to output "YES" if it's a perfect trio, and "NO" otherwise. This check needs to be performed for $T$ independent test cases.

## Intuition & Mathematical Observation

The problem statement provides a very direct definition for a "perfect trio". It states that "the age of one person is equal to the sum of the ages of the other two people."

Given three ages $A, B, C$, this definition can be translated into three possible conditions:
1. The age of the first person ($A$) is equal to the sum of the ages of the second and third persons ($B + C$). Mathematically: $A = B + C$.
2. The age of the second person ($B$) is equal to the sum of the ages of the first and third persons ($A + C$). Mathematically: $B = A + C$.
3. The age of the third person ($C$) is equal to the sum of the ages of the first and second persons ($A + B$). Mathematically: $C = A + B$.

If any one of these three conditions is true, then the group forms a perfect trio. If none of these conditions are met, then it is not a perfect trio.

Our approach will be to read the three ages, check these three conditions using logical OR (`||`), and print "YES" if the combined condition is true, otherwise print "NO".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: three integer reads, two additions, three comparisons, and one print operation. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1) = O(T)$. Given typical constraints for $T$ (e.g., up to $10^5$ or $10^6$), this is highly efficient.

-   **Space Complexity**: $O(1)$
    For each test case, we only need to store three integer variables ($A, B, C$). This amount of memory is constant and does not depend on the input values or the number of test cases $T$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per competitive programming common practice

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three ages for the current test case
    cin >> A >> B >> C;

    // Check if any of the three conditions for a perfect group are met:
    // 1. Age of A is the sum of B and C (A = B + C)
    // 2. Age of B is the sum of A and C (B = A + C)
    // 3. Age of C is the sum of A and B (C = A + B)
    if (A == B + C || B == A + C || C == A + B) {
        // If any condition is true, the group is perfect
        cout << "YES\n";
    } else {
        // Otherwise, the group is not perfect
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```