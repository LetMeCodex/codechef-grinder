# [Police and Thief (POLTHIEF)](https://www.codechef.com/problems/POLTHIEF)
- **Difficulty Rating**: 639
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum time it takes for a policeman to catch a thief. The policeman is initially at position $X$ and moves with a speed of 2 units per second. The thief is initially at position $Y$ and moves with a speed of 1 unit per second. The thief will try to evade the policeman for as long as possible. Both are on a 1D line.

## Intuition & Mathematical Observation

Let $X$ be the initial position of the policeman and $Y$ be the initial position of the thief.
Let $t$ be the time elapsed in seconds.

The policeman's speed is $v_P = 2$ units/sec.
The thief's speed is $v_T = 1$ unit/sec.

The core of the problem lies in understanding the thief's strategy. The thief wants to maximize the time until they are caught. This means the thief will always move in a direction that increases the distance between them and the policeman, or at least delays the inevitable meeting.

Consider two cases:

**Case 1: Policeman is to the left of the thief ($X < Y$)**
The policeman needs to move towards the thief, i.e., to the right.
The thief can either move to the right (away from the policeman) or to the left (towards the policeman).

*   **Thief moves right (evading):**
    Policeman's position at time $t$: $X + 2t$
    Thief's position at time $t$: $Y + t$
    They meet when $X + 2t = Y + t$.
    Solving for $t$: $2t - t = Y - X \implies t = Y - X$.

*   **Thief moves left (towards policeman):**
    Policeman's position at time $t$: $X + 2t$
    Thief's position at time $t$: $Y - t$
    They meet when $X + 2t = Y - t$.
    Solving for $t$: $2t + t = Y - X \implies 3t = Y - X \implies t = \frac{Y - X}{3}$.

Since the thief wants to maximize evasion time, they will choose to move right, resulting in a catch time of $t = Y - X$.

**Case 2: Policeman is to the right of the thief ($X > Y$)**
The policeman needs to move towards the thief, i.e., to the left.
The thief can either move to the left (away from the policeman) or to the right (towards the policeman).

*   **Thief moves left (evading):**
    Policeman's position at time $t$: $X - 2t$
    Thief's position at time $t$: $Y - t$
    They meet when $X - 2t = Y - t$.
    Solving for $t$: $X - Y = 2t - t \implies t = X - Y$.

*   **Thief moves right (towards policeman):**
    Policeman's position at time $t$: $X - 2t$
    Thief's position at time $t$: $Y + t$
    They meet when $X - 2t = Y + t$.
    Solving for $t$: $X - Y = 2t + t \implies 3t = X - Y \implies t = \frac{X - Y}{3}$.

Since the thief wants to maximize evasion time, they will choose to move left, resulting in a catch time of $t = X - Y$.

**Case 3: Policeman and thief are at the same position ($X = Y$)**
If $X = Y$, the policeman catches the thief immediately. The time taken is $0$.

**Unified Observation:**
In all cases, the time taken for the policeman to catch the thief, assuming the thief plays optimally to evade, is the absolute difference between their initial positions: $|X - Y|$.

If $X < Y$, the time is $Y - X = |X - Y|$.
If $X > Y$, the time is $X - Y = |X - Y|$.
If $X = Y$, the time is $0 = |X - Y|$.

Therefore, the minimum time for the policeman to catch the thief is simply the absolute difference between their initial positions.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of operations: reading two integers, calculating their absolute difference, and printing the result.

-   **Space Complexity**: $O(1)$
    We only use a few variables to store the input values and the result, which requires constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath (for abs), etc.

// Using namespace std; is common in competitive programming for brevity.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times for each test case.
        int X, Y;
        cin >> X >> Y; // Read the initial locations of the policeman (X) and thief (Y).
        
        // The problem states the policeman's speed is 2 units/sec and the thief's speed is 1 unit/sec.
        // The thief tries to evade for as long as possible.
        //
        // If the policeman is at X and the thief is at Y:
        // 1. If X < Y (policeman is to the left of the thief):
        //    The policeman will move right (towards Y).
        //    - If the thief also moves right (evading):
        //      Policeman's position: X + 2t
        //      Thief's position: Y + t
        //      They meet when X + 2t = Y + t => t = Y - X
        //    - If the thief moves left (towards policeman):
        //      Policeman's position: X + 2t
        //      Thief's position: Y - t
        //      They meet when X + 2t = Y - t => 3t = Y - X => t = (Y - X) / 3
        //    To maximize evasion time, the thief chooses to move right, so time = Y - X.
        //
        // 2. If X > Y (policeman is to the right of the thief):
        //    The policeman will move left (towards Y).
        //    - If the thief also moves left (evading):
        //      Policeman's position: X - 2t
        //      Thief's position: Y - t
        //      They meet when X - 2t = Y - t => t = X - Y
        //    - If the thief moves right (towards policeman):
        //      Policeman's position: X - 2t
        //      Thief's position: Y + t
        //      They meet when X - 2t = Y + t => 3t = X - Y => t = (X - Y) / 3
        //    To maximize evasion time, the thief chooses to move left, so time = X - Y.
        //
        // In both cases, the minimum time for the policeman to catch the thief, considering the thief's optimal evasion,
        // is simply the absolute difference between their initial positions.
        // If X == Y, the time is 0, which is correctly given by abs(X - Y).
        
        int time_taken = abs(X - Y); // Calculate the absolute difference.
        cout << time_taken << "\n"; // Output the result followed by a newline.
    }
    return 0; // Indicate successful execution.
}
```