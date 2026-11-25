# Distinct Characters Subsequence (DISCHAR)
- **Difficulty Rating**: 1314
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the number of distinct characters present in a given string. We are given a string $S$ and need to output the count of unique characters it contains.

## Intuition & Mathematical Observation

The core of this problem is to identify and count unique elements within a sequence. For a string, the elements are its characters. The problem statement is straightforward: "count the number of distinct characters".

A common and efficient way to count distinct elements in a collection is to use a data structure that inherently stores only unique items. A `set` in C++ is an excellent choice for this purpose. When you insert elements into a `set`, it automatically handles duplicates, ensuring that each element is stored only once.

Therefore, the intuition is to iterate through the input string, inserting each character into a `set`. After processing the entire string, the size of the `set` will directly give us the count of distinct characters.

Mathematically, if we consider the set of all characters in the string $S$, denoted as $C(S) = \{c \mid c \text{ is a character in } S\}$, the problem asks for the cardinality of this set, i.e., $|C(S)|$.

## Complexity Analysis

- **Time Complexity**: $O(N \log K)$ or $O(N)$
    - We iterate through the input string of length $N$ once.
    - For each character, we perform an insertion into a `std::set`.
    - In the worst case, the `std::set` can store up to $K$ distinct characters, where $K$ is the size of the alphabet (e.g., 26 for lowercase English letters, or 256 for ASCII).
    - The insertion operation in a `std::set` (which is typically implemented as a balanced binary search tree) takes $O(\log K)$ time.
    - Thus, the total time complexity is $O(N \log K)$.
    - However, if we consider the alphabet size $K$ to be a constant (e.g., 26 for lowercase English letters), then $\log K$ is also a constant, and the time complexity effectively becomes $O(N)$.
    - An alternative approach using a boolean array or `std::unordered_set` could achieve $O(N)$ time complexity. For this specific problem with a small, fixed alphabet, `std::set` is perfectly acceptable and often simpler to implement.

- **Space Complexity**: $O(K)$
    - We use a `std::set` to store the distinct characters.
    - In the worst case, the `std::set` will store all unique characters present in the string.
    - The maximum number of distinct characters is limited by the size of the character set (alphabet). Let $K$ be the size of the alphabet.
    - Therefore, the space complexity is $O(K)$. If $K$ is considered a constant (e.g., 26 for lowercase English letters), the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <set>
#include <vector> // Although not strictly needed for this solution, it's often included by habit.

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Disables synchronization with C's stdio and unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        std::string s; // The input string
        std::cin >> s;

        // A set automatically stores only unique elements.
        // Inserting characters from the string into this set will
        // result in a set containing only the distinct characters.
        std::set<char> distinct_chars;
        for (char c : s) {
            distinct_chars.insert(c);
        }

        // The size of the set is the count of distinct characters.
        std::cout << distinct_chars.size() << "\n";
    }
    return 0;
}
```