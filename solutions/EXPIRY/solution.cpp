#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

using namespace std; // Allows using standard library elements like cin, cout without the std:: prefix

// Function to solve a single test case
void solve() {
    int N, M, K;
    // Read the number of loaves (N), days to expiry (M), and loaves per day (K)
    cin >> N >> M >> K;

    // Calculate the maximum total loaves Eikooc can eat within M days.
    // She eats up to K loaves per day for M days.
    int max_eatable_loaves = M * K;

    // Compare the total loaves Eikooc has (N) with the maximum she can eat.
    // If N is less than or equal to max_eatable_loaves, she can eat all bread.
    if (N <= max_eatable_loaves) {
        cout << "Yes\n"; // Output "Yes" followed by a newline
    } else {
        // Otherwise, she cannot eat all bread before it expires.
        cout << "No\n"; // Output "No" followed by a newline
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}