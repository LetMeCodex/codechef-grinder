#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Use the standard namespace as requested.
using namespace std;

// The problem statement describes a single test case.
// The generic instruction "Handle multiple test cases (e.g. int t; cin >> t; while(t--))"
// is ignored because the problem statement itself does not specify 't' as input.
void solve() {
    int N;
    cin >> N; // Read the number of elements

    vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read array elements
    }

    vector<int> leaders; // Vector to store leader elements
    
    // Initialize current_max_from_right with the smallest possible integer value.
    // This ensures that the rightmost element (A[N-1]) will always be greater than it,
    // making it a leader as per the problem definition.
    int current_max_from_right = numeric_limits<int>::min();

    // Iterate through the array from right to left
    for (int i = N - 1; i >= 0; --i) {
        // An element A[i] is a leader if it is strictly greater than
        // all elements to its right. This is equivalent to A[i] being
        // strictly greater than the maximum element to its right.
        // 'current_max_from_right' stores the maximum element encountered so far
        // from the right side of the array (i.e., max(A[i+1], ..., A[N-1])).
        if (A[i] > current_max_from_right) {
            leaders.push_back(A[i]); // If A[i] is a leader, add it to the list
        }
        // Update 'current_max_from_right' to be the maximum of its current value
        // and the current element A[i]. This prepares it for the next iteration (i-1).
        current_max_from_right = max(current_max_from_right, A[i]);
    }

    // The leaders were collected in reverse order of their appearance in the input array.
    // The problem requires printing them in their original relative order (left to right).
    reverse(leaders.begin(), leaders.end());

    // Print the leaders, separated by spaces
    for (size_t i = 0; i < leaders.size(); ++i) {
        cout << leaders[i] << (i == leaders.size() - 1 ? "" : " ");
    }
    cout << "\n"; // Print a newline character at the end
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Call the solve function for the single test case.
    solve();

    return 0; // Indicate successful execution
}