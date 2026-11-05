# [Double Strings (DOUBLE)](https://www.codechef.com/problems/DOUBLE)
- **Difficulty Rating**: 1134
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximal possible length of a "double string" that can be formed by taking characters from a given palindrome of length `N`. We are allowed to remove characters and change their order.

A "double string" is defined as a string `S` such that `S = XX` for some string `X`. For example, "ababa" is not a double string, but "ababab" is (where `X = "aba"`).

## Intuition & Mathematical Observation

Let's break down the properties of "double strings" and palindromes to find the optimal solution.

1.  **Properties of a "Double String"**:
    A string `S` is a "double string" if `S = XX`. This implies two crucial properties:
    *   The length of `S` must be even. If `S` has length `L`, then `X` has length `L/2`.
    *   Every character in `S` must appear an even number of times. If a character `c` appears `k` times in `X`, then it appears `2k` times in `S`. Since `2k` is always an even number, all character counts in a double string must be even.

2.  **Properties of a Palindrome of length `N`**:
    We are given a palindrome of length `N`. We can remove characters and reorder the remaining ones. The key is that we can reorder characters, so we only care about the *counts* of each character.
    *   **If `N` is even**: In a palindrome of even length (e.g., "ABBA", "RACEECAR"), every character appears an even number of times. For example, in "ABBA", 'A' appears 2 times, 'B' appears 2 times.
    *   **If `N` is odd**: In a palindrome of odd length (e.g., "RACECAR", "MADAM"), exactly one character appears an odd number of times, and all other characters appear an even number of times. For example, in "RACECAR", 'R' appears 2 times, 'A' appears 2 times, 'C' appears 2 times, and 'E' appears 1 time.

3.  **Combining for the Maximal Length**:
    Our goal is to form a "double string" using characters from the given palindrome, maximizing its length. This means we need to select a subset of characters such that:
    *   The total count of selected characters is even.
    *   Every selected character appears an even number of times.

    Let's consider the two cases for `N`:

    *   **Case 1: `N` is even.**
        If the original palindrome has an even length `N`, all its characters already appear an even number of times. Since we can reorder characters, we can use *all* `N` characters. The total length `N` is even, and all character counts are even. Thus, we can form a double string of length `N`. This is the maximal possible length because we are using all available characters.

    *   **Case 2: `N` is odd.**
        If the original palindrome has an odd length `N`, exactly one character appears an odd number of times. To form a double string, *all* character counts must be even. To achieve this, we must discard at least one character. The most efficient way to make all counts even is to discard *one* instance of the character that appears an odd number of times. After discarding this single character, all remaining characters will have even counts. The total number of remaining characters will be `N - 1`. Since `N` was odd, `N - 1` will be even. Now, we have an even number of characters, and all individual character counts are even. Therefore, we can form a double string of length `N - 1`. This is the maximal length because we only discarded the minimum necessary (1 character).

**Conclusion**:
The maximal length of the double string is `N` if `N` is even, and `N - 1` if `N` is odd. This can be concisely expressed as `N - (N % 2)`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading `N`, checking `N % 2`, and printing the result. If there are `T` test cases, the total time complexity is proportional to `T`.

*   **Space Complexity**: $O(1)$
    We only use a few integer variables (`T`, `N`) to store input and perform calculations. The memory usage does not depend on the input size `N`.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N to store the length of the palindrome.
        std::cin >> N; // Read the length N for the current test case.

        // The problem asks for the maximal possible number of characters in a "double string"
        // that can be obtained by removing and changing the order of symbols from a palindrome of length N.
        //
        // A "double string" must have an even length and its first half must be equal to its second half (e.g., "XX").
        // This implies that every character in a double string must appear an even number of times.
        //
        // We are given a palindrome of length N. The character counts in a palindrome have specific properties:
        // 1. If N is even: All characters in the palindrome appear an even number of times.
        //    Example: "abba" (N=4) has 'a':2, 'b':2.
        //    In this case, since all character counts are already even, we can use all N characters
        //    to form a double string. We can split the counts in half to form 'X' and then 'XX'.
        //    The maximal length is N.
        //
        // 2. If N is odd: Exactly one character in the palindrome appears an odd number of times.
        //    All other characters appear an even number of times.
        //    Example: "racecar" (N=7) has 'r':2, 'a':2, 'c':2, 'e':1.
        //    To form a double string, all characters must appear an even number of times.
        //    We must discard one occurrence of the character that appears an odd number of times.
        //    After discarding this one character, all remaining characters will have even counts,
        //    and the total length will be N-1. Since N is odd, N-1 is even, satisfying the
        //    length requirement for a double string. This is the maximal length possible
        //    because we only discard the minimum necessary (1 character).
        //
        // Therefore, the answer is N if N is even, and N-1 if N is odd.
        // This can be concisely written as N - (N % 2).

        if (N % 2 == 0) { // Check if N is even
            std::cout << N << "\n"; // If N is even, print N
        } else { // If N is odd
            std::cout << N - 1 << "\n"; // If N is odd, print N-1
        }
    }

    return 0; // Indicate successful execution.
}
```