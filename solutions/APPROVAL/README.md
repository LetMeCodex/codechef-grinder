# [Approval Ratings (APPROVAL)](https://www.codechef.com/problems/APPROVAL)
- **Difficulty Rating**: 915
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum cost to achieve a total approval rating of at least 35. We are given the initial scores of 5 judges, where each judge's score is between 0 and 10, inclusive. If the sum of the 5 judges' scores is less than 35, we can bribe judges. Bribing a judge changes their score to 10, regardless of their previous score. Each bribe costs 100 gold coins. We need to output the minimum total gold coins required.

## Intuition & Mathematical Observation

The core idea is to minimize the number of bribes, as each bribe has a fixed cost of 100 gold coins. To minimize bribes, we should maximize the increase in the total sum for each bribe we make.

Consider a judge with a current score `S`. If we bribe this judge, their score becomes 10. The increase in the total sum of scores due to this bribe will be `10 - S`. To maximize this increase (`10 - S`), `S` must be as small as possible.

This leads to a greedy strategy:
1. **Calculate the initial sum** of the 5 judges' scores.
2. **Check if the target is already met:** If the initial sum is already 35 or more, no bribes are needed. The cost is 0.
3. **If not, sort the judges' scores** in ascending order. This allows us to easily identify the judge with the lowest current score.
4. **Iteratively bribe judges:** Starting from the judge with the lowest score (the first element in the sorted list), bribe them.
    - Increment the `bribes_count`.
    - Update the `current_sum`: subtract the old score and add 10 (since their score becomes 10).
    - After each bribe, check if the `current_sum` has reached 35 or more. If it has, we stop, as no further bribes are needed.
5. **Calculate total cost:** The minimum total gold coins will be `bribes_count * 100`.

This greedy approach works because each bribe is independent, and choosing the judge with the lowest score always provides the most efficient increase towards the target sum for a single bribe.

## Complexity Analysis

Let $N$ be the number of judges, which is fixed at 5.
Let $T$ be the number of test cases.

-   **Time Complexity**:
    -   Reading 5 integers: $O(N)$.
    -   Calculating the initial sum: $O(N)$.
    -   Sorting the 5 scores: $O(N \log N)$. Since $N=5$ is a small constant, this is effectively $O(1)$.
    -   Loop for bribing: In the worst case, we might need to bribe all 5 judges. Each iteration involves constant time operations. So, this loop runs at most $N$ times, making it $O(N)$.
    -   Overall for one test case (`solve()` function): $O(N + N \log N + N) = O(N \log N)$. Since $N=5$, this simplifies to $O(1)$ (constant time).
    -   Total time complexity for $T$ test cases: $O(T \cdot 1) = O(T)$.

-   **Space Complexity**:
    -   Storing the 5 judges' scores in a `std::vector<int> A`: $O(N)$. Since $N=5$ is a constant, this is $O(1)$ (constant space).
    -   Other variables (`current_sum`, `bribes_count`, loop counters) use $O(1)$ space.
    -   Total space complexity: $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    vector<int> A(5); // Vector to store the 5 judges' scores
    int current_sum = 0; // Variable to keep track of the total sum of scores
    
    // Read the 5 scores and calculate their initial sum
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        current_sum += A[i];
    }

    // If the initial sum is already 35 or more, no bribes are needed.
    if (current_sum >= 35) {
        cout << 0 << "\n"; // Output 0 gold coins
        return; // Exit the function for this test case
    }

    // To minimize bribes, we should always bribe the judge with the lowest current score first.
    // Sorting the scores in ascending order allows us to easily pick the lowest ones.
    sort(A.begin(), A.end());

    int bribes_count = 0; // Counter for the number of bribes made
    
    // Iterate through the sorted scores, simulating bribing judges one by one
    // starting from the lowest score.
    for (int i = 0; i < 5; ++i) {
        // If current_sum is already 35 or more, we have achieved the target.
        // No more bribes are needed, so we can stop.
        if (current_sum >= 35) {
            break; 
        }
        
        // Bribe the judge with the current lowest score (A[i]).
        // Their score changes from A[i] to 10.
        // The total sum increases by (10 - A[i]).
        current_sum = current_sum - A[i] + 10;
        bribes_count++; // Increment the bribe count
    }

    // Output the total gold coins needed. Each bribe costs 100 gold coins.
    cout << bribes_count * 100 << "\n";
}

int main() {
    // Fast I/O: Unties C++ streams from C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}

```