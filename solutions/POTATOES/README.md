# Farmer Feb (POTATOES)
- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of potatoes that need to be added to a field, which already contains `x` potatoes, such that the total number of potatoes becomes a prime number. We are given two fields with `x` and `y` potatoes respectively. We need to find the smallest non-negative integer `k` such that `x + y + k` is a prime number.

## Intuition & Mathematical Observation
The core of this problem lies in identifying prime numbers. We are given two numbers, `x` and `y`, and we need to find the smallest `k >= 0` such that `x + y + k` is prime.

Let `S = x + y`. We are looking for the smallest `k >= 0` such that `S + k` is prime. This means we need to find the next prime number greater than or equal to `S`. The number of potatoes to add, `k`, will then be `(next_prime_greater_than_or_equal_to_S) - S`.

Since the maximum values for `x` and `y` are 1000, their sum `x + y` can be at most 2000. The next prime number after 2000 is not too far away. This suggests that we can precompute prime numbers up to a certain limit to efficiently check for primality.

A common and efficient way to find all prime numbers up to a given limit is the Sieve of Eratosthenes. We can use this sieve to mark all prime numbers up to a value slightly larger than the maximum possible sum of `x` and `y`. A safe upper bound would be around 2000 + a small buffer, say 2005, to ensure we find the next prime.

Once we have the sieve, for each test case:
1. Calculate the sum `current_sum = x + y`.
2. Start checking numbers from `current_sum + 1` onwards.
3. For each number, check if it's prime using our precomputed sieve.
4. The first prime number we encounter, say `P`, is the target sum.
5. The number of potatoes to add is `k = P - current_sum`.

## Complexity Analysis
- **Time Complexity**:
    - **Sieve of Eratosthenes**: The sieve runs up to `MAX_SUM`. The time complexity of the Sieve of Eratosthenes is approximately $O(N \log \log N)$, where $N$ is the upper limit of the sieve. In our case, $N = \text{MAX\_SUM} \approx 2005$. This precomputation is done only once.
    - **Per Test Case**: For each test case, we calculate `x + y` and then iterate to find the next prime. In the worst case, the gap between two consecutive primes can be relatively small. The maximum sum is 2000. The next prime after 2000 is 2003. The maximum gap between primes around 2000 is much smaller than 2005. Therefore, the loop to find the next prime will run at most a few times. Checking primality using the sieve is $O(1)$. So, the time complexity per test case is effectively constant, $O(1)$, after the sieve is built.
    - **Overall**: With `t` test cases, the total time complexity is $O(\text{MAX\_SUM} \log \log \text{MAX\_SUM} + t)$. Given the constraints, this is very efficient.

- **Space Complexity**:
    - We use a `std::vector<bool>` named `is_prime` of size `MAX_SUM` to store the primality of numbers. This takes $O(\text{MAX\_SUM})$ space.
    - Other variables take constant space.
    - Therefore, the space complexity is $O(\text{MAX\_SUM})$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// Maximum possible sum of x, y, and potatoes from third field.
// x <= 1000, y <= 1000. The next prime after 2000 is 2003.
// A buffer is good practice. 2005 is sufficient.
const int MAX_SUM = 2005;
vector<bool> is_prime(MAX_SUM, true);

// Function to precompute prime numbers using Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (int p = 2; p * p < MAX_SUM; ++p) {
        // If is_prime[p] is not changed, then it is a prime
        if (is_prime[p]) {
            // Update all multiples of p
            for (int i = p * p; i < MAX_SUM; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute primes once
    sieve();

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x, y; // Number of potatoes in the first two fields
        cin >> x >> y;

        int current_sum = x + y; // Sum of potatoes in the first two fields
        int potatoes_needed = 1; // Start checking from 1 potato added

        // Find the smallest number of potatoes to add (potatoes_needed)
        // such that (current_sum + potatoes_needed) is a prime number.
        while (true) {
            if (is_prime[current_sum + potatoes_needed]) {
                cout << potatoes_needed << "\n"; // Output the minimum number of potatoes needed
                break; // Move to the next test case
            }
            potatoes_needed++; // Increment to check the next possible sum
        }
    }

    return 0;
}
```