# [ATM Machine (ATM2)](https://www.codechef.com/problems/ATM2)

- **Difficulty Rating**: 1001
- **Solved in**: 1 attempt(s)

## Problem Summary
An ATM machine has a total amount of $K$ units of money. There are $N$ people standing in a queue, each wishing to withdraw a specific amount $A_i$. The ATM processes the queue in order. If the ATM has enough money to satisfy a person's request ($K \ge A_i$), it gives them the money and subtracts $A_i$ from $K$. If the ATM does not have enough money, it skips that person. We need to output a binary string representing the outcome for each person: '1' if they successfully withdrew money, and '0' otherwise.

## Intuition & Mathematical Observation
The problem follows a greedy approach. Since the people are processed in a fixed sequence (from index $0$ to $N-1$), we simply need to maintain the current balance of the ATM. 

For each person $i$:
1. Check if the current balance $K$ is greater than or equal to the requested amount $A_i$.
2. If **True**: The transaction is successful. We append '1' to our result string and update the balance: $K = K - A_i$.
3. If **False**: The transaction cannot be fulfilled. We append '0' to our result string and leave $K$ unchanged.

Because the decision for each person depends only on the remaining balance after all previous successful transactions, a single pass through the array is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of people in the queue. We iterate through the list of requests exactly once.
- **Space Complexity**: $O(N)$ to store the result string (or $O(1)$ auxiliary space if we print the characters directly).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        
        std::string result = "";
        for (int i = 0; i < n; ++i) {
            long long amount;
            std::cin >> amount;
            
            // Check if the ATM has enough money for the current person
            if (k >= amount) {
                k -= amount;
                result += '1';
            } else {
                result += '0';
            }
        }
        std::cout << result << "\n";
    }
    return 0;
}
```