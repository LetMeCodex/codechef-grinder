# [Chef and Dolls (MISSP)](https://www.codechef.com/problems/MISSP)

- **Difficulty Rating**: 1012
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $N$ dolls, where $N$ is always odd. Every type of doll appears in pairs, except for exactly one doll type which appears an odd number of times (specifically, once). The objective is to identify the type of the doll that does not have a pair.

## Intuition & Mathematical Observation
The problem can be solved efficiently using the **XOR bitwise operator**. The XOR operation possesses three key properties that are perfect for this scenario:

1.  **Self-Inverse**: $a \oplus a = 0$ (Any number XORed with itself results in zero).
2.  **Identity**: $a \oplus 0 = a$ (Any number XORed with zero remains unchanged).
3.  **Commutativity/Associativity**: The order in which we XOR the numbers does not matter.

If we XOR all the doll types present in the input, all pairs will cancel each other out (resulting in 0), leaving behind only the value of the doll that appears an odd number of times.

**Example:**
If the input is `[1, 2, 1, 3, 2]`:
$1 \oplus 2 \oplus 1 \oplus 3 \oplus 2 = (1 \oplus 1) \oplus (2 \oplus 2) \oplus 3 = 0 \oplus 0 \oplus 3 = 3$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of $N$ dolls exactly once.
- **Space Complexity**: $O(1)$, as we only maintain a single integer variable (`result`) to store the running XOR sum, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * We are given N dolls, where every type of doll appears in pairs except for one.
 * We need to find the type of the doll that does not have a pair.
 * 
 * Mathematical Property:
 * The XOR operation (^) has the following properties:
 * 1. a ^ a = 0
 * 2. a ^ 0 = a
 * 3. XOR is commutative and associative.
 * 
 * If we XOR all the doll types together, all pairs will cancel each other out (x ^ x = 0),
 * leaving only the doll type that appears an odd number of times.
 */

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int doll_type;
            cin >> doll_type;
            // XORing all inputs will leave the single element
            result ^= doll_type;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
```