# [Dominant Army (DOMINANT)](https://www.codechef.com/problems/DOMINANT)
- **Difficulty Rating**: 488
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an army is "dominant". An army consists of three types of soldiers: type A, type B, and type C, with $n_A$, $n_B$, and $n_C$ soldiers respectively. An army is considered dominant if the number of soldiers of one type is strictly greater than the sum of the soldiers of the other two types. We are given $T$ test cases, and for each test case, we need to output "YES" if the army is dominant, and "NO" otherwise.

## Intuition & Mathematical Observation

The definition of a dominant army is quite straightforward. We need to check three conditions:
1. Is the number of type A soldiers strictly greater than the sum of type B and type C soldiers? ($n_A > n_B + n_C$)
2. Is the number of type B soldiers strictly greater than the sum of type A and type C soldiers? ($n_B > n_A + n_C$)
3. Is the number of type C soldiers strictly greater than the sum of type A and type B soldiers? ($n_C > n_A + n_B$)

If *any* of these conditions are true, the army is dominant. If *none* of these conditions are true, the army is not dominant.

The problem can be solved by simply implementing these three checks. We can use a boolean flag, say `dominant`, initialized to `false`. We then check each of the three conditions. If any condition is met, we set `dominant` to `true`. After checking all three conditions, if `dominant` is `true`, we print "YES"; otherwise, we print "NO".

The provided C++ solution directly implements this logic. It reads the number of test cases `t`. Inside the loop for each test case, it reads $n_A$, $n_B$, and $n_C$. It then checks the three conditions using `if` statements. If any condition is met, `dominant` is set to `true`. Finally, it prints "YES" or "NO" based on the value of `dominant`.

The use of `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` is a standard optimization in competitive programming for faster I/O operations in C++, which is good practice for problems with multiple test cases.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    - For each test case, we perform a fixed number of comparisons and arithmetic operations (three checks, each involving one addition and one comparison). This number is constant and does not depend on the input values $n_A, n_B, n_C$ or the number of test cases $T$. Therefore, the time complexity per test case is $O(1)$.
    - Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$. However, in the context of typical competitive programming analysis where $T$ is a factor, we often state the complexity per test case. If we consider the total input size, it would be $O(T)$. But if we are asked for the complexity in terms of the input values for a single test case, it's $O(1)$. Given the problem constraints and typical analysis, $O(1)$ per test case is the most appropriate description.

- **Space Complexity**: $O(1)$
    - We only use a few integer variables ($t, nA, nB, nC$) and a boolean variable (`dominant`) to store the input and the result. The amount of memory used is constant and does not grow with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Not strictly necessary for this solution, but good practice to include if using std::max etc.

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int nA, nB, nC; // Number of soldiers of type A, B, and C
        std::cin >> nA >> nB >> nC;

        bool dominant = false; // Flag to indicate if the army is dominant

        // Check if type A soldiers are dominant
        if (nA > nB + nC) {
            dominant = true;
        }
        // Check if type B soldiers are dominant
        if (nB > nA + nC) {
            dominant = true;
        }
        // Check if type C soldiers are dominant
        if (nC > nA + nB) {
            dominant = true;
        }

        // Output the result
        if (dominant) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```