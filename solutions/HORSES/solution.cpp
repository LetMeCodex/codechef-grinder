#include <bits/stdc++.h> // Includes iostream, vector, algorithm, climits etc.

using namespace std; // Use standard namespace for convenience

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of horses

    // Create a vector to store the skill levels of the horses
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i]; // Read each horse's skill
    }

    // Sort the skill levels in ascending order.
    // This is the key step for an efficient solution.
    // After sorting, the minimum difference between any two skills
    // must be found between adjacent elements.
    sort(S.begin(), S.end());

    // Initialize min_diff with a very large value.
    // INT_MAX is the maximum value an 'int' can hold, ensuring any valid
    // difference will be smaller.
    int min_diff = INT_MAX;

    // Iterate through the sorted array and find the minimum difference
    // between adjacent elements.
    // We only need to go up to N-1 because we access S[i+1].
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the difference between the current element and the next.
        // Since the array is sorted, S[i+1] will always be >= S[i],
        // so the difference S[i+1] - S[i] is non-negative.
        min_diff = min(min_diff, S[i+1] - S[i]);
    }

    // Output the minimum difference found for the current test case.
    cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}