# [Chef and Subarrays (CHEFARRP)](https://www.codechef.com/problems/CHEFARRP)
- **Difficulty Rating**: 1041
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the number of subarrays in a given array $A$ of $N$ positive integers such that the sum of elements in the subarray is equal to the product of elements in the subarray.

**Constraints:**
- $1 \le T \le 100$ (number of test cases)
- $1 \le N \le 50$ (size of the array)
- $1 \le A_i \le 10^9$ (value of array elements)
- It is guaranteed that $A_1 \cdot A_2 \cdot \dots \cdot A_N \le 10^9$. This implies that the product of elements in any subarray will also not exceed $10^9$.

## Intuition & Mathematical Observation

The key to solving this problem efficiently lies in observing the constraints, particularly the small value of $N$ ($N \le 50$). This small constraint immediately suggests that a solution with a time complexity of $O(N^2)$ or even $O(N^3)$ per test case would be acceptable.

A subarray is defined by its starting and ending indices. For an array of size $N$, there are $N(N+1)/2$ possible subarrays. We can iterate through all possible subarrays, calculate their sum and product, and check if they are equal.

Let's outline the brute-force approach:
1. Initialize a counter `count` to 0.
2. Use an outer loop to pick every possible starting index `i` from $0$ to $N-1$.
3. Use an inner loop to pick every possible ending index `j` from `i` to $N-1$.
4. For each pair `(i, j)` representing the subarray $A[i \dots j]$:
   a. Calculate the sum of elements $A[i] + A[i+1] + \dots + A[j]$.
   b. Calculate the product of elements $A[i] \times A[i+1] \times \dots \times A[j]$.
   c. If the sum equals the product, increment `count`.

To optimize step 4, instead of recalculating the sum and product from scratch for each `(i, j)` pair, we can incrementally update them. When the inner loop extends the subarray from $A[i \dots j-1]$ to $A[i \dots j]$:
- The `current_sum` can be updated by adding $A[j]$.
- The `current_product` can be updated by multiplying by $A[j]$.

**Data Type Considerations:**
- The sum of elements can be up to $N \times \max(A_i) = 50 \times 10^9 = 5 \times 10^{10}$. This value exceeds the maximum capacity of a 32-bit integer (`int`), so `long long` must be used for `current_sum`.
- The problem guarantees that the product of all elements $A_1 \cdot A_2 \cdot \dots \cdot A_N \le 10^9$. This means the product of any subarray will also not exceed $10^9$. While $10^9$ fits within a 32-bit signed integer, using `long long` for `current_product` is safer and consistent with `current_sum`, preventing any potential overflow issues or type mismatches during comparison.
- The `count` of subarrays can be at most $N(N+1)/2 = 50 \times 51 / 2 = 1275$. This fits comfortably within a 32-bit integer, but `long long` is used in the provided solution for consistency.

This approach directly implements the problem definition and is efficient enough given the constraints.

## Complexity Analysis

-   **Time Complexity**: $O(N^2)$
    -   The outer loop iterates `N` times (for the starting index `i`).
    -   The inner loop iterates up to `N` times (for the ending index `j`).
    -   Inside the inner loop, we perform constant-time operations (addition, multiplication, comparison).
    -   Thus, the total number of operations per test case is proportional to $N \times N = N^2$.
    -   Given $N \le 50$, $N^2 = 50^2 = 2500$.
    -   For $T$ test cases, the total time complexity is $O(T \cdot N^2)$. With $T=100$ and $N=50$, this is $100 \times 2500 = 250,000$ operations, which is well within typical time limits (usually $10^8$ operations per second).

-   **Space Complexity**: $O(N)$
    -   We use a `std::vector<long long> a(n)` to store the input array elements, which requires $O(N)$ space.
    -   A few additional variables (`count`, `current_sum`, `current_product`, `n`, `t`, `i`, `j`) consume $O(1)$ auxiliary space.
    -   Therefore, the total space complexity is dominated by the input array storage, resulting in $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for using std::vector to store the array elements

// As per competitive programming common practice and problem instructions,
// using the entire std namespace to avoid prefixing std:: everywhere.
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the size of the array

    // Declare a vector of long long to store array elements.
    // long long is used because elements can be up to 10^9,
    // and sums can exceed 2*10^9 (max for 32-bit int).
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read array elements
    }

    long long count = 0; // Initialize counter for subarrays satisfying the condition

    // Iterate through all possible starting indices 'i' for subarrays
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;     // Initialize sum for the current subarray
        long long current_product = 1; // Initialize product for the current subarray (product starts at 1)

        // Iterate through all possible ending indices 'j' for subarrays, starting from 'i'
        for (int j = i; j < n; ++j) {
            // Add the current element A[j] to the running sum
            current_sum += a[j];

            // Multiply the current element A[j] to the running product
            // The problem states A[i] are positive (1 <= A[i] <= 10^9),
            // so no division by zero or product becoming zero unexpectedly.
            // The constraint A1 * A2 * ... * An <= 10^9 ensures that
            // any subarray product will also not exceed 10^9.
            // long long is used for current_product for consistency and safety,
            // as current_sum can reach 50 * 10^9.
            current_product *= a[j];

            // Check if the current sum equals the current product
            if (current_sum == current_product) {
                count++; // If they are equal, increment the counter
            }
        }
    }

    // Output the total count for the current test case, followed by a newline
    cout << count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```