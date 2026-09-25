# [RCB and Playoffs (RCBPLAY)](https://www.codechef.com/problems/RCBPLAY)
- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if the Royal Challengers Bangalore (RCB) team can qualify for the playoffs. We are given three integers:
1. `X`: The current total points RCB has.
2. `Y`: The minimum total points required to qualify for the playoffs.
3. `Z`: The number of matches RCB still has to play.

In each match, a win gives 2 points, a draw gives 1 point, and a loss gives 0 points. We need to output "YES" if RCB can achieve at least `Y` points, and "NO" otherwise.

## Intuition & Mathematical Observation

RCB currently has `X` points and needs to reach at least `Y` points. This means they need to gain at least `Y - X` more points from their remaining `Z` matches.

To determine if qualification is possible, we should consider the *best-case scenario* for RCB in their remaining `Z` matches. The best-case scenario is one where they maximize the points they can get from these matches.

Each match offers a maximum of 2 points (by winning). Therefore, to maximize their points from `Z` matches, RCB should aim to win all `Z` matches.
If RCB wins all `Z` matches, they will gain `2 * Z` points.

So, the maximum total points RCB can achieve is their current points (`X`) plus the maximum points they can get from the remaining matches (`2 * Z`).
Maximum achievable total points = `X + (2 * Z)`.

Now, we compare this maximum achievable total with the required points `Y`:
- If `X + (2 * Z)` is greater than or equal to `Y`, it means RCB can reach or exceed the qualification threshold. In this case, the answer is "YES".
- If `X + (2 * Z)` is less than `Y`, it means even in the best possible scenario, RCB cannot reach the qualification threshold. In this case, the answer is "NO".

This simple comparison is sufficient because if they can qualify by winning all games, they can also qualify by winning some and drawing others, as long as the total points are sufficient. If even winning all games isn't enough, then no other combination of wins/draws/losses will be enough.

## Complexity Analysis

- **Time Complexity**: $O(T)$
  The program reads `T` test cases. For each test case, it performs a constant number of operations: reading three integers, one multiplication, one addition, one comparison, and printing a string. All these operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  The program uses a fixed amount of memory to store a few integer variables (`t`, `x`, `y`, `z`) regardless of the input values or the number of test cases. This constant memory usage leads to an $O(1)$ space complexity.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Not strictly necessary for this problem, but often included

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int x, y, z; // Variables for current points, required points, and remaining games
        std::cin >> x >> y >> z; // Read the values for the current test case

        // Intuition:
        // To qualify, RCB needs at least Y points.
        // They currently have X points.
        // They need at least Y - X more points.

        // To maximize points from Z remaining games, RCB should win all Z games.
        // Each win gives 2 points.
        // Maximum points from Z games = 2 * Z.

        // Maximum total points RCB can achieve = Current points (X) + Max points from remaining games (2 * Z).
        // If this maximum achievable total is >= Y, then it's possible to qualify.
        // Otherwise, it's impossible.

        if (x + 2 * z >= y) {
            std::cout << "YES\n"; // If qualification is possible
        } else {
            std::cout << "NO\n";  // If qualification is not possible
        }
    }

    return 0; // Indicate successful execution
}

```