# [Marathon (MARARUN)](https://www.codechef.com/problems/MARARUN)
- **Difficulty Rating**: 955
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is participating in a marathon. The marathon has a total distance of $D$ kilometers, and Chef runs $d$ kilometers each day. Chef can win prizes based on the total distance covered. If Chef covers at least 10 km, they win prize $A$. If they cover at least 21 km, they win prize $B$. If they cover at least 42 km, they win prize $C$. Note that these are cumulative prizes; if Chef covers 42 km, they are eligible for all three prizes, but they only receive the highest prize they qualify for. The goal is to determine the maximum prize Chef can win.

## Intuition & Mathematical Observation
The problem asks us to find the maximum prize Chef can win. The prizes are awarded based on specific distance thresholds: 10 km, 21 km, and 42 km. The key observation is that the prizes are structured such that if Chef qualifies for a higher distance threshold, they also qualify for all lower distance thresholds. For example, covering 42 km means Chef also covers at least 21 km and at least 10 km. Therefore, Chef should always aim for the highest possible prize they qualify for.

The total distance Chef can cover is simply the product of the total number of days ($D$) and the distance covered per day ($d$). Let this total distance be $T_{dist} = D \times d$.

We need to check the conditions for winning prizes in descending order of prize value (which corresponds to descending order of distance thresholds):

1.  **Prize C**: Chef wins prize $C$ if $T_{dist} \ge 42$.
2.  **Prize B**: If Chef does not qualify for prize $C$ (i.e., $T_{dist} < 42$), they check if they qualify for prize $B$. Chef wins prize $B$ if $T_{dist} \ge 21$.
3.  **Prize A**: If Chef does not qualify for prize $C$ or $B$ (i.e., $T_{dist} < 21$), they check if they qualify for prize $A$. Chef wins prize $A$ if $T_{dist} \ge 10$.
4.  **No Prize**: If $T_{dist} < 10$, Chef does not qualify for any prize, and the prize won is 0.

By checking these conditions in this order, we can directly determine the maximum prize.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication and comparisons) for each test case. The number of operations does not depend on the input values $D$, $d$, $A$, $B$, or $C$, nor on the number of test cases $T$. Therefore, the time complexity per test case is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store the input values and the calculated total distance and maximum prize. The memory usage does not grow with the input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming
using namespace std;     // Allows using standard library elements without the std:: prefix

void solve() {
    int D, d, A, B, C;
    // Read the five integers for the current test case
    cin >> D >> d >> A >> B >> C;

    // Calculate the total distance Chef can cover
    int chef_total_dist = D * d;

    int max_prize = 0; // Initialize max_prize to 0 (in case no prize is won)

    // Check categories from highest prize to lowest prize
    // Category 3: 42 km, Prize C
    if (chef_total_dist >= 42) {
        max_prize = C;
    } 
    // Category 2: 21 km, Prize B
    else if (chef_total_dist >= 21) {
        max_prize = B;
    } 
    // Category 1: 10 km, Prize A
    else if (chef_total_dist >= 10) {
        max_prize = A;
    } 
    // If none of the above conditions are met, chef_total_dist is less than 10 km,
    // so Chef cannot win any prize. max_prize remains 0.

    // Output the maximum prize Chef can win, followed by a newline
    cout << max_prize << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```