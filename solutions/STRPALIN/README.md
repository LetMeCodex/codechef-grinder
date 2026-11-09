# [Palindromic substrings (STRPALIN)](https://www.codechef.com/problems/STRPALIN)
- **Difficulty Rating**: 1238
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to choose a non-empty substring `s1` from a given string `A` and a non-empty substring `s2` from another given string `B` such that their concatenation `s1 + s2` forms a palindrome. Both strings `A` and `B` consist of lowercase English alphabets.

## Intuition & Mathematical Observation

Let's consider the properties of a palindrome. A string `S` is a palindrome if it reads the same forwards and backwards. This means `S[i]` must be equal to `S[length(S) - 1 - i]` for all valid indices `i`.

We are looking for `s1` (a non-empty substring of `A`) and `s2` (a non-empty substring of `B`) such that `s1 + s2` is a palindrome.
Let `P = s1 + s2`. For `P` to be a palindrome, at the very least, its first character must be equal to its last character.
The first character of `P` is `s1[0]`.
The last character of `P` is `s2[length(s2) - 1]`.
So, a necessary condition for `P` to be a palindrome is `s1[0] == s2[length(s2) - 1]`.

Now, let's explore this condition:
1.  `s1[0]` is a character that appears in string `A`.
2.  `s2[length(s2) - 1]` is a character that appears in string `B`.

If there exists *any* character `x` that is present in string `A` AND also present in string `B`, can we construct `s1` and `s2` such that `s1 + s2` is a palindrome?
Yes! We can simply choose:
*   `s1 = "x"` (a substring of `A` of length 1, since `x` is in `A`)
*   `s2 = "x"` (a substring of `B` of length 1, since `x` is in `B`)

Then, the concatenation `s1 + s2` becomes `"xx"`. This string `"xx"` is always a palindrome (e.g., "aa", "bb", "cc"). Since `s1` and `s2` are both non-empty, this construction satisfies all conditions.
Therefore, if there is at least one common character between `A` and `B`, the answer is "Yes".

What if there are NO common characters between `A` and `B`?
This means that any character present in `A` is *not* present in `B`, and vice-versa.
In this scenario, consider any non-empty substring `s1` from `A` and any non-empty substring `s2` from `B`.
*   `s1[0]` will be a character from `A`.
*   `s2[length(s2) - 1]` will be a character from `B`.
Since there are no common characters, `s1[0]` can never be equal to `s2[length(s2) - 1]`.
As `s1[0] == s2[length(s2) - 1]` is a necessary condition for `s1 + s2` to be a palindrome, if this condition cannot be met, then `s1 + s2` can never be a palindrome.
Therefore, if no common character exists between `A` and `B`, the answer is "No".

**Conclusion:** The problem simplifies to checking if there is at least one common character between string `A` and string `B`.

The algorithm will be:
1.  Create a frequency map or a boolean array to keep track of characters present in string `A`.
2.  Iterate through string `B`. For each character in `B`, check if it's present in `A` (using the map/array).
3.  If a common character is found, print "Yes" and terminate for the current test case.
4.  If the loop finishes without finding any common character, print "No".

## Complexity Analysis

Let $|A|$ be the length of string `A` and $|B|$ be the length of string `B`.

-   **Time Complexity**:
    1.  Reading strings `A` and `B`: $O(|A| + |B|)$.
    2.  Populating the `present_in_A` boolean array: We iterate through each character of string `A` once. This takes $O(|A|)$ time.
    3.  Checking for common characters: We iterate through each character of string `B` once. In the worst case, we might iterate through all characters of `B` before finding a common character or concluding none exist. This takes $O(|B|)$ time.
    The total time complexity per test case is $O(|A| + |B|)$.
    Given that $|A|, |B| \le 10^5$, this is efficient enough. For $T$ test cases, the total time complexity is $O(T \cdot (|A| + |B|))$.

-   **Space Complexity**:
    1.  Storing strings `A` and `B`: $O(|A| + |B|)$ space.
    2.  `present_in_A` boolean array: This array has a fixed size of 26 (for lowercase English alphabets), regardless of the input string lengths. This is considered $O(1)$ constant space.
    The total space complexity is $O(|A| + |B|)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Using namespace std; as requested by the prompt.
using namespace std;

void solve() {
    string A, B;
    cin >> A >> B;

    // A boolean array to keep track of characters present in string A.
    // Since characters are lowercase English alphabets, an array of size 26 is sufficient.
    // present_in_A[0] corresponds to 'a', present_in_A[1] to 'b', and so on.
    vector<bool> present_in_A(26, false);

    // Populate present_in_A based on characters in string A.
    for (char c : A) {
        present_in_A[c - 'a'] = true;
    }

    bool found_common_char = false;
    // Iterate through string B to check for common characters.
    for (char c : B) {
        // If the current character from B is also present in A,
        // then we have found a common character.
        if (present_in_A[c - 'a']) {
            found_common_char = true;
            break; // No need to check further, one common character is enough.
        }
    }

    // If a common character 'x' was found:
    // We can choose s1 = "x" (a substring of A) and s2 = "x" (a substring of B).
    // The concatenation s1 + s2 = "xx" is a palindrome.
    // So, the answer is "Yes".
    //
    // If no common character was found:
    // Let s1 be any non-empty substring of A, and s2 be any non-empty substring of B.
    // For s1 + s2 to be a palindrome, its first character (s1[0]) must be equal to its last character (s2[length(s2)-1]).
    // s1[0] is a character from A. s2[length(s2)-1] is a character from B.
    // If there are no common characters between A and B, then no character from A can be equal to any character from B.
    // Therefore, s1[0] cannot be equal to s2[length(s2)-1].
    // This means s1 + s2 cannot be a palindrome.
    // So, the answer is "No".
    if (found_common_char) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```