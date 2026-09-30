#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array
    int current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read each element
        current_sum += val; // Add it to the total sum
    }

    // The core logic:
    // Each operation (flipping 1 to -1 or -1 to 1) changes the sum by exactly 2.
    // For example, 1 becomes -1: sum changes by -2.
    // -1 becomes 1: sum changes by +2.
    // This means the parity of the sum never changes.
    // If the initial sum is odd, it's impossible to make it 0 (which is even).
    if (current_sum % 2 != 0) {
        cout << -1 << "\n";
    } else {
        // If the initial sum is even, we need to change it to 0.
        // The total change required is |current_sum|.
        // Since each operation changes the sum by 2, the minimum number of operations
        // is |current_sum| / 2.
        cout << abs(current_sum) / 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}