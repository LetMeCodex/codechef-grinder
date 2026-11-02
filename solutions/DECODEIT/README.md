# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to decode an encoded binary string. We are given an integer `N`, which is the length of the encoded string `S`. The encoding scheme is as follows:
1. The encoded string `S` consists of binary digits ('0's and '1's).
2. Each character of the original (decoded) message is represented by a 4-bit binary sequence from `S`.
3. The first 4 bits of `S` represent the first character, the next 4 bits represent the second, and so on.
4. To decode a 4-bit sequence, convert it to its decimal equivalent `X`.
5. This decimal value `X` (which will be between 0 and 15, inclusive) corresponds to the `X`-th lowercase English letter, starting with 'a'. That is, 'a' corresponds to 0, 'b' to 1, 'c' to 2, ..., and 'p' to 15.

Our task is to read `N` and `S`, then output the complete decoded message.

## Intuition & Mathematical Observation

The problem statement provides a direct mapping and a clear structure for decoding. The key observations are:

1.  **Fixed Chunk Size**: Every decoded character is represented by exactly 4 bits. This means we can iterate through the input string `S` in steps of 4. If `N` is the length of `S`, there will be `N/4` decoded characters.

2.  **Binary to Decimal Conversion**: For each 4-bit chunk, we need to convert its binary representation to a decimal integer. For example:
    *   `"0000"` -> 0
    *   `"0001"` -> 1
    *   `"1000"` -> 8
    *   `"1111"` -> 15
    This can be done by standard binary-to-decimal conversion. If the 4 bits are `b3 b2 b1 b0`, the decimal value is `b3*2^3 + b2*2^2 + b1*2^1 + b0*2^0`. A more efficient way in programming is to build the decimal value bit by bit using left shifts and bitwise OR: `decimal_value = (decimal_value << 1) | current_bit;`.

3.  **Decimal to Character Mapping**: Once we have the decimal value `X` (0-15), we need to convert it to the corresponding lowercase English letter. The problem specifies that 'a' is 0, 'b' is 1, ..., 'p' is 15. This is a straightforward mapping: the character can be found by adding `X` to the ASCII value of 'a'. For example, if `X=0`, `'a'+0` gives 'a'; if `X=1`, `'a'+1` gives 'b'; if `X=15`, `'a'+15` gives 'p'.

Combining these, the algorithm is:
*   Initialize an empty string for the decoded message.
*   Loop from `i = 0` to `N-1`, incrementing `i` by 4 in each step.
    *   Inside the loop, take the substring `S[i]` to `S[i+3]` (a 4-bit chunk).
    *   Convert this 4-bit chunk to its decimal equivalent, say `decimal_value`.
    *   Convert `decimal_value` to its corresponding character `decoded_char` using `'a' + decimal_value`.
    *   Append `decoded_char` to the decoded message string.
*   Print the final decoded message.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading the input string `S` takes $O(N)$ time.
    *   The main loop iterates `N/4` times (once for each decoded character).
    *   Inside the main loop, there's an inner loop that runs exactly 4 times (constant time) to convert the 4-bit chunk to a decimal value.
    *   Appending a character to a `std::string` (`decoded_message += decoded_char;`) takes amortized $O(1)$ time. Since we append `N/4` characters, the total time for string building is $O(N/4)$.
    *   Therefore, the dominant operations are proportional to `N`, making the overall time complexity $O(N)$.

*   **Space Complexity**: $O(N)$
    *   Storing the input string `S` requires $O(N)$ space.
    *   Storing the `decoded_message` string requires $O(N/4)$ space, which simplifies to $O(N)$.
    *   Other variables (like `N`, `i`, `j`, `decimal_value`, `bit_val`, `decoded_char`) use constant space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries for competitive programming

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the encoded string
    string S;
    cin >> S; // Read the encoded string

    string decoded_message = ""; // Initialize an empty string to store the decoded message

    // Iterate through the encoded string in chunks of 4 bits
    // Each 4-bit chunk represents one character
    for (int i = 0; i < N; i += 4) {
        int decimal_value = 0; // This will store the decimal equivalent of the 4-bit chunk

        // Process each of the 4 bits in the current chunk
        for (int j = 0; j < 4; ++j) {
            // Get the character at the current bit position (S[i+j])
            // Convert '0' to integer 0, and '1' to integer 1
            int bit_val = S[i + j] - '0';

            // Build the decimal value from the bits.
            // This is equivalent to shifting the current decimal_value left by 1 bit
            // (multiplying by 2) and then adding the new bit.
            // For example, if decimal_value is 0 and bit_val is 1, it becomes 1.
            // If decimal_value is 1 (binary 0001) and bit_val is 0, it becomes 2 (binary 0010).
            // If decimal_value is 2 (binary 0010) and bit_val is 0, it becomes 4 (binary 0100).
            // If decimal_value is 4 (binary 0100) and bit_val is 1, it becomes 9 (binary 1001).
            decimal_value = (decimal_value << 1) | bit_val;
        }

        // The problem states that the first 16 lowercase English letters ('a' through 'p')
        // are encoded. 'a' corresponds to decimal 0, 'b' to 1, ..., 'p' to 15.
        // So, we can simply add the calculated decimal_value to the ASCII value of 'a'
        // to get the decoded character.
        char decoded_char = 'a' + decimal_value;
        
        // Append the decoded character to our result string
        decoded_message += decoded_char;
    }

    // Print the complete decoded message followed by a newline
    cout << decoded_message << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```