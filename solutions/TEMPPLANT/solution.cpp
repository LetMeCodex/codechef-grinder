#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of days

    // Create a vector to store the temperatures
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read each temperature
    }

    // Initialize max_height to 0. Since all temperatures A_i >= 1,
    // any valid tree height will be at least 1, so 0 is a safe initial minimum.
    int max_height = 0;

    // Iterate through all possible planting days.
    // If planted on day i (0-indexed), it grows on day i and day i+1.
    // The first day to plant is 0 (using A[0] and A[1]).
    // The last possible day to plant is N-2 (using A[N-2] and A[N-1]).
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the height if planted on day i
        int current_height = min(A[i], A[i+1]);
        
        // Update max_height if the current height is greater
        if (current_height > max_height) {
            max_height = current_height;
        }
        // Alternatively, using std::max: max_height = max(max_height, current_height);
    }

    // Output the maximum possible height for the current test case
    cout << max_height << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}