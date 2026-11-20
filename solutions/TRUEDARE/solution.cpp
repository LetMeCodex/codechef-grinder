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