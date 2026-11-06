# Luigi and Uniformity (DIVIDEMAKEEQ)

- **Difficulty Rating**: 1185
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations to make all elements in an array $A$ of size $N$ equal to some positive integer $K$. An operation consists of choosing an element $A_i$ and replacing it with $A_i / d$, where $d$ is a positive integer divisor of $A_i$. We can perform this operation any number of times on any element.

## Intuition & Mathematical Observation

The core idea is to find a target value $K$ such that we can transform all elements of the array $A$ into $K$ using the allowed operation, and the total number of operations is minimized.

Let's consider an element $A_i$. If we want to transform $A_i$ into $K$, it means $K$ must be obtainable from $A_i$ by repeatedly dividing by divisors. This implies that $K$ must be a divisor of $A_i$. If we want to make *all* elements $A_i$ equal to the *same* value $K$, then $K$ must be a divisor of *every* element $A_i$ in the array.

This leads to a crucial observation: the target value $K$ must be a common divisor of all elements in the array $A$. If $K$ is a common divisor of all $A_i$, then for each $A_i$, we can repeatedly divide $A_i$ by $A_i/K$ (which is a divisor of $A_i$) to transform $A_i$ into $K$. The number of operations for a single element $A_i$ to become $K$ is 1 (if $A_i \neq K$) or 0 (if $A_i = K$).

Therefore, the problem reduces to finding a common divisor $K$ of all elements in $A$ that maximizes the number of elements already equal to $K$. If we find such a $K$, the minimum number of operations will be $N$ minus the count of elements initially equal to $K$.

Since $K$ must be a common divisor of all elements in $A$, it must also be a divisor of the greatest common divisor (GCD) of all elements in $A$. Let $G = \text{gcd}(A_1, A_2, \dots, A_N)$. Any common divisor of all $A_i$ is also a divisor of $G$. Conversely, any divisor of $G$ is a common divisor of all $A_i$.

So, the candidate target values $K$ are precisely the positive divisors of $G$. We need to iterate through all divisors of $G$, and for each divisor $d$, check its frequency in the original array $A$. The divisor $d$ that has the highest frequency in $A$ will be our optimal target $K$. The minimum number of operations will then be $N - \text{max\_frequency}$.

**Algorithm:**
1. Read the input array $A$ of size $N$.
2. Calculate the GCD of all elements in $A$. Let this be $G$.
3. Find all positive divisors of $G$.
4. For each divisor $d$ of $G$, count its occurrences in the original array $A$.
5. Find the maximum frequency among all divisors of $G$.
6. The minimum number of operations is $N - \text{maximum frequency}$.

**Example:**
Let $A = [6, 12, 18]$.
1. $N = 3$.
2. $\text{gcd}(6, 12, 18) = 6$. So, $G = 6$.
3. Divisors of 6 are $\{1, 2, 3, 6\}$.
4. Frequencies in $A$:
   - 1: 0 times
   - 2: 0 times
   - 3: 0 times
   - 6: 1 time
5. Maximum frequency is 1 (for $K=6$).
6. Minimum operations = $3 - 1 = 2$.
   We can choose $K=6$. $A_1=6$ (0 ops), $A_2=12 \to 12/2=6$ (1 op), $A_3=18 \to 18/3=6$ (1 op). Total 2 ops.

## Complexity Analysis

- **Time Complexity**:
    - Reading the input array: $O(N)$.
    - Calculating the GCD of $N$ numbers: If we use `std::gcd` iteratively, it takes $O(N \log(\max(A_i)))$.
    - Finding divisors of $G$: If $G$ is the GCD, the maximum value of $G$ can be up to $10^9$. Finding divisors up to $\sqrt{G}$ takes $O(\sqrt{G})$.
    - Counting frequencies of divisors: We iterate through the divisors of $G$. The number of divisors of an integer $G$ can be large in the worst case, but for $G \le 10^9$, it's manageable. A loose upper bound on the number of divisors for a number up to $10^9$ is around $1344$ (for $735134400$). For each divisor, we check its frequency in the map, which is $O(\log N)$ if we use `std::map` or $O(1)$ on average if we use `std::unordered_map`.
    - Overall, the dominant factor is finding divisors, which is $O(\sqrt{G})$. Given $G \le 10^9$, $\sqrt{G} \approx 31622$.
    - The frequency counting using `std::map` would be $O(\text{number of divisors} \times \log N)$.
    - The overall time complexity is approximately $O(N \log(\max(A_i)) + \sqrt{G} + D \log N)$, where $D$ is the number of divisors of $G$. For the given constraints, this is efficient enough.

- **Space Complexity**:
    - Storing the array $A$: $O(N)$.
    - Storing the frequency map: $O(N)$ in the worst case if all elements are distinct.
    - Storing the divisors of $G$: $O(D)$, where $D$ is the number of divisors of $G$.
    - Overall, the space complexity is $O(N + D)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <numeric>  // Required for std::gcd
#include <map>      // Required for std::map
#include <algorithm> // Required for std::max

// Function to calculate GCD of an array of positive integers.
// Assumes arr is not empty and contains positive integers.
int calculate_array_gcd(const std::vector<int>& arr) {
    // Initialize result with the first element.
    // Constraints state N >= 1, so arr will not be empty.
    int result = arr[0];
    // Iterate from the second element to calculate GCD cumulatively.
    for (size_t i = 1; i < arr.size(); ++i) {
        result = std::gcd(result, arr[i]);
        // Optimization: If GCD becomes 1, it cannot get any smaller.
        // The overall GCD of the array will be 1.
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

// Function to find all positive divisors of a given positive integer n.
std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    // Iterate up to sqrt(n) to find divisors.
    // If i divides n, then n/i also divides n.
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            // If i*i is not equal to n, then i and n/i are distinct divisors.
            // If i*i == n, then i and n/i are the same, so add only once.
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

void solve() {
    int n;
    std::cin >> n; // Read the size of the array

    std::vector<int> a(n); // Declare vector to store array elements
    std::map<int, int> freq; // Map to store frequencies of elements in array A

    // Read array elements and populate frequency map
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    // Edge case: If N=1, the array already has all elements equal. 0 moves.
    // This is handled correctly by the general logic as well (GCD will be A[0],
    // A[0] will be in freq map with count 1, N - 1 = 0 moves).
    if (n == 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Calculate the greatest common divisor (GCD) of all elements in the array.
    // The target value K must be a divisor of all A_i, hence K must be a divisor of their GCD.
    int common_gcd = calculate_array_gcd(a);

    // Find all divisors of the common_gcd. These are the candidate target values K.
    std::vector<int> divisors_of_gcd = get_divisors(common_gcd);

    // We want to maximize the number of elements that are already equal to the target K.
    // This means finding a K (which is a divisor of common_gcd) that appears most frequently in A.
    int max_freq_for_target = 0;

    // Iterate through all candidate target values (divisors of common_gcd)
    for (int d : divisors_of_gcd) {
        // Check if this candidate target value 'd' exists in the original array A.
        if (freq.count(d)) {
            // If it exists, update max_freq_for_target with the frequency of 'd'.
            max_freq_for_target = std::max(max_freq_for_target, freq[d]);
        }
    }

    // The minimum number of moves is N minus the maximum number of elements
    // that are already equal to the chosen target value K.
    std::cout << n - max_freq_for_target << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```