# Prime Sum (PRIMESUM7)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count the number of pairs of elements $(A_i, A_j)$ from a given array $A$ such that $i < j$ and their sum $A_i + A_j$ is a prime number. The elements of the array $A$ are guaranteed to be integers between 1 and 3, inclusive.

## Intuition & Mathematical Observation
The key observation is that the elements of the array are restricted to only three possible values: 1, 2, and 3. This significantly limits the possible sums of pairs. Let's list all possible sums and check if they are prime:

1.  **Sum of two 1s**: $1 + 1 = 2$. The number 2 is prime.
2.  **Sum of a 1 and a 2**: $1 + 2 = 3$. The number 3 is prime.
3.  **Sum of a 1 and a 3**: $1 + 3 = 4$. The number 4 is not prime.
4.  **Sum of two 2s**: $2 + 2 = 4$. The number 4 is not prime.
5.  **Sum of a 2 and a 3**: $2 + 3 = 5$. The number 5 is prime.
6.  **Sum of two 3s**: $3 + 3 = 6$. The number 6 is not prime.

From this analysis, we see that only three combinations of elements result in a prime sum:
*   A pair of (1, 1) sums to 2.
*   A pair of (1, 2) sums to 3.
*   A pair of (2, 3) sums to 5.

The problem requires us to count pairs $(A_i, A_j)$ where $i < j$. This means we are looking for unordered pairs, but the indices must be distinct.

To efficiently count these pairs, we can first count the occurrences of each number (1, 2, and 3) in the input array. Let:
*   `count1` be the number of 1s in the array.
*   `count2` be the number of 2s in the array.
*   `count3` be the number of 3s in the array.

Now, we can calculate the number of pairs for each prime sum:

1.  **Pairs of (1, 1) summing to 2**: If we have `count1` occurrences of the number 1, the number of ways to choose two distinct 1s is given by the combination formula: $\binom{\text{count1}}{2} = \frac{\text{count1} \times (\text{count1} - 1)}{2}$.

2.  **Pairs of (1, 2) summing to 3**: To form a pair with a sum of 3, we need one 1 and one 2. The number of ways to choose one 1 from `count1` occurrences and one 2 from `count2` occurrences is `count1 * count2`.

3.  **Pairs of (2, 3) summing to 5**: Similarly, to form a pair with a sum of 5, we need one 2 and one 3. The number of ways to choose one 2 from `count2` occurrences and one 3 from `count3` occurrences is `count2 * count3`.

The total number of pairs with prime sums is the sum of the counts from these three cases.

The constraints on $N$ (the size of the array) are up to 100. This means `count1`, `count2`, and `count3` will also be at most 100. The maximum number of pairs would occur if all elements were 1s, leading to $\binom{100}{2} = \frac{100 \times 99}{2} = 4950$. This fits comfortably within a standard integer type. However, using `long long` for the answer is a good practice to avoid potential overflows in similar problems with larger constraints.

The problem statement also requires using specific headers (`<bits/stdc++.h>`) and namespaces (`using namespace std;`), which are included in the provided solution. Fast I/O is also implemented for efficiency.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution iterates through the input array once to count the occurrences of 1s, 2s, and 3s. This takes $O(N)$ time, where $N$ is the size of the array. The subsequent calculations for the number of pairs are constant time operations, $O(1)$. Therefore, the total time complexity is dominated by the input reading and counting, resulting in $O(N)$ per test case.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`count1`, `count2`, `count3`, `ans`, `N`, `T`, `val`, `i`) regardless of the input size $N$. Thus, the space complexity is constant, $O(1)$, per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required as per problem instructions

void solve() {
    int N;
    cin >> N; // Read the length of the array

    // Initialize counters for each possible value (1, 2, 3)
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    // Read N integers and count their occurrences
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 1) {
            count1++;
        } else if (val == 2) {
            count2++;
        } else { // val must be 3, as per constraints 1 <= A_i <= 3
            count3++;
        }
    }

    // Variable to store the total number of pairs with prime sums.
    // Using long long for 'ans' is a safe practice, though for N <= 100,
    // the maximum possible count (around 9950) would fit in an int.
    long long ans = 0;

    // Calculate pairs that sum to a prime number:
    // Possible sums:
    // 1+1 = 2 (prime)
    // 1+2 = 3 (prime)
    // 1+3 = 4 (not prime)
    // 2+2 = 4 (not prime)
    // 2+3 = 5 (prime)
    // 3+3 = 6 (not prime)

    // 1. Pairs of (1, 1): sum is 2 (prime)
    // Number of ways to choose 2 ones from 'count1' ones is count1 * (count1 - 1) / 2
    // Cast to long long before multiplication to prevent potential overflow if counts were larger,
    // though for N=100, int is sufficient for intermediate products.
    ans += (long long)count1 * (count1 - 1) / 2;

    // 2. Pairs of (1, 2): sum is 3 (prime)
    // Number of ways to choose one 1 and one 2 is count1 * count2
    ans += (long long)count1 * count2;

    // 3. Pairs of (2, 3): sum is 5 (prime)
    // Number of ways to choose one 2 and one 3 is count2 * count3
    ans += (long long)count2 * count3;

    // Output the total count for the current test case
    cout << ans << "\n";
}

int main() {
    // Enable fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```