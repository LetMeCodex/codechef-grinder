#include <bits/stdc++.h> // Includes iostream, algorithm, climits, etc. for convenience

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the number of elements

    long long min_val, max_val; // Variables to store the minimum and maximum values found

    // Read the first element and initialize min_val and max_val with it.
    // This is safe because N >= 3, so there's always at least one element.
    long long first_A;
    cin >> first_A;
    min_val = first_A;
    max_val = first_A;

    // Iterate through the remaining N-1 elements
    for (int i = 1; i < n; ++i) {
        long long current_A;
        cin >> current_A; // Read the current element
        
        // Update min_val and max_val using std::min and std::max
        min_val = min(min_val, current_A);
        max_val = max(max_val, current_A);
    }

    // The problem asks to maximize |Ax-Ay| + |Ay-Az| + |Az-Ax|.
    // For any three numbers a, b, c, this expression is equivalent to
    // 2 * (max(a,b,c) - min(a,b,c)).
    // To maximize this, we need to pick three numbers from the sequence A
    // such that their maximum is as large as possible and their minimum is as small as possible.
    // This means we should pick the overall maximum element from A (max_val)
    // and the overall minimum element from A (min_val).
    // Since N >= 3, we can always pick a third distinct element.
    // The minimum of these three chosen elements will be min_val, and the maximum will be max_val.
    // Thus, the maximum possible value of the expression is 2 * (max_val - min_val).
    long long result = 2 * (max_val - min_val);
    
    cout << result << "\n"; // Print the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}