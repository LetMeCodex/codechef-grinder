#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm, etc.

// Using namespace std; is requested by the problem statement for competitive programming contexts.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the total number of ingredients

    // Create a vector to store the required amounts of each ingredient (A_i)
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read A_i for each ingredient
    }

    // Create a vector to store the currently available amounts of each ingredient (B_i)
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i]; // Read B_i for each ingredient
    }

    // Initialize total_cost to 0. Using long long to be safe, though int would suffice given constraints.
    long long total_cost = 0;

    // Iterate through each ingredient to calculate the cost
    for (int i = 0; i < N; ++i) {
        // For each ingredient i, calculate the amount needed:
        // If A[i] (required) is greater than B[i] (available), Chef needs to buy A[i] - B[i] units.
        // Otherwise (if A[i] <= B[i]), Chef has enough or more, so 0 units need to be bought.
        // Since each unit costs 1 coin, the cost for this ingredient is simply the amount to buy.
        total_cost += max(0, A[i] - B[i]);
    }

    // Output the total cost for the current test case, followed by a newline
    cout << total_cost << "\n";
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

    return 0; // Indicate successful program execution
}