# Deputy Chef (DEPCHEF)
- **Difficulty Rating**: 1397
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum defense value among all soldiers who are guaranteed to survive an attack. There are $N$ soldiers arranged in a circle. Each soldier $i$ has an attack power $A_i$ and a defense power $D_i$. A soldier $i$ can be attacked by their immediate neighbors: soldier $(i-1) \pmod N$ and soldier $(i+1) \pmod N$. A soldier $i$ survives if their defense power $D_i$ is strictly greater than the total attack power directed at them. The total attack power on soldier $i$ is the sum of the attack powers of their two neighbors. We need to find the maximum $D_i$ among all soldiers $i$ for whom $D_i > A_{(i-1) \pmod N} + A_{(i+1) \pmod N}$. If no soldier can guarantee survival, we should output -1.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the condition for a soldier to be "guaranteed to survive". A soldier $i$ is guaranteed to survive if their defense power $D_i$ is strictly greater than the *maximum possible attack* they can receive. Since the soldiers are in a circle, soldier $i$ has two neighbors: the soldier to their left and the soldier to their right.

Let's denote the soldiers by indices $0, 1, \dots, N-1$.
For soldier $i$:
- The soldier to their left is at index $(i-1+N) \pmod N$.
- The soldier to their right is at index $(i+1) \pmod N$.

The attack power of the left neighbor is $A_{(i-1+N) \pmod N}$.
The attack power of the right neighbor is $A_{(i+1) \pmod N}$.

The total attack power on soldier $i$ is the sum of the attack powers of these two neighbors:
$Attack_{on\_i} = A_{(i-1+N) \pmod N} + A_{(i+1) \pmod N}$.

Soldier $i$ survives if and only if $D_i > Attack_{on\_i}$.
$D_i > A_{(i-1+N) \pmod N} + A_{(i+1) \pmod N}$.

We are looking for the maximum defense value among all soldiers who satisfy this survival condition. This means we need to iterate through each soldier, check if they satisfy the condition, and if they do, keep track of the maximum defense value seen so far.

If no soldier satisfies the condition, the initial maximum defense value (which we can initialize to -1) will remain -1, which is the correct output in that case.

The indices need to be handled carefully due to the circular arrangement. The modulo operator `%` is crucial here. For index $i$, the left neighbor is $(i-1+N)\%N$ and the right neighbor is $(i+1)\%N$. Adding $N$ before taking the modulo for the left neighbor ensures that we handle the case where $i=0$ correctly (i.e., $(0-1+N)\%N = (N-1)\%N = N-1$).

## Complexity Analysis
- **Time Complexity**: $O(N)$
    - We read $N$ attack values and $N$ defense values, which takes $O(N)$ time.
    - We then iterate through all $N$ soldiers once. For each soldier, we perform a constant number of operations: calculating neighbor indices, summing their attack powers, and comparing with the current soldier's defense. This loop takes $O(N)$ time.
    - Therefore, the total time complexity is dominated by the input reading and the single pass, resulting in $O(N)$.

- **Space Complexity**: $O(N)$
    - We use two vectors, `a` and `d`, to store the attack and defense powers of the $N$ soldiers. Each vector requires $O(N)$ space.
    - The other variables used (like `t`, `n`, `max_safe_defense`, `left_attacker_attack`, `right_attacker_attack`, `max_attack_on_i`) take constant space, $O(1)$.
    - Thus, the total space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of soldiers
        std::cin >> n;

        // Vectors to store attack and defense powers
        std::vector<long long> a(n);
        std::vector<long long> d(n);

        // Read attack powers
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        // Read defense powers
        for (int i = 0; i < n; ++i) {
            std::cin >> d[i];
        }

        // Initialize max_safe_defense to -1. This will be the output if no soldier can survive.
        long long max_safe_defense = -1;

        // Iterate through each soldier to check if they can guarantee survival
        for (int i = 0; i < n; ++i) {
            // Calculate the index of the left neighbor, handling circularity.
            // (i - 1 + n) % n ensures a positive result for i = 0.
            long long left_neighbor_idx = (i - 1 + n) % n;
            // Calculate the index of the right neighbor, handling circularity.
            long long right_neighbor_idx = (i + 1) % n;

            // Get the attack power of the left and right neighbors
            long long left_attacker_attack = a[left_neighbor_idx];
            long long right_attacker_attack = a[right_neighbor_idx];

            // The maximum possible attack on soldier i is the sum of their neighbors' attack powers.
            long long max_attack_on_i = left_attacker_attack + right_attacker_attack;

            // Check if soldier i's defense is strictly greater than the maximum possible attack.
            // If it is, soldier i is guaranteed to survive.
            if (d[i] > max_attack_on_i) {
                // If this soldier is a guaranteed survivor, update max_safe_defense
                // to be the maximum of its current value and the defense of this soldier.
                max_safe_defense = std::max(max_safe_defense, d[i]);
            }
        }
        // Output the maximum defense value among guaranteed survivors, or -1 if none exist.
        std::cout << max_safe_defense << "\n";
    }
    return 0;
}
```