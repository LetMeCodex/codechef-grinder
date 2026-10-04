# [Pet Store (PETSTORE)](https://www.codechef.com/problems/PETSTORE)
- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if it's possible to divide a given set of animals, identified by their types, into two equal halves for Alice and Bob. Each animal type is represented by an integer. We are given the total number of animals and a list of their types.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the conditions under which a perfect division is possible. We need to split the animals into two groups of equal size. Let $N$ be the total number of animals.

1.  **Total Number of Animals:** For Alice and Bob to receive an equal number of animals, the total number of animals, $N$, must be an even number. If $N$ is odd, it's impossible to divide them into two groups of size $N/2$. So, the first condition is that $N$ must be even.

2.  **Distribution of Animal Types:** Consider a specific type of animal. Let's say there are $k$ animals of type $X$. For Alice and Bob to receive an equal share of animals *of this specific type*, the number of animals of type $X$, i.e., $k$, must also be an even number. If $k$ is odd, one person will receive $(k+1)/2$ animals of type $X$, and the other will receive $(k-1)/2$, leading to an unequal distribution of that specific animal type. Since this must hold true for *every* animal type to ensure a fair split of the entire collection, the count of each distinct animal type must be even.

Combining these observations, the problem can be solved by checking two conditions:
*   The total number of animals ($N$) must be even.
*   The count of each individual animal type must be even.

If both these conditions are met, then it's possible to divide the animals equally. Otherwise, it's not.

## Complexity Analysis

-   **Time Complexity**: $O(N + M)$, where $N$ is the total number of animals and $M$ is the maximum possible animal type ID (which is 100 in this problem).
    *   We iterate through the $N$ animals to count their types. This takes $O(N)$ time.
    *   We then iterate through all possible animal types (from 1 to 100) to check if their counts are even. This takes $O(M)$ time.
    *   Since $M$ is a constant (100), the overall time complexity is dominated by reading the input, effectively $O(N)$ per test case.

-   **Space Complexity**: $O(M)$, where $M$ is the maximum possible animal type ID.
    *   We use an array `counts` of size 101 to store the frequency of each animal type. This array's size is fixed and independent of $N$.
    *   Therefore, the space complexity is $O(101)$, which is constant space, $O(M)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout

// Declare counts array globally to be zero-initialized by default.
// Max A_i is 100, so an array of size 101 (indices 0-100) is sufficient.
// We will use indices 1 to 100 for animal types.
int counts[101]; 

void solve() {
    int N;
    std::cin >> N;

    // For each test case, reset the counts array.
    // We only care about animal types from 1 to 100.
    for (int i = 1; i <= 100; ++i) {
        counts[i] = 0;
    }

    // Read all animal types and update their counts.
    for (int i = 0; i < N; ++i) {
        int animal_type;
        std::cin >> animal_type;
        counts[animal_type]++;
    }

    // Condition 1: Total number of animals N must be even.
    // If N is odd, it's impossible to split them into two groups of equal size.
    if (N % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    // Condition 2: The count of each animal type must be even.
    // If any animal type has an odd count, it's impossible to split that type
    // equally between Alice and Bob.
    bool possible = true;
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] % 2 != 0) {
            possible = false;
            break; // Found an odd count, no need to check further
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the function to solve each test case
    }

    return 0; // Indicate successful execution
}
```