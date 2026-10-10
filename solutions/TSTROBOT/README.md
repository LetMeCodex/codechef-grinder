# [Testing Robot (TSTROBOT)](https://www.codechef.com/problems/TSTROBOT)
- **Difficulty Rating**: 1124
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate the movement of a robot on an infinite number line. The robot starts at an initial coordinate `X`. It is then given a string `S` of `N` commands. Each character in `S` is either 'L' (move one unit left) or 'R' (move one unit right). After executing all commands, we need to determine the total number of *distinct* coordinates the robot visited throughout its journey, including its initial position.

## Intuition & Mathematical Observation

1.  **Tracking Current Position**: The core of the problem is to keep track of the robot's current coordinate. We can use an integer variable, say `current_position`, initialized to `X`. For each 'L' command, we decrement `current_position`; for each 'R' command, we increment it.

2.  **Counting Distinct Points**: The crucial requirement is to count *distinct* coordinates. If the robot visits the same point multiple times, it should only be counted once. This immediately suggests using a data structure that automatically handles uniqueness. A `std::set<int>` in C++ is an ideal choice for this purpose. It stores elements in sorted order and ensures that only unique values are present.

3.  **Initial Position**: The robot's starting position `X` is always considered visited. Therefore, `X` must be added to our set of visited points before processing any commands.

4.  **Processing Commands**: We iterate through the command string `S` character by character. For each command:
    *   Update `current_position` based on 'L' or 'R'.
    *   Add the *new* `current_position` to our `std::set`. The `std::set::insert()` method will automatically handle duplicates; if the position has already been visited, it won't be added again.

5.  **Final Result**: After processing all `N` commands, the total number of distinct points visited will simply be the `size()` of our `std::set`.

6.  **Coordinate Range**: The maximum value of `N` is 100, and `X` can be up to 1,000,000 (or down to -1,000,000).
    *   The maximum coordinate reached would be `X + N` (e.g., 1,000,000 + 100 = 1,000,100).
    *   The minimum coordinate reached would be `X - N` (e.g., -1,000,000 - 100 = -1,000,100).
    These values fit comfortably within a standard 32-bit signed integer type (which typically ranges from approximately -2 billion to +2 billion).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input (`N`, `X`, `S`): $O(N)$ for the string `S`.
    *   Initializing `std::set`: $O(1)$.
    *   Inserting the initial position `X` into the set: $O(\log K)$, where $K$ is the current size of the set (initially $K=0$, so $O(\log 1)$).
    *   Looping through the `N` commands in string `S`:
        *   In each iteration, we perform a constant number of operations (character comparison, increment/decrement) and an `insert` operation into the `std::set`.
        *   The `insert` operation into a `std::set` takes $O(\log K)$ time, where $K$ is the number of elements currently in the set.
        *   In the worst case, all $N+1$ positions visited are distinct. So, $K$ can grow up to $N+1$.
        *   Thus, each `insert` takes at most $O(\log (N+1))$ time.
        *   The total time for the loop is $N \times O(\log (N+1))$.
    *   Retrieving the size of the set: $O(1)$.
    *   Overall, the dominant factor is the loop, leading to a total time complexity of $O(N \log N)$. Given $N \le 100$, $N \log N$ is very small ($100 \times \log_2 100 \approx 100 \times 6.64 \approx 664$ operations), making this solution extremely efficient.

*   **Space Complexity**:
    *   Storing `N`, `X`, `current_position`: $O(1)$ space.
    *   Storing the input string `S`: $O(N)$ space.
    *   Storing `visited_points` (the `std::set`): In the worst case, all $N+1$ positions visited are distinct. Each integer takes constant space. Therefore, the set can store up to $N+1$ integers, leading to $O(N)$ space complexity for the set.
    *   Overall, the space complexity is $O(N)$ due to the string `S` and the `std::set`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, set, etc.

void solve() {
    int N;
    int X; // X can be up to 1,000,000 and N up to 100.
           // The maximum coordinate reached would be X + N (1,000,000 + 100 = 1,000,100)
           // The minimum coordinate reached would be X - N (-1,000,000 - 100 = -1,000,100)
           // Both these values fit comfortably within a standard 32-bit signed integer.
    std::cin >> N >> X;
    std::string S;
    std::cin >> S;

    // A std::set is used to store all unique coordinates visited by the robot.
    // It automatically handles duplicates, ensuring only distinct points are counted.
    std::set<int> visited_points;
    
    // The robot's initial position X is always considered visited.
    visited_points.insert(X);
    
    // current_position tracks the robot's current coordinate.
    int current_position = X;

    // Iterate through each command in the string S.
    for (char command : S) {
        if (command == 'L') {
            // Move one step to the left (decrease x by 1).
            current_position--;
        } else { // command == 'R'
            // Move one step to the right (increase x by 1).
            current_position++;
        }
        // After each command, the new position is visited. Add it to the set.
        visited_points.insert(current_position);
    }

    // The total number of distinct points visited is the size of the set.
    std::cout << visited_points.size() << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // T denotes the number of test cases.
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```