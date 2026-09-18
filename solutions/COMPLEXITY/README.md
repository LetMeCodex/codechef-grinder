# [Time Complexity (COMPLEXITY)](https://www.codechef.com/problems/COMPLEXITY)
- **Difficulty Rating**: 364
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if algorithm A has a strictly greater time complexity than algorithm B, given the number of comparisons each algorithm performs. We are given two integers, $X$ and $Y$, representing the number of comparisons for algorithm A and algorithm B, respectively. We need to output "YES" if algorithm A has a strictly greater time complexity than algorithm B, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem statement explicitly defines that "algorithm A has more time complexity than algorithm B if it uses MORE number of comparisons." This is a direct and simple condition.

Therefore, to check if algorithm A has a strictly greater time complexity than algorithm B, we only need to compare the number of comparisons they perform. If the number of comparisons for algorithm A ($X$) is strictly greater than the number of comparisons for algorithm B ($Y$), then algorithm A has a greater time complexity. Otherwise, it does not.

Mathematically, this translates to the condition:
$X > Y$

If this condition is true, the answer is "YES".
If this condition is false (i.e., $X \le Y$), the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves reading two integers and performing a single comparison. This operation takes constant time, regardless of the input values of $X$ and $Y$. The loop for test cases runs $T$ times, and each iteration takes $O(1)$ time. Thus, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like $X$, $Y$, and $T$. The memory usage does not grow with the input size. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, string, etc.

using namespace std; // Required to avoid writing std:: prefix

// Function to solve a single test case
void solve() {
    int X, Y; // Declare two integers X and Y
    cin >> X >> Y; // Read the number of comparisons for algorithm A (X) and algorithm B (Y)

    // According to the problem definition, algorithm A has more time complexity
    // than algorithm B if it uses MORE number of comparisons.
    // So, we check if X is strictly greater than Y.
    if (X > Y) {
        cout << "YES\n"; // If X is greater than Y, print YES
    } else {
        cout << "NO\n"; // Otherwise (if X is less than or equal to Y), print NO
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}
```