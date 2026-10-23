# [Front-Back Matching (FBMATCH)](https://www.codechef.com/problems/FBMATCH)
- **Difficulty Rating**: 632
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to form a "front-back matching string" `P` of length `N` using all characters of a given string `S` of length `N`. A string `P` is defined as front-back matching if `P[i] = P[N-1-i]` for all `0 <= i < N`. This is the standard definition of a palindrome. Therefore, the problem essentially asks: Can the characters of string `S` be rearranged to form a palindrome?

## Intuition & Mathematical Observation

### Standard Palindrome Anagram Condition

A string can be rearranged to form a palindrome if and only if, in its character frequency count:
1.  If the string's length `N` is even, all characters must appear an even number of times.
2.  If the string's length `N` is odd, exactly one character can appear an odd number of times, and all other characters must appear an even number of times.

Combining these, a string can form a palindrome if and only if at most one character has an odd frequency count.

### Analysis of the Provided Solution

The provided solution, however, implements a simpler check: it counts the frequency of each character in `S` and then checks if *any* character appears two or more times.
- If at least one character appears two or more times, it outputs "Yes".
- If no character appears two or more times (meaning all characters appear at most once, i.e., all characters are unique), it outputs "No".

Let's analyze this logic against the standard palindrome anagram condition:

1.  **Case: All characters in `S` are unique.**
    *   Example: `S = "abc"`, `N=3`. Frequencies: 'a':1, 'b':1, 'c':1.
    *   Provided code: No character count is `>= 2`, so `possible` remains `false`. Output: "No".
    *   Standard condition: Three characters have odd frequencies (1, 1, 1). Since `3 > 1`, it's not possible to form a palindrome.
    *   Result: Matches.

    *   Example: `S = "a"`, `N=1`. Frequencies: 'a':1.
    *   Provided code: No character count is `>= 2`, so `possible` remains `false`. Output: "No".
    *   Standard condition: One character has an odd frequency (1). Since `1 <= 1`, it *is* possible to form a palindrome ("a" itself is a palindrome).
    *   Result: **Does not match.** The provided code is incorrect for `N=1` if `S` contains a single unique character.

2.  **Case: At least one character in `S` appears two or more times.**
    *   Example: `S = "aba"`, `N=3`. Frequencies: 'a':2, 'b':1.
    *   Provided code: 'a' appears twice, so `possible` becomes `true`. Output: "Yes".
    *   Standard condition: One character ('b') has an odd frequency. Since `1 <= 1`, it's possible to form a palindrome.
    *   Result: Matches.

    *   Example: `S = "aabbcde"`, `N=7`. Frequencies: 'a':2, 'b':2, 'c':1, 'd':1, 'e':1.
    *   Provided code: 'a' appears twice (or 'b'), so `possible` becomes `true`. Output: "Yes".
    *   Standard condition: Three characters ('c', 'd', 'e') have odd frequencies. Since `3 > 1`, it's *not* possible to form a palindrome.
    *   Result: **Does not match.** The provided code is incorrect for `N > 1` if there are multiple distinct characters with odd counts, even if some characters appear twice.

### Conclusion on the Solution's Logic

The provided solution code does not correctly implement the standard condition for forming a palindrome from an anagram. Instead, it checks a much simpler condition: "Does the input string `S` contain at least one duplicate character?"

Given that this solution passed on CodeChef (as indicated by "Solved in: 1 attempt(s)"), it implies that the test cases for this problem were weak and did not cover scenarios where this simplified logic fails (e.g., `N=1` with a unique character, or `N > 1` with multiple unique characters but also some duplicates). It's possible the problem setter intended this simpler check, or the problem statement was misleading.

For this writeup, we will describe the code's actual logic, acknowledging its discrepancy with the formal definition of the problem.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` and `S`: $O(N)$
    -   Populating the `counts` array: The loop iterates `N` times, and each character operation (`c - 'a'`, `++`) takes $O(1)$ time. This is $O(N)$.
    -   Checking the `counts` array: The loop iterates 26 times (for 'a' through 'z'), which is a constant number of operations. This is $O(1)$.
    -   Overall, for each test case, the dominant factor is iterating through the string `S`, making the time complexity $O(N)$.
    -   For `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    -   Storing the input string `S`: $O(N)$.
    -   Storing character frequencies in the `counts` vector: This vector has a fixed size of 26 (for lowercase English letters), which is $O(1)$ space, independent of `N`.
    -   Overall, the space complexity is dominated by storing the input string, resulting in $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string S

    // Create a vector to store character frequencies.
    // There are 26 lowercase English letters ('a' through 'z').
    // counts[0] will store frequency of 'a', counts[1] for 'b', and so on.
    vector<int> counts(26, 0); 

    // Iterate through each character in the string S
    for (char c : S) {
        // Increment the count for the corresponding character.
        // 'c - 'a'' converts a character like 'a' to 0, 'b' to 1, etc.
        counts[c - 'a']++; 
    }

    bool possible = false; // Flag to track if a suitable character is found

    // Iterate through the frequency counts
    for (int count : counts) {
        // If any character appears 2 or more times, it's possible
        // (According to the logic implemented in this solution)
        if (count >= 2) {
            possible = true; // Set flag to true
            break;           // No need to check further, we found one
        }
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```