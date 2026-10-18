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