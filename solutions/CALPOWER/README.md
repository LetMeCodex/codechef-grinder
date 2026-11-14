Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the Cool Name (CALPOWER) problem:

# [Cool Name (CALPOWER)](https://www.codechef.com/problems/CALPOWER)
- **Difficulty Rating**: 1223
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the "power" of a given string. The power is defined by a specific process:
1. First, the input string must be sorted alphabetically.
2. After sorting, for each character in the string, its contribution to the total power is calculated as `(1-based position) * (ord_value)`.
3. The `ord_value` for 'a' is 1, 'b' is 2, ..., 'z' is 26.
4. The total power is the sum of these contributions for all characters.

We need to perform this calculation for multiple test cases.

## Intuition & Mathematical Observation

The problem statement explicitly dictates the process: "The power of a string is calculated by first sorting the string alphabetically." This is the most crucial piece of information. It means we don't need to find an optimal arrangement; we simply follow the given rule.

Let's break down the calculation:
1.  **Sorting**: The first step is to sort the input string `s` alphabetically. For example, if `s = "bca"`, after sorting it becomes `s' = "abc"`.
2.  **Character Ordinal Value**: For any character `c`, its `ord_value` can be calculated as `c - 'a' + 1`.
    *   For 'a': `'a' - 'a' + 1 = 0 + 1 = 1`
    *   For 'b': `'b' - 'a' + 1 = 1 + 1 = 2`
    *   ...
    *   For 'z': `'z' - 'a' + 1 = 25 + 1 = 26`
3.  **Position**: After sorting, if a character is at 0-indexed position `i` in the string, its 1-based position is `i + 1`.
4.  **Total Power**: We iterate through the sorted string. For each character `s'[i]` at 0-indexed position `i`:
    *   Its 1-based position is `(i + 1)`.
    *   Its `ord_value` is `(s'[i] - 'a' + 1)`.
    *   Its contribution is `(i + 1) * (s'[i] - 'a' + 1)`.
    *   We sum these contributions to get the `total_power`.

**Data Type Consideration**:
The maximum length of the string `N` is $10^5$.
The maximum `ord_value` is 26 (for 'z').
The maximum 1-based position is $10^5$.
A single term in the sum can be up to $10^5 \times 26 = 2.6 \times 10^6$.
The total sum can be much larger. If all characters are 'z' and $N=10^5$:
Total Power $\approx \sum_{i=1}^{10^5} i \times 26 = 26 \times \frac{10^5 \times (10^5 + 1)}{2} \approx 26 \times \frac{10^{10}}{2} \approx 1.3 \times 10^{11}$.
This value exceeds the capacity of a standard 32-bit integer (which is around $2 \times 10^9$). Therefore, a `long long` data type is essential for `total_power` and for the intermediate product `(i + 1) * (s[i] - 'a' + 1)` to prevent overflow. The solution code correctly uses `long long` for `total_power` and casts `(i + 1)` to `long long` before multiplication.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading the input string of length $N$: $O(N)$.
    *   Sorting the string using `std::sort`: $O(N \log N)$. This is the dominant operation.
    *   Iterating through the sorted string to calculate the sum: $O(N)$.
    *   For each test case, the total time complexity is $O(N \log N)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot N \log N)$. With $T \le 100$ and $N \le 10^5$, this is approximately $100 \times 10^5 \times \log_2(10^5) \approx 10^7 \times 17 \approx 1.7 \times 10^8$ operations, which is acceptable within typical time limits for competitive programming (usually 1-2 seconds).

*   **Space Complexity**:
    *   Storing the input string `s`: $O(N)$.
    *   `std::sort` typically uses $O(\log N)$ auxiliary space for its recursive calls (e.g., IntroSort) or $O(1)$ if it falls back to HeapSort.
    *   Other variables (`total_power`, loop counter `i`, `t`): $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    string s;
    cin >> s;

    // Sort the string to arrange characters in ascending order of their ord values.
    // This is because 'a' < 'b' < ... < 'z' lexicographically,
    // which corresponds to their ord values.
    sort(s.begin(), s.end());

    long long total_power = 0;
    for (int i = 0; i < s.length(); ++i) {
        // The character at 0-indexed position i is s[i].
        // Its 1-based position in the sorted string is (i+1).
        // Its ord value is (s[i] - 'a' + 1).
        // Cast (i + 1) to long long to ensure the multiplication is done using long long arithmetic
        // before adding to total_power, preventing potential intermediate overflow.
        total_power += (long long)(i + 1) * (s[i] - 'a' + 1);
    }

    cout << total_power << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```