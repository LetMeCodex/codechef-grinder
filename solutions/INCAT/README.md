# [Make Cat (INCAT)](https://www.codechef.com/problems/INCAT)
- **Difficulty Rating**: 210
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given string $S$ of length 3 can be rearranged to form the word "cat".

## Intuition & Mathematical Observation
The core of this problem lies in understanding what it means for a string to be a rearrangement of another. Two strings are rearrangements of each other if they contain the same characters with the same frequencies.

Since the input string $S$ is guaranteed to have a length of 3, and we want to form the word "cat" (which also has a length of 3), we need to check if the string $S$ contains exactly one 'c', one 'a', and one 't'. The order of these characters in the input string $S$ does not matter.

A straightforward way to check if two strings are anagrams (rearrangements of each other) is to sort both strings alphabetically. If the sorted versions of the strings are identical, then the original strings are anagrams.

In this specific case, the target word is "cat". If we sort the characters of "cat" alphabetically, we get "act". Therefore, if the input string $S$, when sorted alphabetically, becomes "act", it means $S$ contains exactly the characters 'a', 'c', and 't', and thus can be rearranged to form "cat".

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The input string $S$ has a fixed length of 3. Sorting a string of length 3 takes a constant amount of time, regardless of the characters. The comparison `s == "act"` also takes constant time for strings of fixed length. Therefore, the overall time complexity is constant.

- **Space Complexity**: $O(1)$
  We are using a single string variable `s` to store the input, which has a fixed size. The sorting operation might use a small amount of auxiliary space depending on the implementation, but for a fixed small size like 3, it's effectively constant. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a string variable to store the input.
    // The problem states the string S will always be of length 3.
    string s;
    
    // Read the input string S.
    cin >> s;

    // To check if the letters of string S can be rearranged to form "cat",
    // we can sort the letters of S and compare it with the sorted version of "cat".
    // The letters 'c', 'a', 't' when sorted alphabetically become 'a', 'c', 't'.
    
    // Sort the characters of the string S in ascending order.
    // For a string of length 3, this operation is constant time.
    sort(s.begin(), s.end());

    // After sorting, if the string S contains exactly the letters 'a', 'c', 't'
    // (one of each), then it will be equal to the string "act".
    if (s == "act") {
        // If they are equal, it means "cat" can be formed.
        cout << "Yes\n";
    } else {
        // Otherwise, "cat" cannot be formed.
        cout << "No\n";
    }

    return 0; // Indicate successful execution.
}
```