# [Cleaning Up (CLEANUP)](https://www.codechef.com/problems/CLEANUP)
- **Difficulty Rating**: 1309
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to manage a list of `N` jobs, numbered from 1 to `N`. We are given `M` jobs that have already been completed. Our task is to identify the remaining unfinished jobs and then assign them to two people: Chef and his Assistant.

The assignment rule is specific:
1.  First, collect all unfinished jobs and list them in increasing order of their job numbers.
2.  Chef takes the 1st, 3rd, 5th, ... job from this sorted list of unfinished jobs.
3.  The Assistant takes the 2nd, 4th, 6th, ... job from this sorted list.

Finally, we need to print two lines:
*   The first line should contain the job numbers assigned to the Chef, in increasing order, separated by spaces. If Chef gets no jobs, print "-1".
*   The second line should contain the job numbers assigned to the Assistant, in increasing order, separated by spaces. If Assistant gets no jobs, print "-1".

This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

1.  **Tracking Completed Jobs**: Since `N` can be up to 1000, a boolean array `is_completed` of size `N+1` (for 1-indexed jobs) is an efficient way to keep track of which jobs are done. We can initialize all entries to `false` and then mark `true` for the `M` completed jobs. This allows $O(1)$ lookup for any job's status.

2.  **Finding Unfinished Jobs**: After marking all completed jobs, we can iterate from `i = 1` to `N`. If `is_completed[i]` is `false`, then job `i` is unfinished. We collect these jobs into a `std::vector`. By iterating from 1 to `N`, the jobs will naturally be added to the vector in increasing order, satisfying the problem's requirement.

3.  **Assigning Jobs Alternately**: Once we have the `std::vector` of `unfinished_jobs` (let's say `U`), we need to distribute them.
    *   The "1st, 3rd, 5th, ..." job in the list `U` corresponds to `U[0]`, `U[2]`, `U[4]`, ... if we use 0-indexed access for the vector. These are jobs at **even indices**.
    *   The "2nd, 4th, 6th, ..." job in the list `U` corresponds to `U[1]`, `U[3]`, `U[5]`, ... if we use 0-indexed access for the vector. These are jobs at **odd indices**.
    So, we can iterate through the `unfinished_jobs` vector and, based on the current index `i`, assign `unfinished_jobs[i]` to Chef if `i % 2 == 0` or to Assistant if `i % 2 == 1`.

4.  **Handling Empty Lists**: The problem specifies printing "-1" if a person gets no jobs. Our `print_jobs` helper function checks if the input vector is empty and prints "-1" accordingly, otherwise it prints the elements separated by spaces.

This approach is straightforward and efficient given the constraints.

## Complexity Analysis

Let `N` be the total number of jobs and `M` be the number of completed jobs.

*   **Time Complexity**:
    *   **Initialization**: `memset(is_completed, ...)` takes $O(N)$ time to reset the boolean array for each test case.
    *   **Reading Completed Jobs**: Reading `M` job indices and marking them in `is_completed` takes $O(M)$ time.
    *   **Finding Unfinished Jobs**: Iterating from 1 to `N` to populate the `unfinished_jobs` vector takes $O(N)$ time.
    *   **Assigning Jobs**: Iterating through the `unfinished_jobs` vector (which has at most `N` elements) to assign them to Chef and Assistant takes $O(N-M)$ time, which is $O(N)$ in the worst case.
    *   **Printing Jobs**: Printing the jobs for Chef and Assistant takes $O(N)$ time in total (as the total number of jobs is at most `N`).
    *   **Total per Test Case**: Summing these up, the time complexity for one test case is $O(N + M + N + N + N) = O(N+M)$. Since $M \le N$, this simplifies to $O(N)$.
    *   **Overall**: With `T` test cases, the total time complexity is $O(T \cdot N)$. Given $T=100$ and $N=1000$, $T \cdot N = 10^5$, which is well within typical time limits.

*   **Space Complexity**:
    *   **`is_completed` array**: This boolean array stores `N+1` values, so it requires $O(N)$ space.
    *   **`unfinished_jobs` vector**: In the worst case (if `M=0`), this vector can store `N` job indices, requiring $O(N)$ space.
    *   **`chef_jobs` and `assistant_jobs` vectors**: In total, these two vectors store all `N-M` unfinished jobs, requiring $O(N)$ space.
    *   **Total**: The dominant factor is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <cstring>  // Required for memset

// It's common practice in competitive programming to include <bits/stdc++.h>
// and use the entire std namespace to save time.
// For this problem, iostream, vector, and cstring are sufficient.
// #include <bits/stdc++.h> 
using namespace std;

// Global array to keep track of completed jobs.
// Max N is 1000, so an array of size 1001 (for 1-indexed jobs up to 1000) is safe.
// Declaring it globally ensures it's zero-initialized (false for bool) by default,
// but we explicitly use memset for clarity and to reset for each test case.
bool is_completed[1001]; 

// Helper function to print a vector of job indices.
// It handles the case where the vector is empty by printing "-1".
void print_jobs(const vector<int>& jobs) {
    if (jobs.empty()) {
        cout << "-1\n";
    } else {
        // Iterate through the jobs and print them, separated by spaces.
        // No trailing space after the last job.
        for (size_t i = 0; i < jobs.size(); ++i) {
            cout << jobs[i] << (i == jobs.size() - 1 ? "" : " ");
        }
        cout << "\n"; // Newline after each list of jobs.
    }
}

// Function to solve a single test case.
void solve() {
    int n, m;
    cin >> n >> m;

    // Reset the is_completed array for the current test case.
    // All jobs are initially considered not completed (false).
    // memset is efficient for setting a block of memory to a specific value.
    // For boolean arrays, false corresponds to 0.
    memset(is_completed, false, sizeof(is_completed));

    // Read the m completed jobs and mark their indices as true in the array.
    for (int i = 0; i < m; ++i) {
        int job_idx;
        cin >> job_idx;
        is_completed[job_idx] = true;
    }

    // Collect all unfinished jobs.
    // Since we iterate from 1 to n, the jobs will be added to 'unfinished_jobs'
    // in increasing order of their indices.
    vector<int> unfinished_jobs;
    for (int i = 1; i <= n; ++i) {
        if (!is_completed[i]) {
            unfinished_jobs.push_back(i);
        }
    }

    // Divide the unfinished jobs between the Chef and the Assistant.
    // The problem states: Chef takes the 1st, 3rd, 5th, ... job in the list.
    // Assistant takes the 2nd, 4th, 6th, ... job in the list.
    // Using 0-indexed positions for the 'unfinished_jobs' vector:
    // Chef takes jobs at indices 0, 2, 4, ... (even indices)
    // Assistant takes jobs at indices 1, 3, 5, ... (odd indices)
    vector<int> chef_jobs;
    vector<int> assistant_jobs;

    for (size_t i = 0; i < unfinished_jobs.size(); ++i) {
        if (i % 2 == 0) { // If the 0-indexed position is even, it's for the Chef
            chef_jobs.push_back(unfinished_jobs[i]);
        } else { // If the 0-indexed position is odd, it's for the Assistant
            assistant_jobs.push_back(unfinished_jobs[i]);
        }
    }

    // Print the jobs assigned to the Chef, followed by the jobs assigned to the Assistant.
    print_jobs(chef_jobs);
    print_jobs(assistant_jobs);
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is crucial in competitive programming for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}
```