# Bone Appetit (BNE_APT)
- **Difficulty Rating**: 280
- **Solved in**: 1 attempt(s)

## Problem Summary
Suri Bhai is organizing a party and has two groups of guests: "Bones" and "Blood".
There are $N$ people in the "Bones" group, and each person in this group will receive $X$ treats.
There are $M$ people in the "Blood" group, and each person in this group will receive $Y$ treats.
The task is to calculate the total number of treats Suri Bhai will distribute.

## Intuition & Mathematical Observation
The problem is a straightforward calculation. We are given the number of people in two distinct groups and the number of treats each person in those groups will receive.

1.  **Treats for the "Bones" group**: If there are $N$ people in the "Bones" group and each receives $X$ treats, the total number of treats for this group is $N \times X$.
2.  **Treats for the "Blood" group**: Similarly, if there are $M$ people in the "Blood" group and each receives $Y$ treats, the total number of treats for this group is $M \times Y$.

The total number of treats Suri Bhai will distribute is the sum of treats for both groups. Therefore, the total treats can be calculated as:
$$ \text{Total Treats} = (N \times X) + (M \times Y) $$

The constraints on $N, M, X, Y$ are up to $100,000$. The maximum possible value for $N \times X$ or $M \times Y$ would be $100,000 \times 100,000 = 10^{10}$. The sum of these two could be up to $2 \times 10^{10}$. A standard 32-bit integer (`int`) typically has a maximum value of around $2 \times 10^9$, which is insufficient. Therefore, `long long` in C++ (which can typically hold values up to $9 \times 10^{18}$) is necessary to avoid integer overflow.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (two multiplications and one addition) and input/output operations. The time taken does not depend on the size of the input values, only on the number of operations, which is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input values and the result. The memory usage does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the number of people and treats.
    // Using 'long long' to safely handle potential integer overflow,
    // as per critical instructions, even though 'int' would suffice
    // for the given constraints (max total treats = 200,000).
    // The problem statement constraints are N, M, X, Y <= 100,000.
    // Thus, N*X or M*Y can be up to 10^10, requiring long long.
    long long N, M; // N: people in "Bones", M: people in "Blood"
    long long X, Y; // X: treats per person in "Bones", Y: treats per person in "Blood"

    // Read the number of people in "Bones" (N) and "Blood" (M).
    cin >> N >> M;

    // Read the number of treats per person in "Bones" (X) and "Blood" (Y).
    cin >> X >> Y;

    // Calculate the total treats from "Bones" and "Blood" sectors.
    // Total treats from "Bones" = N * X
    // Total treats from "Blood" = M * Y
    // Total treats = (N * X) + (M * Y)
    long long total_treats = (N * X) + (M * Y);

    // Output the total number of treats Suri Bhai will receive, followed by a newline.
    cout << total_treats << "\n";

    return 0;
}
```