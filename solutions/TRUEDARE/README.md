# [Truth and Dare (TRUEDARE)](https://www.codechef.com/problems/TRUEDARE)
- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game of Truth and Dare between Ram and Shyam. Ram has a list of truth tasks and a list of dare tasks that he is capable of performing. Shyam then proposes a list of truth tasks and a list of dare tasks. Ram wins the game if he can perform *all* the truth tasks proposed by Shyam AND *all* the dare tasks proposed by Shyam. If even a single task proposed by Shyam cannot be performed by Ram, then Ram loses. We need to determine if Ram wins ("yes") or loses ("no") for multiple test cases. The task IDs are integers between 1 and 100.

## Intuition & Mathematical Observation

The core of the problem is to efficiently check if Ram can perform a given task. Since task IDs are small (1 to 100), we can use a simple and effective data structure: boolean arrays (or `std::vector<bool>` in C++).

1.  **Representing Ram's Capabilities**: We can use two boolean arrays, say `ram_can_do_truth` and `ram_can_do_dare`, both of size 101 (to cover task IDs from 1 to 100, using 1-based indexing).
    *   Initialize all entries in both arrays to `false`.
    *   When we read a truth task `T` that Ram can perform, we set `ram_can_do_truth[T] = true`.
    *   Similarly, for a dare task `D`, we set `ram_can_do_dare[D] = true`.

2.  **Checking Shyam's Proposals**:
    *   Initialize a boolean flag, `ram_wins`, to `true`. This flag will track if Ram is currently winning.
    *   Iterate through each truth task `TS` proposed by Shyam. For each `TS`, check `ram_can_do_truth[TS]`. If `ram_can_do_truth[TS]` is `false`, it means Ram cannot perform this task. In this case, Ram loses, so we set `ram_wins = false`.
    *   Similarly, iterate through each dare task `DS` proposed by Shyam. For each `DS`, check `ram_can_do_dare[DS]`. If `ram_can_do_dare[DS]` is `false`, Ram loses, so we set `ram_wins = false`.
    *   It's important to continue reading all of Shyam's tasks even if `ram_wins` becomes `false` early, to ensure the input stream is correctly positioned for the next test case. We only need to update `ram_wins` if it's still `true` and a task cannot be performed.

3.  **Final Result**: After checking all of Shyam's proposed tasks, if `ram_wins` is still `true`, Ram wins, and we print "yes". Otherwise, Ram loses, and we print "no".

This approach works because checking an element in a boolean array is an $O(1)$ operation, making the overall process very efficient.

## Complexity Analysis

Let $T$ be the number of test cases.
Let $TR_C, DR_C$ be the number of truth and dare tasks Ram can perform, respectively.
Let $TS_C, DS_C$ be the number of truth and dare tasks Shyam proposes, respectively.
According to the problem constraints, $TR_C, DR_C, TS_C, DS_C$ are all between 1 and 100. Task IDs are also between 1 and 100.

-   **Time Complexity**:
    For each test case:
    *   Initializing two `vector<bool>` of size 101: $O(101)$, which is $O(1)$ as 101 is a constant.
    *   Reading Ram's $TR_C$ truth tasks and marking them: $O(TR_C)$ operations. Since $TR_C \le 100$, this is $O(100)$.
    *   Reading Ram's $DR_C$ dare tasks and marking them: $O(DR_C)$ operations. Since $DR_C \le 100$, this is $O(100)$.
    *   Reading Shyam's $TS_C$ truth tasks and checking them: $O(TS_C)$ operations. Since $TS_C \le 100$, this is $O(100)$.
    *   Reading Shyam's $DS_C$ dare tasks and checking them: $O(DS_C)$ operations. Since $DS_C \le 100$, this is $O(100)$.
    The total time for one test case is $O(101 + TR_C + DR_C + TS_C + DS_C)$, which simplifies to $O(1)$ because all counts are bounded by small constants.
    Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$.

-   **Space Complexity**:
    For each test case:
    *   Two `vector<bool>` of size 101 (`ram_can_do_truth` and `ram_can_do_dare`). Each `vector<bool>` uses approximately 101 bits (or a few bytes) of memory.
    This memory usage is constant and does not depend on the input counts ($TR_C, DR_C, TS_C, DS_C$) or the number of test cases $T$.
    Therefore, the space complexity is $O(101)$, which simplifies to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested.
using namespace std;     // Uses the standard namespace, as requested.

// Function to solve a single test case
void solve() {
    // Use boolean vectors to keep track of tasks Ram can perform.
    // Size 101 to cover task IDs from 1 to 100 (index 0 is unused).
    // Initialize all entries to false.
    vector<bool> ram_can_do_truth(101, false);
    vector<bool> ram_can_do_dare(101, false);

    // Read Ram's truth tasks
    int tr_count;
    cin >> tr_count;
    for (int i = 0; i < tr_count; ++i) {
        int task_id;
        cin >> task_id;
        ram_can_do_truth[task_id] = true; // Mark this truth task as performable by Ram
    }

    // Read Ram's dare tasks
    int dr_count;
    cin >> dr_count;
    for (int i = 0; i < dr_count; ++i) {
        int task_id;
        cin >> task_id;
        ram_can_do_dare[task_id] = true; // Mark this dare task as performable by Ram
    }

    // Flag to track if Ram wins. Assume Ram wins initially.
    bool ram_wins = true;

    // Read Shyam's truth tasks and check if Ram can perform them
    int ts_count;
    cin >> ts_count;
    for (int i = 0; i < ts_count; ++i) {
        int task_id;
        cin >> task_id;
        // If Ram is currently winning and cannot perform this truth task,
        // then Ram loses. Set ram_wins to false.
        // We continue reading input for the current test case even if Ram loses,
        // to ensure the input stream is correctly positioned for the next test case.
        if (ram_wins && !ram_can_do_truth[task_id]) {
            ram_wins = false;
        }
    }

    // Read Shyam's dare tasks and check if Ram can perform them
    int ds_count;
    cin >> ds_count;
    for (int i = 0; i < ds_count; ++i) {
        int task_id;
        cin >> task_id;
        // Similar logic for dare tasks.
        if (ram_wins && !ram_can_do_dare[task_id]) {
            ram_wins = false;
        }
    }

    // Output the result for the current test case
    if (ram_wins) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) { // Loop through each test case
        solve();
    }

    return 0; // Indicate successful execution
}
```