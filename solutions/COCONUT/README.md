# [Summer Heat (COCONUT)](https://www.codechef.com/problems/COCONUT)
- **Difficulty Rating**: 852
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of coconut packets we can buy from two different shops.

We are given:
1. `xa`: Number of coconuts in one packet from Shop A.
2. `xb`: Number of coconuts in one packet from Shop B.
3. `Xa`: Total number of coconuts required from Shop A.
4. `Xb`: Total number of coconuts required from Shop B.

We need to find the total number of packets we can buy, which is the sum of packets from Shop A and packets from Shop B.

## Intuition & Mathematical Observation

The core idea revolves around integer division. When we need a certain total quantity (`Xa`) and each unit comes in a fixed size (`xa`), the number of units we can acquire is simply the total quantity divided by the size of one unit, using integer division. This is because we can only buy whole packets. Any remainder means we don't have enough to buy another full packet.

1.  **Packets from Shop A**: If we need `Xa` coconuts and each packet from Shop A contains `xa` coconuts, the number of packets we can buy from Shop A is `Xa / xa` (integer division). For example, if `Xa = 10` and `xa = 3`, we can buy `10 / 3 = 3` packets, obtaining 9 coconuts. We cannot buy a fourth packet as we only need 1 more coconut, and packets come in units of 3.

2.  **Packets from Shop B**: Similarly, for Shop B, the number of packets we can buy is `Xb / xb` (integer division).

3.  **Total Packets**: The total number of packets will be the sum of packets from Shop A and Shop B.

So, the formula is `(Xa / xa) + (Xb / xb)`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, where `T` is the number of test cases. Inside each test case, it performs a fixed number of operations: reading four integers, two integer divisions, one addition, and printing an integer. All these operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`t`, `xa`, `xb`, `Xa`, `Xb`, `num_a`, `num_b`) to store input and intermediate results. The memory usage does not depend on the input values or the number of test cases (beyond the stack space for function calls, which is constant for this flat structure). Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop 't' times, once for each test case.
    while (t--) {
        int xa, xb, Xa, Xb; // Declare integer variables for the problem inputs.
        std::cin >> xa >> xb >> Xa >> Xb; // Read the four input values for the current test case.

        // Calculate the number of packets from Shop A using integer division.
        int num_a = Xa / xa;
        // Calculate the number of packets from Shop B using integer division.
        int num_b = Xb / xb;

        // Print the sum of packets from both shops, followed by a newline character.
        std::cout << num_a + num_b << "\n";
    }

    return 0; // Indicate successful program execution.
}

```