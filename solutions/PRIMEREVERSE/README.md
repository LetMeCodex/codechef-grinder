# [Prime Reversal (PRIMEREVERSE)](https://www.codechef.com/problems/PRIMEREVERSE)
- **Difficulty Rating**: 1053
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a binary string `A` can be transformed into another binary string `B` of the same length `N` using a specific operation. The allowed operation is to reverse any substring of length `X`, where `X` is a prime number. We need to output "YES" if `A` can be transformed into `B`, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the power of the given operation: "reverse any substring of length `X`, where `X` is a prime number."

1.  **Invariance of Character Counts**: When we reverse a substring, we are merely rearranging the characters *within* that substring. This operation does not change the total number of '0's or '1's in the entire string. Therefore, a necessary condition for string `A` to be transformable into string `B` is that they must have the same count of '0's and the same count of '1's. If their character counts differ, it's impossible to transform one into the other.

2.  **Sufficiency of the Operation**: Now, let's consider if this necessary condition is also sufficient. If `A` and `B` have the same counts of '0's and '1's, can we always transform `A` into `B`?
    *   The crucial part is that `X` can be *any* prime number. The smallest prime number is 2.
    *   If we can reverse a substring of length 2, it means we can swap any two *adjacent* characters. For example, reversing the substring `A[i]A[i+1]` effectively swaps `A[i]` and `A[i+1]`.
    *   The ability to swap any two adjacent characters is a fundamental operation in permutation theory. It is known that any permutation of a sequence can be achieved through a series of adjacent swaps (e.g., this is the principle behind Bubble Sort).
    *   Since we can achieve any permutation of the characters in string `A` (by repeatedly applying adjacent swaps), if string `A` and string `B` have the same multiset of characters (i.e., same counts of '0's and '1's), we can always rearrange `A` to match `B`.

**Conclusion**: The problem simplifies to checking if string `A` and string `B` have the same number of '1's. If they do, then they must also have the same number of '0's (since their lengths `N` are equal), and thus `A` can be transformed into `B`. Otherwise, it cannot.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   Reading the input strings `A` and `B` takes $O(N)$ time.
    *   Counting the '1's in string `A` involves iterating through its `N` characters, taking $O(N)$ time.
    *   Similarly, counting the '1's in string `B` takes $O(N)$ time.
    *   The comparison and printing take $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**: $O(N)$ per test case.
    *   Storing the input strings `A` and `B` requires $O(N)$ space.
    *   The integer variables for counts and `N` require $O(1)$ space.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <numeric>  // Not strictly needed if using a manual loop, but useful for std::count

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the strings
    std::string a, b;
    std::cin >> a >> b; // Read the binary strings A and B

    // Count the number of '1's in string A
    int countA_ones = 0;
    for (char c : a) {
        if (c == '1') {
            countA_ones++;
        }
    }

    // Count the number of '1's in string B
    int countB_ones = 0;
    for (char c : b) {
        if (c == '1') {
            countB_ones++;
        }
    }

    // The core logic:
    // We can reverse any substring of length X, where X is a prime number.
    // Since 2 is a prime number, we can choose X=2.
    // Reversing a substring of length 2 (e.g., A[i]A[i+1]) effectively swaps
    // the two adjacent characters (A[i+1]A[i]).
    // The ability to swap any two adjacent characters means we can achieve any
    // permutation of the string's characters. This is a fundamental property
    // of permutations (e.g., bubble sort uses adjacent swaps to sort).
    //
    // Therefore, if string A can be transformed into string B, they must have
    // the same multiset of characters. Since these are binary strings, this
    // simply means they must have the same count of '0's and the same count of '1's.
    // If the count of '1's in A is equal to the count of '1's in B, then
    // the count of '0's must also be equal (since total length N is the same).
    // In this scenario, we can always rearrange the characters of A to match B.
    // If the counts of '1's differ, it's impossible to make them equal, as
    // reversing a substring does not change the counts of characters within it,
    // and thus does not change the total counts in the string.
    if (countA_ones == countB_ones) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```