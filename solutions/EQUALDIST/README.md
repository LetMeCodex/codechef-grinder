# [Equal Distribution (EQUALDIST)](https://www.codechef.com/problems/EQUALDIST)
- **Difficulty Rating**: 330
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has `A` chocolates and Bob has `B` chocolates. They want to distribute *all* their chocolates equally between themselves. The task is to determine if it's possible to distribute all chocolates such that both Alice and Bob end up with the same number of chocolates. Output "YES" if possible, "NO" otherwise.

## Intuition & Mathematical Observation
The core idea behind distributing items equally among a certain number of people is divisibility.
1.  **Total Chocolates**: First, we need to find the total number of chocolates available. This is simply the sum of chocolates Alice has and Bob has: `Total Chocolates = A + B`.
2.  **Number of People**: There are two people involved: Alice and Bob.
3.  **Equal Distribution Condition**: For the `Total Chocolates` to be distributed equally between 2 people, the `Total Chocolates` must be perfectly divisible by 2. This means that the `Total Chocolates` must be an even number. If the total is even, each person will receive `(A + B) / 2` chocolates. If the total is odd, it's impossible to distribute them equally without breaking chocolates (which is not allowed in this context).

Therefore, the problem boils down to a simple check: is `(A + B)` an even number?
This can be checked using the modulo operator: `(A + B) % 2 == 0`.

## Complexity Analysis
*   **Time Complexity**: $O(T)$
    The solution involves a loop that runs `T` times, where `T` is the number of test cases. Inside the loop, we perform a constant number of operations: reading two integers, performing an addition, a modulo operation, and printing a string. Each of these operations takes constant time, $O(1)$. Thus, the total time complexity is directly proportional to the number of test cases, making it $O(T)$. Given $T \le 1000$, this is extremely efficient.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory regardless of the input values `A` and `B` (within their constraints). We only store a few variables like `t`, `a`, and `b`. No data structures that grow with input size are used. Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' for the number of test cases.
    
    // Read the number of test cases.
    // The 'if (!(cin >> t)) return 0;' is a robust way to handle input,
    // though for competitive programming, 'cin >> t;' is usually sufficient
    // as input is guaranteed to be valid.
    if (!(cin >> t)) return 0; 
    
    // Loop through each test case.
    while (t--) {
        long long a, b; // Declare 'a' and 'b' to store the number of chocolates.
                        // Using 'long long' is a safe practice, though for A, B <= 10^5,
                        // their sum (max 2*10^5) would fit in an 'int'.
        
        // Read the number of chocolates Alice and Bob have.
        cin >> a >> b;
        
        // Check if the sum of chocolates is even.
        // If (a + b) is divisible by 2, it means they can be distributed equally.
        if ((a + b) % 2 == 0) {
            cout << "YES" << "\n"; // Output "YES" followed by a newline.
        } else {
            cout << "NO" << "\n";  // Output "NO" followed by a newline.
        }
    }
    
    return 0; // Indicate successful program execution.
}

```