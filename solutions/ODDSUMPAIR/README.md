# [Odd Sum Pair (ODDSUMPAIR)](https://www.codechef.com/problems/ODDSUMPAIR)
- **Difficulty Rating**: 506
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to select two distinct numbers from a given set of three integers, `A`, `B`, and `C`, such that their sum is an odd number. We need to output "YES" if such a pair exists, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of odd and even numbers under addition:
1.  **Even + Even = Even**
2.  **Odd + Odd = Even**
3.  **Odd + Even = Odd**

We are given three numbers `A`, `B`, and `C`. We need to check if any of the pairs `(A, B)`, `(A, C)`, or `(B, C)` sum to an odd number. Let's analyze the possible parities of the three numbers:

*   **Case 1: All three numbers are Even (E, E, E)**
    *   `A + B = E + E = E`
    *   `A + C = E + E = E`
    *   `B + C = E + E = E`
    In this case, no pair will sum to an odd number.

*   **Case 2: One number is Odd, two are Even (O, E, E)**
    *   Let `A` be Odd, and `B`, `C` be Even.
    *   `A + B = O + E = O` (An odd sum pair exists!)
    *   `A + C = O + E = O` (An odd sum pair exists!)
    *   `B + C = E + E = E`
    In this case, at least one odd sum pair exists.

*   **Case 3: Two numbers are Odd, one is Even (O, O, E)**
    *   Let `A`, `B` be Odd, and `C` be Even.
    *   `A + B = O + O = E`
    *   `A + C = O + E = O` (An odd sum pair exists!)
    *   `B + C = O + E = O` (An odd sum pair exists!)
    In this case, at least one odd sum pair exists.

*   **Case 4: All three numbers are Odd (O, O, O)**
    *   `A + B = O + O = E`
    *   `A + C = O + O = E`
    *   `B + C = O + O = E`
    In this case, no pair will sum to an odd number.

From these observations, we can conclude that an odd sum pair exists if and only if the count of odd numbers among `A`, `B`, and `C` is either **1** (Case 2) or **2** (Case 3). If the count of odd numbers is **0** (Case 1) or **3** (Case 4), no odd sum pair can be formed.

The solution strategy is thus to count how many of the three input numbers are odd. If this count is 1 or 2, we output "YES"; otherwise, we output "NO".

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (three modulo operations, two additions, and one comparison). These operations take constant time, regardless of the magnitude of the input integers.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store a few integer variables (`A`, `B`, `C`, `odd_count`). This space requirement does not grow with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc., as per problem instructions

// Use the standard namespace as requested
using namespace std;

// The compile error indicates that the testing environment expects the function
// to be a method of a class named 'Solution'.
// We need to wrap the function in a class.
class Solution {
public:
    // Function Declaration
    // Function Name: checkOddPairs
    // Parameters: A, B, C (integers)
    // Return Value: "YES" or "NO" (string)
    string checkOddPairs(int A, int B, int C) {
        // Count the number of odd integers among A, B, and C.
        // For positive integers, X % 2 is 1 if X is odd, and 0 if X is even.
        int odd_count = (A % 2) + (B % 2) + (C % 2);

        // An odd sum pair exists if and only if the number of odd integers
        // among A, B, and C is either 1 or 2.
        // - If odd_count is 0 (all even) or 3 (all odd), no odd sum pair can be formed.
        //   (Even + Even = Even; Odd + Odd = Even)
        // - If odd_count is 1 (one odd, two even) or 2 (two odd, one even),
        //   an odd sum pair (Odd + Even) can always be formed.
        //   (Odd + Even = Odd)
        if (odd_count == 1 || odd_count == 2) {
            return "YES";
        } else {
            return "NO";
        }
    }
};
```