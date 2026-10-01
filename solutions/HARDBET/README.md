# [Hardest Problem Bet (HARDBET)](https://www.codechef.com/problems/HARDBET)
- **Difficulty Rating**: 803
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a bet between Larry, Bob, and Alice regarding who solved the "hardest" problem. The hardness of a problem is defined by the number of submissions required to solve it. We are given three integers:
1.  `sA`: Number of submissions Larry made for Problem A.
2.  `sB`: Number of submissions Bob made for Problem B.
3.  `sC`: Number of submissions Alice made for Problem C.

The person who solved the problem with the *minimum* number of submissions wins the bet.
- If Problem A (Larry's problem) is the hardest, Larry wins, and we should output "Draw".
- If Problem B (Bob's problem) is the hardest, Bob wins, and we should output "Bob".
- If Problem C (Alice's problem) is the hardest, Alice wins, and we should output "Alice".

It is guaranteed that `sA`, `sB`, and `sC` are distinct, meaning there will always be a unique minimum and thus a unique winner.

## Intuition & Mathematical Observation

The core of this problem is to find the minimum value among three given integers and then determine which of the original integers corresponds to that minimum.

Let the number of submissions be $S_A$, $S_B$, and $S_C$.
The "hardest" problem is the one that required the fewest submissions. Therefore, we need to find the minimum value among $S_A$, $S_B$, and $S_C$.
Mathematically, we are looking for $\min(S_A, S_B, S_C)$.

Once this minimum value is found, we compare it back to the original submission counts:
1.  If $\min(S_A, S_B, S_C) = S_A$, it means Problem A was the hardest. Larry wins, so we print "Draw".
2.  If $\min(S_A, S_B, S_C) = S_B$, it means Problem B was the hardest. Bob wins, so we print "Bob".
3.  If $\min(S_A, S_B, S_C) = S_C$, it means Problem C was the hardest. Alice wins, so we print "Alice".

Since the problem guarantees that $S_A, S_B, S_C$ are distinct, there will be no ties for the minimum value. This simplifies the logic, as exactly one of the three conditions above will be true.

In C++, the `std::min` function can be used with an initializer list (e.g., `min({sA, sB, sC})`) to easily find the minimum of three or more values.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs the following operations:
    1.  Reads three integers (`sA`, `sB`, `sC`). This is a constant time operation.
    2.  Finds the minimum of these three integers using `std::min`. This involves a constant number of comparisons.
    3.  Compares the minimum value with `sA`, `sB`, and `sC` using `if-else if-else` statements. This also involves a constant number of comparisons.
    4.  Prints a string to the console. This is a constant time operation.
    All these operations take constant time, $O(1)$, per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`sA`, `sB`, `sC`, `min_submissions`, `t`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of the input values or the number of test cases (beyond the loop counter). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int sA, sB, sC;
    cin >> sA >> sB >> sC;

    // Find the minimum number of submissions among sA, sB, and sC.
    // std::min with an initializer list is a convenient way to do this in C++11 and later.
    int min_submissions = min({sA, sB, sC});

    // Determine the winner based on which problem has the minimum submissions.
    // Since sA, sB, sC are guaranteed to be distinct, exactly one of these conditions will be true.
    if (min_submissions == sA) {
        cout << "Draw\n"; // Problem A is the hardest (Larry wins)
    } else if (min_submissions == sB) {
        cout << "Bob\n";  // Problem B is the hardest (Bob wins)
    } else { // min_submissions must be sC
        cout << "Alice\n"; // Problem C is the hardest (Alice wins)
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0; // Indicate successful execution
}
```