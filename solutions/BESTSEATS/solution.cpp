#include <bits/stdc++.h> // Includes most standard libraries

// Using namespace std; is common in competitive programming to avoid typing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of seats in the row

    // Create a vector to store the costs of the seats.
    // N is small (up to 100), so a vector is efficient enough.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read the cost of each seat
    }

    // Initialize min_cost with the cost of the first possible pair of adjacent seats.
    // Since N is guaranteed to be at least 2, seats A[0] and A[1] always exist.
    int min_cost = A[0] + A[1];

    // Iterate through all other possible pairs of adjacent seats.
    // A pair consists of seats at index i and i+1.
    // The loop starts from i = 1 because the pair (A[0], A[1]) has already been considered.
    // It goes up to N-2 (inclusive), meaning the last pair considered will be (A[N-2], A[N-1]).
    for (int i = 1; i < N - 1; ++i) {
        int current_cost = A[i] + A[i+1]; // Calculate the cost of the current adjacent pair
        // Update min_cost if the current pair's cost is lower than the minimum found so far.
        min_cost = min(min_cost, current_cost);
    }

    // Output the minimum cost found for this test case, followed by a newline.
    cout << min_cost << "\n";
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