# [Echo (ECHOECHO)](https://www.codechef.com/problems/ECHOECHO)
- **Difficulty Rating**: 231
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given string `s` is an "echo" string. An echo string is defined as a string of length 4 where the first two characters are repeated to form the entire string. Specifically, if the string is `S1S2S3S4`, it's an echo string if `S1 = S3` and `S2 = S4`.

## Intuition & Mathematical Observation
The definition of an echo string is quite direct. We are given a string `s` and need to check if it adheres to the pattern `ABAB`, where `A` and `B` are characters.

For a string `s` of length 4, let its characters be indexed from 0 to 3: `s[0]`, `s[1]`, `s[2]`, `s[3]`.
According to the problem statement, for `s` to be an echo string:
1. The length of `s` must be exactly 4.
2. The first character must be equal to the third character: `s[0] == s[2]`.
3. The second character must be equal to the fourth character: `s[1] == s[3]`.

If all these conditions are met, the string is an echo string, and we should output "Yes". Otherwise, we should output "No".

The provided solution directly implements these checks. It first verifies if the string's length is 4. If it is, it then proceeds to compare `s[0]` with `s[2]` and `s[1]` with `s[3]`.

The problem statement implies a single test case based on the sample input and the absence of a loop for multiple test cases in the problem description. The solution code reflects this assumption. If multiple test cases were intended, a loop structure like `int t; cin >> t; while(t--)` would typically be present.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of operations: reading a string, checking its length, and performing a few character comparisons. These operations take constant time, regardless of the input string's length (which is fixed at 4 for a valid echo string).

- **Space Complexity**: $O(L)$ where $L$ is the length of the input string.
The primary space usage is for storing the input string `s`. Since the problem constraints likely limit the string length, and we are only storing this one string, the space complexity is effectively constant for practical purposes related to the problem's core logic. If we consider the maximum possible length of a string that could be read, it would be $O(L)$. However, the *relevant* part of the logic only operates on a string of length 4.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies a single test case, but the template
    // suggests handling multiple test cases. Based on typical CodeChef
    // problem structures and the absence of a 't' in the sample input,
    // we'll assume a single test case for this specific problem.
    // If multiple test cases were intended, a loop like `int t; cin >> t; while(t--)`
    // would be used.

    string s;
    cin >> s;

    // An echo string of length 4 has S1 = S3 and S2 = S4.
    // In 0-based indexing, this translates to s[0] == s[2] and s[1] == s[3].
    if (s.length() == 4 && s[0] == s[2] && s[1] == s[3]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
```