# Chef in Heaven (CCHEAVEN)
- **Difficulty Rating**: 1317
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is given a sequence of $L$ years, represented by a binary string $S$. A '1' in the string denotes a good year, and a '0' denotes a bad year. Chef can go to heaven if there exists a prefix of the sequence of years, say of length $L'$, such that the number of good years within this prefix is at least half the length of the prefix. That is, if $G(L')$ is the count of '1's in the first $L'$ years, Chef can go to heaven if there exists an $L'$ ($1 \le L' \le L$) such that $2 \times G(L') \ge L'$.

## Intuition & Mathematical Observation

The problem asks us to determine if there's *any* prefix of the given year sequence that satisfies a specific condition. The condition is that the number of good years in that prefix must be at least half the length of the prefix.

Let's denote the length of the prefix as $L'$ and the number of good years in that prefix as $G(L')$. The condition can be written as:
$G(L') \ge \frac{L'}{2}$
Multiplying both sides by 2 gives us the form used in the problem statement:
$2 \times G(L') \ge L'$

We need to check this condition for all possible prefix lengths $L'$, where $L'$ can range from 1 to $L$.

A straightforward approach is to iterate through each possible prefix length. For each prefix length $L'$, we can calculate the number of good years within that prefix and then check if the condition $2 \times G(L') \ge L'$ holds.

We can maintain a running count of good years as we iterate through the string $S$. Let's say we are considering a prefix of length $i+1$ (where $i$ is the 0-based index in the string $S$). We can keep a variable `good_years_count` that stores the number of '1's encountered so far. When we move from a prefix of length $i$ to a prefix of length $i+1$, we simply check if $S[i]$ is '1'. If it is, we increment `good_years_count`.

Then, for the current prefix length $(i+1)$, we check if $2 \times \text{good\_years\_count} \ge (i+1)$. If this condition is met for any $i$ from 0 to $L-1$, then Chef can go to heaven, and we can immediately output "YES" and stop.

If we iterate through all possible prefix lengths (from $L'=1$ to $L'=L$) and the condition is never met, then Chef cannot go to heaven, and we should output "NO".

This approach directly translates the problem statement into an algorithm. There are no complex mathematical insights required beyond understanding the inequality. The key is to efficiently check all prefixes.

## Complexity Analysis

- **Time Complexity**: $O(L)$
    The solution iterates through the input string $S$ of length $L$ exactly once. Inside the loop, operations like incrementing a counter and performing a comparison are constant time operations. Therefore, the total time complexity is directly proportional to the length of the string $L$.

- **Space Complexity**: $O(1)$
    The solution uses a few variables to store the count of good years, the loop index, and a boolean flag. The amount of memory used does not depend on the input size $L$. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries
using namespace std;

void solve() {
    int L;
    cin >> L; // Read the total number of years
    string S;
    cin >> S; // Read the string representing good/bad years

    int good_years_count = 0; // Counter for good years in the current prefix
    bool can_go_to_heaven = false; // Flag to indicate if Chef can go to heaven

    // Iterate through all possible L' values, from 1 to L.
    // 'i' is the 0-based index, so (i + 1) represents the current L'.
    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years_count++; // Increment if the current year is good
        }

        // Check the condition: 2 * (good years) >= (total years lived)
        // Here, total years lived is (i + 1)
        if (2 * good_years_count >= (i + 1)) {
            can_go_to_heaven = true; // Condition met, Chef can go to heaven
            break; // No need to check further L' values
        }
    }

    // Output the result based on the flag
    if (can_go_to_heaven) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```