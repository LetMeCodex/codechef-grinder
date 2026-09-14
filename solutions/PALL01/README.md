# [The Block Game (PALL01)](https://www.codechef.com/problems/PALL01)

- **Difficulty Rating**: 830
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine whether a given integer $N$ is a palindrome. A palindrome is a number that reads the same forwards and backwards (e.g., 121, 55, 12321). For each test case, if the number is a palindrome, output "wins"; otherwise, output "loses".

## Intuition & Mathematical Observation
A number is a palindrome if its sequence of digits remains unchanged when reversed. 

There are two primary ways to solve this:
1. **Mathematical Approach**: Extract digits using the modulo operator (`% 10`) and build the reversed number by multiplying the current result by 10 and adding the extracted digit.
2. **String Manipulation Approach**: Since the input is treated as a sequence of characters, we can read the number as a `string`. By using the built-in `reverse()` function in C++, we can easily compare the original string with its reversed version.

The string approach is highly efficient for this problem because the constraints on $N$ are small, and it reduces the risk of overflow errors associated with reversing large integers mathematically.

## Complexity Analysis
- **Time Complexity**: $O(D)$, where $D$ is the number of digits in $N$. Since $N$ is typically small (e.g., up to 5 or 6 digits), this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(D)$ to store the string representation of the number.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Block Game (PALL01)
 * Approach: 
 * To check if a number is a palindrome, we convert the integer to a string 
 * and compare it with its reverse. This is clean and avoids potential 
 * integer overflow issues during reversal.
 */

void solve() {
    string n;
    cin >> n;
    
    // Create a copy and reverse it
    string reversed_n = n;
    reverse(reversed_n.begin(), reversed_n.end());
    
    // Compare original with reversed
    if (n == reversed_n) {
        cout << "wins" << "\n";
    } else {
        cout << "loses" << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```