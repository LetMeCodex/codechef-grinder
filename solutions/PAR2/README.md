# [Parity (PAR2)](https://www.codechef.com/problems/PAR2)

- **Difficulty Rating**: 295
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether it is possible to divide $N$ chocolates equally between two friends. Since there are exactly two friends, the chocolates can be divided equally if and only if the total number of chocolates $N$ is an even number.

## Intuition & Mathematical Observation
The core of the problem is determining the parity of an integer $N$. 
- If $N$ is **even**, it can be expressed as $2k$ for some integer $k$. Dividing $2k$ by 2 results in $k$ chocolates for each friend, which is a valid equal distribution.
- If $N$ is **odd**, it can be expressed as $2k + 1$. Dividing this by 2 results in $k.5$ chocolates per person, which is not possible without breaking the chocolates.

Therefore, we simply need to check if $N \pmod 2 == 0$. If the condition holds, output "Yes"; otherwise, output "No".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ modulo operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the value of T from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the number of chocolates
        cin >> N; // Read the value of N for the current test case

        // Check if N is an even number.
        // An even number is perfectly divisible by 2, leaving a remainder of 0.
        if (N % 2 == 0) {
            cout << "Yes\n"; // Output "Yes" followed by a newline
        } else {
            // If N is odd, it's not perfectly divisible by 2.
            cout << "No\n"; // Output "No" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}
```