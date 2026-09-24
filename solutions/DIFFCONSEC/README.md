# [Different Consecutive Characters (DIFFCONSEC)](https://www.codechef.com/problems/DIFFCONSEC)
- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to transform a given binary string (composed of '0's and '1's) such that no two adjacent characters are the same. An operation consists of inserting any character between two adjacent identical characters.

For example:
- If the string is "00", we can insert a '1' to make it "010". This takes 1 operation.
- If the string is "111", we can insert a '0' between the first two '1's to get "1011". Now, the last two '1's are still identical. We insert a '0' between them to get "10101". This takes a total of 2 operations.

The goal is to determine this minimum number of operations.

## Intuition & Mathematical Observation

Let's consider the conditions under which an operation is necessary. An operation is required *only if* we find two adjacent characters `s[i]` and `s[i+1]` that are identical. If `s[i] == s[i+1]`, we *must* perform an operation to break this pair.

What happens when we perform an operation? We insert a character (say, `X`) between `s[i]` and `s[i+1]`. The string segment `s[i]s[i+1]` becomes `s[i]Xs[i+1]`.
The character `X` can be chosen such that `X != s[i]` and `X != s[i+1]`. Since the string is binary, if `s[i] == '0'`, we insert '1'; if `s[i] == '1'`, we insert '0'. This ensures that `s[i]` is now followed by `X` (which is different from `s[i]`), and `X` is followed by `s[i+1]` (which is different from `X`). Thus, the pair `(s[i], s[i+1])` is resolved.

The crucial observation is that performing an operation to fix the pair `(s[i], s[i+1])` does not negatively affect any other part of the string:
1.  It does not affect any pairs `(s[j], s[j+1])` where `j < i-1`. These pairs are to the left and are already processed or don't exist.
2.  It does not affect the need for an operation for the pair `(s[i+1], s[i+2])`. The characters `s[i+1]` and `s[i+2]` (from the original string) remain adjacent to each other, even though `s[i+1]` is now preceded by an inserted character. If `s[i+1] == s[i+2]` in the original string, they will still be identical after the insertion at `i`. Therefore, a separate operation will still be needed for `(s[i+1], s[i+2])`.

This means that each time we encounter `s[i] == s[i+1]`, we increment our operation count. This greedy strategy works because each problematic pair `(s[i], s[i+1])` requires exactly one operation, and this operation does not create new problems or make existing problems harder to solve. We simply iterate through the string from left to right, checking each adjacent pair.

For example, with "000":
-   `i = 0`: `s[0] = '0'`, `s[1] = '0'`. They are equal. Increment `operations` to 1. (Conceptually: "0100")
-   `i = 1`: `s[1] = '0'`, `s[2] = '0'`. They are equal. Increment `operations` to 2. (Conceptually: "01010")
-   The loop continues until `i = n-2`.
The total operations will be 2.

This approach guarantees the minimum number of operations because each `s[i] == s[i+1]` pair *must* be fixed, and our method fixes each such pair with exactly one operation without interfering with others.

## Complexity Analysis

-   **Time Complexity**: The solution involves a single loop that iterates from `i = 0` to `n - 2`, where `n` is the length of the input string. Inside the loop, constant-time operations (character comparison and integer increment) are performed. Reading the input string also takes $O(N)$ time. Therefore, for each test case, the time complexity is $O(N)$. Given `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: The solution uses a few integer variables (`n`, `operations`, `i`) and stores the input string `s`. The space required to store the string `s` is $O(N)$. The other variables occupy a constant amount of space. Therefore, the total space complexity is $O(N)$ for storing the string.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header
using namespace std;     // Required namespace

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    // Iterate through the string to check adjacent characters.
    // The loop runs from i = 0 to n-2, checking pairs (s[i], s[i+1]).
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            operations++;
            // When s[i] == s[i+1], we must perform an operation.
            // This operation involves inserting a character (e.g., '1' if s[i]=='0')
            // between s[i] and s[i+1].
            // Example: "00" -> "010".
            // This fixes the current pair (s[i], s[i+1]).
            // The character s[i+1] (original) is now preceded by the inserted character.
            // However, s[i+1] is still followed by s[i+2] (original).
            // The pair (s[i+1], s[i+2]) might still be problematic (e.g., "000").
            // "000" -> "0100" (1 op). Now we need to check the next pair.
            // The next pair to check is effectively (s[i+1], s[i+2]) from the original string.
            // The loop's `++i` naturally moves to `i+1` for the next iteration,
            // which correctly checks `s[i+1]` against `s[i+2]`.
            // No extra `i++` is needed here.
        }
    }
    cout << operations << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(NULL);                   // Untie cin from cout

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}
```