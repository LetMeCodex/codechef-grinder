# Olympics Ranking (OLYRANK)

- **Difficulty Rating**: 893
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine which of two countries, Country 1 or Country 2, has a better ranking in the Olympics based on their medal counts. We are given the number of gold, silver, and bronze medals for each country. The ranking is determined by the total number of medals. The country with more total medals is ranked higher. We are guaranteed that there will be no ties in the total medal count.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how the ranking is determined. The problem statement explicitly states that the ranking is based on the *total* number of medals. This means we don't need to consider the individual medal types (gold, silver, bronze) separately for ranking purposes.

Let:
- $G_1, S_1, B_1$ be the gold, silver, and bronze medals for Country 1.
- $G_2, S_2, B_2$ be the gold, silver, and bronze medals for Country 2.

The total number of medals for Country 1 is $Total_1 = G_1 + S_1 + B_1$.
The total number of medals for Country 2 is $Total_2 = G_2 + S_2 + B_2$.

According to the problem, Country 1 is ranked better if $Total_1 > Total_2$. Otherwise, Country 2 is ranked better. Since ties are not possible, if $Total_1$ is not greater than $Total_2$, then $Total_2$ must be greater than $Total_1$.

Therefore, the logic is straightforward:
1. Calculate the sum of medals for Country 1.
2. Calculate the sum of medals for Country 2.
3. Compare these two sums.
4. If Country 1's sum is greater, output "1".
5. Otherwise, output "2".

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (additions and comparisons) for each test case, regardless of the input values. The loop runs $T$ times, where $T$ is the number of test cases. Thus, for each test case, the time complexity is constant.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store the medal counts and the number of test cases. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        // Declare six integer variables to store medal counts for two countries
        int G1, S1, B1; // Gold, Silver, Bronze for Country 1
        int G2, S2, B2; // Gold, Silver, Bronze for Country 2

        // Read the medal counts for both countries
        cin >> G1 >> S1 >> B1 >> G2 >> S2 >> B2;

        // Calculate the total number of medals for Country 1
        int total_medals_1 = G1 + S1 + B1;

        // Calculate the total number of medals for Country 2
        int total_medals_2 = G2 + S2 + B2;

        // Compare the total medals to determine which country is ranked better
        // The problem guarantees there will not be a tie.
        if (total_medals_1 > total_medals_2) {
            // If Country 1 has more medals, print "1"
            cout << "1\n";
        } else {
            // Otherwise (Country 2 must have more medals), print "2"
            cout << "2\n";
        }
    }

    return 0; // Indicate successful execution
}
```