# [Playing with Strings (PLAYSTR)](https://www.codechef.com/problems/PLAYSTR)
- **Difficulty Rating**: 1108
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a given binary string `S` of length `N` can be transformed into another binary string `R` of the same length `N` using a specific operation. The allowed operation is to choose any two indices `i` and `j` (which can be the same) and swap `S[i]` and `S[j]`. This operation can be performed any number of times. We need to output "YES" if `S` can be transformed into `R`, and "NO" otherwise.

## Intuition & Mathematical Observation
The key to this problem lies in understanding the power of the allowed operation. If we can choose any two indices `i` and `j` and swap `S[i]` and `S[j]`, it means we can effectively rearrange the characters of string `S` in any arbitrary order. This is because any permutation of characters can be achieved through a series of swaps. For example, to move a character from position `k` to position `p`, we can swap `S[k]` with `S[p]`. We can continue this process to place all characters in their desired positions.

Given this, string `S` can be transformed into string `R` if and only if `S` and `R` are anagrams of each other. For binary strings (strings consisting only of '0's and '1's), two strings are anagrams if and only if they have the same count of '0's and the same count of '1's.

Since both strings `S` and `R` have the same length `N`, if the count of '1's in `S` is equal to the count of '1's in `R`, then it automatically implies that the count of '0's in `S` (`N - count_of_1s_in_S`) must also be equal to the count of '0's in `R` (`N - count_of_1s_in_R`).

Therefore, the problem reduces to a simple check: count the number of '1's in string `S` and count the number of '1's in string `R`. If these counts are equal, then `S` can be transformed into `R`, and we output "YES". Otherwise, it's impossible, and we output "NO".

## Complexity Analysis
-   **Time Complexity**: $O(N)$ per test case.
    -   Reading the input strings `S` and `R` takes $O(N)$ time.
    -   Iterating through string `S` to count '1's takes $O(N)$ time.
    -   Iterating through string `R` to count '1's takes $O(N)$ time.
    -   The comparison and output take $O(1)$ time.
    -   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.
-   **Space Complexity**: $O(N)$ per test case.
    -   Storing the input strings `S` and `R` requires $O(N)$ space.
    -   A few integer variables (`n`, `s_ones`, `r_ones`) require $O(1)$ space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the length of the strings
    string s, r;
    cin >> s >> r; // Read the binary strings S and R

    // Count the number of '1's in string S
    int s_ones = 0;
    for (char c : s) {
        if (c == '1') {
            s_ones++;
        }
    }
    // Alternatively, using std::count:
    // int s_ones = count(s.begin(), s.end(), '1');

    // Count the number of '1's in string R
    int r_ones = 0;
    for (char c : r) {
        if (c == '1') {
            r_ones++;
        }
    }
    // Alternatively, using std::count:
    // int r_ones = count(r.begin(), r.end(), '1');

    // If the counts of '1's are equal, then S can be transformed into R
    if (s_ones == r_ones) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```