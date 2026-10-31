# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)
- **Difficulty Rating**: 1216
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct two *distinct* binary palindromes, each containing exactly `A` zeros and `B` ones. We are given the counts `A` and `B` for each test case.

## Intuition & Mathematical Observation

A binary string is a palindrome if it reads the same forwards and backwards. This implies that characters at symmetric positions must be identical.

Let the total length of the palindrome be `L = A + B`.

**Case 1: Total Length `L` is Even (`A + B` is even)**
If the total length is even, every character `S[i]` must have a distinct symmetric partner `S[L - 1 - i]`. This means that the count of each character ('0' and '1') must be even.
- If `A` is odd AND `B` is odd: `A + B` will be even. However, since both `A` and `B` are odd, it's impossible to form *any* palindrome, as their counts are not even. Thus, in this scenario, the answer is "No".
- If `A` is even AND `B` is even: `A + B` will be even. This is a valid scenario for forming palindromes. A palindrome can be constructed by forming a prefix `P` of length `(A+B)/2` (containing `A/2` zeros and `B/2` ones) and then appending its reverse (`P + reverse(P)`). To form two *different* palindromes, we need to be able to construct at least two different valid prefixes. This is generally possible if `A/2 >= 1` and `B/2 >= 1` (i.e., `A >= 2` and `B >= 2`), allowing us to start the prefix with either '0' or '1'.

**Case 2: Total Length `L` is Odd (`A + B` is odd)**
If the total length is odd, there will be a single middle character that does not have a symmetric partner. For a palindrome to be formed, the character with the odd count must be this middle character. The remaining characters (total `L-1`) form a prefix `P` and its reverse `reverse(P)`, each of length `(L-1)/2`.
- If `A` is odd and `B` is even: '0' must be the middle character. The prefix `P` needs `(A-1)/2` zeros and `B/2` ones.
- If `B` is odd and `A` is even: '1' must be the middle character. The prefix `P` needs `A/2` zeros and `(B-1)/2` ones.

To determine if two *different* palindromes can be formed, we analyze the conditions under which only one (or zero) palindromes are possible:

**Conditions for "No" (cannot construct two different palindromes):**

1.  **Both `A` and `B` are odd:**
    - `A+B` is even.
    - For an even length palindrome, counts of both '0's and '1's must be even.
    - Since `A` and `B` are both odd, it's impossible to form *any* palindrome.
    - Example: `A=1, B=1`. Length 2. Palindromes "01" and "10" are not allowed as they are not palindromes. No palindrome can be formed.

2.  **`A = 1` and `B` is even:**
    - `A+B` is odd. Since `A` is odd, '0' must be the middle character.
    - The prefix `P` needs `(A-1)/2 = (1-1)/2 = 0` zeros and `B/2` ones.
    - This means `P` must consist solely of `B/2` ones (e.g., "11...1"). There is only one way to form such a prefix.
    - Thus, only one palindrome can be formed.
    - Example: `A=1, B=2`. Length 3. Middle '0'. Prefix needs 0 zeros, 1 one. Prefix is "1". Palindrome: "101". Only one.

3.  **`B = 1` and `A` is even:**
    - `A+B` is odd. Since `B` is odd, '1' must be the middle character.
    - The prefix `P` needs `A/2` zeros and `(B-1)/2 = (1-1)/2 = 0` ones.
    - This means `P` must consist solely of `A/2` zeros (e.g., "00...0"). There is only one way to form such a prefix.
    - Thus, only one palindrome can be formed.
    - Example: `A=2, B=1`. Length 3. Middle '1'. Prefix needs 1 zero, 0 ones. Prefix is "0". Palindrome: "010". Only one.

**Conditions for "Yes" (can construct two different palindromes):**

If none of the above "No" conditions are met, it means we have enough '0's and '1's (after accounting for the middle character if `A+B` is odd) to construct at least two distinct prefixes. This typically occurs when both `A` and `B` are sufficiently large (e.g., `A >= 2` and `B >= 2` for the prefix part).

Let's verify the remaining cases:
-   **`A` and `B` are both even (and `A, B >= 2`):**
    -   `A+B` is even. Prefix needs `A/2` zeros and `B/2` ones.
    -   Since `A, B >= 2`, `A/2 >= 1` and `B/2 >= 1`. We can form a prefix starting with '0' (e.g., `0` followed by `A/2-1` zeros and `B/2` ones) and another starting with '1' (e.g., `1` followed by `A/2` zeros and `B/2-1` ones). These will lead to two distinct palindromes.
    -   Example: `A=2, B=2`. Prefixes: "01", "10". Palindromes: "0110", "1001". (Yes)
-   **`A` is even (`A >= 2`), `B` is odd (`B >= 3`):**
    -   `A+B` is odd. Middle is '1'. Prefix needs `A/2` zeros and `(B-1)/2` ones.
    -   Since `A >= 2`, `A/2 >= 1`. Since `B >= 3`, `(B-1)/2 >= 1`.
    -   Similar to the above, we can form two distinct prefixes.
    -   Example: `A=2, B=3`. Middle '1'. Prefixes: "01", "10". Palindromes: "01110", "10101". (Yes)
-   **`A` is odd (`A >= 3`), `B` is even (`B >= 2`):**
    -   `A+B` is odd. Middle is '0'. Prefix needs `(A-1)/2` zeros and `B/2` ones.
    -   Since `A >= 3`, `(A-1)/2 >= 1`. Since `B >= 2`, `B/2 >= 1`.
    -   Similar to the above, we can form two distinct prefixes.
    -   Example: `A=3, B=2`. Middle '0'. Prefixes: "01", "10". Palindromes: "01010", "10001". (Yes)

**Edge Case: `A=0` or `B=0`**
If `A=0` or `B=0` (and `A+B > 0`), it means only one type of character is available. For example, if `A=0, B=3`, the only palindrome is "111". If `A=2, B=0`, the only palindrome is "00". In such cases, only one palindrome can be formed, so the answer should be "No".
The provided solution code does *not* explicitly check for `A=0` or `B=0`. If `A=0` and `B=2`, the code would evaluate `both_odd`, `a_is_one_b_is_even`, `b_is_one_a_is_even` as false, and output "Yes". This would be incorrect, as "11" is the only palindrome. It's possible the test cases for this problem did not cover `A=0` or `B=0` where `A+B > 0`, or implicitly assumed `A, B >= 1` for the core logic. For a fully robust solution, an additional check `if (a == 0 || b == 0)` should be added to the "No" conditions. However, since the task is to explain the *provided* solution, we note this observation.

The provided solution correctly identifies the specific scenarios where it's impossible to form two distinct palindromes based on parity and counts of 1. All other cases are assumed to allow for two distinct palindromes.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution processes each of the `T` test cases independently. For each test case, it performs a constant number of arithmetic operations (modulo, comparison, logical operations) and input/output operations. Therefore, the total time complexity is directly proportional to the number of test cases.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`t`, `a`, `b`, and a few boolean flags) to store input and intermediate results. The memory usage does not scale with the input values `A` or `B`. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        long long a, b; // Use long long for A and B, as per problem constraints (up to 10^6, int is fine, but long long is safer and harmless).
        std::cin >> a >> b; // Read A and B for the current test case.

        // Condition 1: Both A and B are odd.
        // In this case, A+B is even. For an even length palindrome, both character counts must be even.
        // Since A and B are both odd, it's impossible to form any palindrome.
        bool both_odd = (a % 2 != 0) && (b % 2 != 0);

        // Condition 2: A is 1 and B is even.
        // The total length A+B is odd. The middle character must be '0' (since A is odd).
        // The prefix P needs (A-1)/2 zeros and B/2 ones.
        // If A=1, then (A-1)/2 = 0. So P needs 0 zeros and B/2 ones.
        // This means P must be '1' repeated B/2 times. Only one such P exists.
        // Thus, only one palindrome can be formed.
        bool a_is_one_b_is_even = (a == 1) && (b % 2 == 0);

        // Condition 3: B is 1 and A is even.
        // Similar to Condition 2, but roles of A and B are swapped.
        // The total length A+B is odd. The middle character must be '1' (since B is odd).
        // The prefix P needs A/2 zeros and (B-1)/2 ones.
        // If B=1, then (B-1)/2 = 0. So P needs A/2 zeros and 0 ones.
        // This means P must be '0' repeated A/2 times. Only one such P exists.
        // Thus, only one palindrome can be formed.
        bool b_is_one_a_is_even = (b == 1) && (a % 2 == 0);

        // If any of these conditions are true, we cannot construct two different palindromes.
        if (both_odd || a_is_one_b_is_even || b_is_one_a_is_even) {
            std::cout << "No\n";
        } else {
            // In all other cases, it's possible to construct two different palindromes.
            // This includes:
            // - A and B are both even (A, B >= 2).
            // - A is even (A >= 2), B is odd (B >= 3).
            // - A is odd (A >= 3), B is even (B >= 2).
            std::cout << "Yes\n";
        }
    }
    return 0;
}
```