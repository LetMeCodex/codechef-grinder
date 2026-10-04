# [Chef and SnackDown (SNCKYEAR)](https://www.codechef.com/problems/SNCKYEAR)
- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine whether a given year `N` was one of the years when the "SnackDown" programming contest was hosted. We are provided with a specific list of years when SnackDown was hosted: 2010, 2015, 2016, 2017, and 2019. For each given year `N`, we need to output "HOSTED" if it's one of these years, and "NOT HOSTED" otherwise. The program must handle multiple test cases.

## Intuition & Mathematical Observation

The problem is a straightforward conditional check. There's no complex algorithm or deep mathematical observation required. The core idea is to directly compare the input year `N` with the predefined list of years when SnackDown was hosted.

Since the list of hosted years (2010, 2015, 2016, 2017, 2019) is small and fixed, the most intuitive approach is to use a series of `OR` conditions. If `N` matches any of these specific years, we print "HOSTED"; otherwise, we print "NOT HOSTED". This is essentially a direct lookup operation against a small, static set of values.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program reads an integer `N` and performs a constant number of comparisons (at most 5 comparisons in the `if` condition). Reading an integer and performing these comparisons are all $O(1)$ operations. Since there are `T` test cases, the total time complexity will be $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program only uses a few integer variables (`T`, `N`) to store input and loop counters. The amount of memory used does not depend on the input values or the number of test cases. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the year
        cin >> N; // Read the year N for the current test case

        // Check if the year N is one of the years SnackDown was hosted.
        // The problem statement lists these specific years: 2010, 2015, 2016, 2017, 2019.
        if (N == 2010 || N == 2015 || N == 2016 || N == 2017 || N == 2019) {
            // If N matches any of the hosted years, print "HOSTED"
            cout << "HOSTED\n";
        } else {
            // Otherwise (if N is not one of the hosted years), print "NOT HOSTED"
            cout << "NOT HOSTED\n";
        }
    }

    return 0; // Indicate successful program execution
}
```