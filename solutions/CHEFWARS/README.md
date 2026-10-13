# [Chef Wars - Return of the Jedi (CHEFWARS)](https://www.codechef.com/problems/CHEFWARS)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a battle between Chef and Darth. Darth has an initial health `H`, and Chef starts with an initial attack power `P`. The battle proceeds in turns:
1.  Chef attacks Darth, reducing Darth's health `H` by Chef's current attack power `P`.
2.  Chef's attack power `P` is then halved (using integer division).

The battle continues as long as both Darth's health `H` and Chef's attack power `P` are positive. We need to determine the outcome:
*   If Darth's health `H` drops to 0 or below, Chef wins.
*   If Chef's attack power `P` drops to 0 while Darth's health `H` is still positive, Chef loses.

The program should output `1` if Chef wins, and `0` if Chef loses.

## Intuition & Mathematical Observation

The problem statement directly describes a turn-based simulation. The most straightforward approach is to simulate the battle turn by turn, applying the given rules until a termination condition is met.

**Simulation Logic:**
We can use a `while` loop that continues as long as both Darth's health (`H`) and Chef's attack power (`P`) are greater than zero.
Inside the loop, in each turn:
1.  Darth's health is reduced: `H = H - P`.
2.  Chef's attack power is halved: `P = P / 2` (integer division automatically handles flooring).

**Termination Conditions:**
The loop will naturally terminate when one of the conditions `H > 0` or `P > 0` becomes false.
*   If `H <= 0` after the loop, it means Chef successfully depleted Darth's health. Chef wins.
*   If `P <= 0` (and thus `H` must still be `> 0` for the loop to have terminated this way), it means Chef ran out of attack power while Darth was still alive. Chef loses.

**Mathematical Observation on `P`:**
Chef's attack power `P` is repeatedly halved in each turn. This is a very rapid decrease. For example, if `P` starts at $10^9$, it will become $10^9/2$, then $10^9/4$, and so on. The number of times an integer `P` can be halved before it reaches 0 is logarithmic with respect to its initial value, specifically $\log_2(\text{initial } P)$. Since the maximum initial `P` is $10^9$, $\log_2(10^9) \approx 29.89$, meaning the loop will run at most about 30-31 times. This makes the simulation extremely efficient and fast enough for the given constraints.

## Complexity Analysis

*   **Time Complexity**:
    The core of the solution is the `while` loop within the `solve()` function. In each iteration of this loop, Chef's attack power `P` is divided by 2. Since `P` starts with a maximum value of $10^9$, it will take approximately $\log_2(10^9)$ iterations for `P` to become 0. $\log_2(10^9)$ is roughly 30. Thus, the `while` loop runs a very small, constant number of times (at most about 30-31 iterations). All operations inside the loop are constant time.
    The `main` function calls `solve()` for `T` test cases.
    Therefore, the total time complexity is $O(T \cdot \log P_{max})$, where $P_{max}$ is the maximum possible initial attack power. Given $T \le 1000$ and $P_{max} \le 10^9$, this is roughly $1000 \times 30 = 30,000$ operations, which is extremely fast.
    This simplifies to **$O(\log P)$ per test case**.

*   **Space Complexity**:
    The solution uses a few integer variables (`H`, `P`, `T`) to store input values and loop counters. These variables consume a constant amount of memory regardless of the input size.
    Therefore, the space complexity is **$O(1)$**.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Using namespace std; is a common practice in competitive programming
// to avoid repeatedly typing std:: before standard library elements.
using namespace std;

void solve() {
    int H, P;
    // Read Darth's initial health H and Chef's initial attack power P
    cin >> H >> P;

    // Simulate the battle turn by turn
    // The loop continues as long as:
    // 1. Darth's health is positive (H > 0) - meaning Darth is still alive.
    // 2. Chef's attack power is positive (P > 0) - meaning Chef can still attack.
    while (H > 0 && P > 0) {
        H -= P;    // Darth's health decreases by the current attack power
        P /= 2;    // Chef's attack power is halved (integer division automatically handles floor)
    }

    // After the loop terminates, one of the conditions (H > 0 or P > 0) must have become false.

    // If H <= 0, it means Darth's health dropped to 0 or below.
    // This implies Chef dealt enough damage before his attack power ran out.
    if (H <= 0) {
        cout << 1 << "\n"; // Chef wins, print 1
    } else {
        // If H > 0, it means P must have become 0 (since the loop terminated).
        // Chef's attack power ran out while Darth was still alive.
        cout << 0 << "\n"; // Chef loses, print 0
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with large numbers of test cases or large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL);                   // Prevents cin from flushing cout before each input operation

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}
```