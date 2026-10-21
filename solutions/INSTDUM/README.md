# [Inside The Stadium (INSTDUM)](https://www.codechef.com/problems/INSTDUM)
- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate a cricket match scenario where we are given the runs scored on `N` consecutive balls. For each ball played, we need to calculate the current strike rate. The strike rate is defined as `(Total Runs Scored / Total Balls Faced) * 100`. Our task is to count how many times, throughout the `N` balls, the strike rate was *exactly* 100.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the condition for the strike rate to be exactly 100.
Let `total_runs` be the cumulative runs scored and `balls_faced` be the cumulative number of balls faced at any given point.
The strike rate formula is:
`Strike Rate = (total_runs / balls_faced) * 100`

We are interested in the cases where `Strike Rate = 100`.
So, we set up the equation:
`(total_runs / balls_faced) * 100 = 100`

To simplify this equation:
1. Divide both sides by 100:
   `total_runs / balls_faced = 1`
2. Multiply both sides by `balls_faced`:
   `total_runs = balls_faced`

This is the key observation! The strike rate is exactly 100 if and only if the total runs scored so far are equal to the total number of balls faced so far.

Therefore, the algorithm is straightforward:
1. Initialize `total_runs = 0` and `count_100_strike_rate = 0`.
2. Iterate from the first ball (`i = 1`) up to the `N`-th ball.
3. In each iteration `i`:
    a. Read the runs scored on the current ball (`A_i`).
    b. Add `A_i` to `total_runs`.
    c. Check if `total_runs` is equal to `i` (which represents `balls_faced`).
    d. If `total_runs == i`, increment `count_100_strike_rate`.
4. After iterating through all `N` balls, print `count_100_strike_rate`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through `N` balls once. Inside the loop, operations like reading input, addition, and comparison are all constant time $O(1)$.
    *   If there are `T` test cases, the total time complexity will be $O(T \cdot N)$. Given the constraints ($T \le 100$, $N \le 100$), the maximum operations would be around $100 \cdot 100 = 10000$, which is very efficient and well within typical time limits.

-   **Space Complexity**: $O(1)$.
    *   We only use a few integer variables (`N`, `total_runs`, `count_100_strike_rate`, `A_i`, `i`, `T`) to store the current state and counts. These variables consume a constant amount of memory regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std:: before standard library elements.
using namespace std; 

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the total number of balls played

    long long total_runs = 0; // Initialize cumulative runs scored.
                              // Using long long to be safe, though int would suffice for given constraints.
    int count_100_strike_rate = 0; // Initialize counter for times strike rate is exactly 100

    // Loop through each ball played.
    // 'i' represents the current number of balls played (from 1 to N).
    for (int i = 1; i <= N; ++i) { 
        int A_i;
        cin >> A_i; // Read runs scored on the i-th ball
        total_runs += A_i; // Add runs to the cumulative total

        // Check if the strike rate is exactly 100.
        // The condition (total_runs / i) * 100 == 100 simplifies to total_runs == i.
        if (total_runs == i) { 
            count_100_strike_rate++; // Increment counter if strike rate is 100
        }
    }

    // Output the total number of times the strike rate was 100 for this test case.
    cout << count_100_strike_rate << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and disables synchronization,
    // which is crucial for problems with large inputs/outputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```