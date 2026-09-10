# [Candy Division (CANDIVIDE)](https://www.codechef.com/problems/CANDIVIDE)
- **Difficulty Rating**: 289
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given number of candies, `N`, can be divided equally among three friends. The conditions are that all candies must be distributed, and each friend must receive an integer number of candies. We need to output "YES" if it's possible, and "NO" otherwise. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The core of this problem lies in a simple mathematical concept: divisibility.
If `N` candies are to be divided equally among three friends, and each friend must receive an integer number of candies, it implies that `N` must be perfectly divisible by 3.

*   **If N is divisible by 3**: This means `N` can be expressed as `3 * K` for some integer `K`. In this case, each friend would receive `K = N / 3` candies, which is an integer. So, the division is possible.
*   **If N is not divisible by 3**: This means `N` divided by 3 would result in a remainder (either 1 or 2). In this scenario, it's impossible to distribute the candies such that each friend gets an integer amount and no candies are left over or extra.

Therefore, the solution boils down to checking if `N % 3 == 0`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, for each test case, it performs a constant number of operations: reading an integer `N`, performing a modulo operation (`N % 3`), and printing "YES" or "NO". These operations take constant time, $O(1)$.
    *   Thus, the total time complexity is proportional to the number of test cases, $T$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `N`) to store input and loop counters. These variables occupy a constant amount of memory regardless of the input values or the number of test cases.
    *   No dynamic data structures or arrays are used that would scale with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N to store the number of candies.
        cin >> N; // Read the number of candies for the current test case.

        // To distribute N candies equally among three friends such that all candies
        // are used and each friend gets an integer number of candies, N must be
        // perfectly divisible by 3.
        // If N % 3 == 0, then each friend gets N/3 candies.
        // Otherwise, it's impossible to distribute them equally.
        if (N % 3 == 0) {
            cout << "YES\n"; // If N is divisible by 3, output "YES".
        } else {
            cout << "NO\n"; // Otherwise, output "NO".
        }
    }

    return 0; // Indicate successful program execution.
}
```