#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, algorithm, etc.

// Required using namespace std;
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of mountains

    // Initialize max_height. Since mountain heights are non-negative (0 to 10^9),
    // initializing with 0 is safe. Any valid height will be >= 0.
    // If heights could be negative, it would be safer to initialize with
    // numeric_limits<int>::min() or the first element.
    int max_height = 0; 

    // Loop N times to read each mountain's height
    for (int i = 0; i < N; ++i) {
        int height;
        cin >> height; // Read the current mountain's height

        // Update max_height if the current mountain is taller
        if (height > max_height) {
            max_height = height;
        }
        // Alternatively, using std::max from <algorithm> (included by <bits/stdc++.h>):
        // max_height = max(max_height, height);
    }

    // Output the height of the tallest mountain for this test case
    cout << max_height << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}