# Reach Codetown (CODETOWN)
- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given 8-character string `S` can be transformed into the string "CODETOWN" by only changing characters that are vowels to other vowels, and consonants to other consonants. We are given `T` test cases, each with a string `S`.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the transformation rule. We can change a vowel to any other vowel, and a consonant to any other consonant. This means that the *type* of character (vowel or consonant) at each position must be preserved.

Let's consider the target string "CODETOWN". We can analyze the type of each character:
- C: Consonant
- O: Vowel
- D: Consonant
- E: Vowel
- T: Consonant
- O: Vowel
- W: Consonant
- N: Consonant

For a given input string `S` of length 8, to be transformable into "CODETOWN", the character at each position `i` (0-indexed) in `S` must satisfy the following condition:
- If `target[i]` is a vowel, then `S[i]` must also be a vowel.
- If `target[i]` is a consonant, then `S[i]` must also be a consonant.

In other words, for every position `i` from 0 to 7, the character `S[i]` and the character `target[i]` must belong to the same category: both vowels or both consonants. If this condition holds for all 8 positions, then `S` can be transformed into "CODETOWN". If even for a single position this condition is violated, then it's impossible.

The provided solution implements this logic directly. It iterates through the 8 characters of the input string `S` and compares them with the characters of "CODETOWN". For each position, it checks if the character type (vowel/consonant) matches. If a mismatch in type is found, it flags the string as impossible.

The `is_vowel` helper function efficiently checks if a character is an uppercase vowel.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The input string `S` is always of length 8. The code iterates through this string exactly once. The operations inside the loop (character comparison, `is_vowel` function call) take constant time. Therefore, for each test case, the time complexity is constant. Since there are `T` test cases, the total time complexity is $O(T)$. However, if we consider the problem statement's constraint on the input string length being fixed at 8, the complexity per test case is $O(8)$, which simplifies to $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a few variables to store the input string, the target string, and a boolean flag. The space used does not depend on the input size (beyond the fixed-size string). Therefore, the space complexity is constant, $O(1)$.