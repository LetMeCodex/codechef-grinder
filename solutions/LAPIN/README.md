# [Lapindromes (LAPIN)](https://www.codechef.com/problems/LAPIN)

- **Difficulty Rating**: 1159
- **Solved in**: 1 attempt(s)

## Problem Summary
A "Lapindrome" is defined as a string which when split into two halves, the two halves contain the same characters with the same frequencies. If the length of the string is odd, the middle character is ignored. Given a string $S$, determine if it is a Lapindrome.

## Intuition & Mathematical Observation
To determine if a string is a Lapindrome, we need to compare the character counts of the first half and the second half:

1.  **Splitting the String**: 
    *   For a string of length $N$, the first half always spans indices $[0, \frac{N}{2} - 1]$.
    *   If $N$ is even, the second half spans $[\frac{N}{2}, N - 1]$.
    *   If $N$ is odd, the middle character is at index $\frac{N}{2}$. We skip this index and the second half spans $[\frac{N}{2} + 1, N - 1]$.
2.  **Frequency Counting**: Since the problem only involves lowercase English letters, we can use two frequency arrays (or hash maps) of size 26 to store the count of each character ('a' through 'z') for both halves.
3.  **Comparison**: After populating the frequency arrays, we compare them index by index. If all 26 counts match, the string is a Lapindrome.

## Complexity Analysis
- **Time Complexity**: $O(T \times |S|)$, where $T$ is the number of test cases and $|S|$ is the length of the string. We iterate through the string once to count frequencies and then perform a constant-time comparison (26 iterations).
- **Space Complexity**: $O(1)$, because the frequency arrays are of fixed size (26), regardless of the input string length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Lapindromes
 * Approach:
 * 1. Calculate the length of the string.
 * 2. Identify the two halves. If the length is odd, skip the middle character.
 * 3. Use frequency arrays (size 26 for lowercase English letters) to count 
 *    the occurrences of each character in both halves.
 * 4. Compare the two frequency arrays. If they are identical, it's a lapindrome.
 * 
 * Time Complexity: O(T * |S|), where |S| is the length of the string.
 * Space Complexity: O(1) as the frequency array size is constant (26).
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    
    // First half
    for (int i = 0; i < n / 2; ++i) {
        freq1[s[i] - 'a']++;
    }
    
    // Second half
    // If n is odd, start from n/2 + 1, else start from n/2
    int start = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
    for (int i = start; i < n; ++i) {
        freq2[s[i] - 'a']++;
    }
    
    bool isLapindrome = true;
    for (int i = 0; i < 26; ++i) {
        if (freq1[i] != freq2[i]) {
            isLapindrome = false;
            break;
        }
    }
    
    if (isLapindrome) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```