# [Cats and Dogs (CATSDOGS)](https://www.codechef.com/problems/CATSDOGS)
- **Difficulty Rating**: 1389
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if a given total number of legs, `L`, is possible for a group of `C` cats and `D` dogs. Each animal (cat or dog) has 4 legs. The key constraint is that cats can ride on dogs. Each dog can carry at most 2 cats.

We are given `C` (number of cats), `D` (number of dogs), and `L` (total observed legs). We need to output "yes" if `L` is a possible configuration, and "no" otherwise.

## Intuition & Mathematical Observation

The core idea to solve this problem is to find the minimum and maximum possible number of legs that can be on the ground. If the given `L` falls within this range and satisfies other basic conditions, then it's a "yes".

1.  **Divisibility by 4**: Since every animal has exactly 4 legs, the total number of legs on the ground must always be a multiple of 4. If `L % 4 != 0`, it's impossible.

2.  **Maximum Possible Legs**:
    The maximum number of legs occurs when all animals (all `C` cats and all `D` dogs) are standing on the ground.
    *   Total animals on ground = `C + D`
    *   Maximum total legs = `(C + D) * 4`

3.  **Minimum Possible Legs**:
    The minimum number of legs occurs when as many cats as possible are riding on dogs, thus reducing the number of cats on the ground.
    *   **Dogs**: All `D` dogs must be on the ground, as cats ride on them. So, `D` dogs contribute `D * 4` legs.
    *   **Cats**:
        *   Each dog can carry at most 2 cats.
        *   Therefore, `D` dogs can collectively carry a maximum of `2 * D` cats.
        *   If the total number of cats `C` is less than or equal to `2 * D`, then all `C` cats can potentially ride on dogs. In this scenario, 0 cats *must* be on the ground.
        *   If `C` is greater than `2 * D`, then `2 * D` cats can ride, but the remaining `C - 2 * D` cats *must* be on the ground.
        *   So, the minimum number of cats that *must* be on the ground is `max(0, C - 2 * D)`.
    *   **Total animals on ground (minimum case)**: `(minimum cats on ground) + D`
    *   Minimum total legs = `(max(0, C - 2 * D) + D) * 4`

4.  **Final Check**:
    For `L` to be a possible number of legs, it must satisfy all three conditions:
    *   `L % 4 == 0` (L must be a multiple of 4)
    *   `L >= minimum_total_legs`
    *   `L <= maximum_total_legs`

If all these conditions are met, the answer is "yes"; otherwise, it's "no".

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a fixed number of arithmetic operations (subtraction, multiplication, addition, comparison, modulo) and a `std::max` call. These operations take constant time. Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a few variables (`t`, `C`, `D`, `L`, `cats_standing_min`, `min_total_legs`, `max_total_legs`) to store input and intermediate calculations. The amount of memory used does not depend on the input size, hence it's constant space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        long long C, D, L;
        std::cin >> C >> D >> L; // Read cats, dogs, and legs

        // Calculate the minimum possible number of legs on the ground.
        // All D dogs are always on the ground.
        // The maximum number of cats that can ride is 2*D.
        // The remaining cats (C - 2*D, if positive) must be on the ground.
        long long cats_standing_min = std::max(0LL, C - 2 * D);
        long long min_total_legs = (cats_standing_min + D) * 4;

        // Calculate the maximum possible number of legs on the ground.
        // This happens when all cats and all dogs are standing.
        long long max_total_legs = (C + D) * 4;

        // Check if the given L is possible.
        // 1. L must be a multiple of 4.
        // 2. L must be within the calculated range [min_total_legs, max_total_legs].
        if (L % 4 == 0 && L >= min_total_legs && L <= max_total_legs) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}
```