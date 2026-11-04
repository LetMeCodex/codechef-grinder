#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the total number of legs

    // Calculate the maximum number of cows.
    // Each cow has 4 legs. Integer division N / 4 gives the maximum whole cows.
    int num_cows = N / 4;

    // Calculate the remaining legs after accounting for cows.
    // Since N is even, N % 4 will either be 0 or 2.
    // If N % 4 is 0, no legs remain, so 0 chickens.
    // If N % 4 is 2, 2 legs remain, which must come from 1 chicken.
    int remaining_legs = N % 4;
    
    // Each chicken has 2 legs.
    // remaining_legs / 2 will correctly give 0 chickens if remaining_legs is 0,
    // and 1 chicken if remaining_legs is 2.
    int num_chickens = remaining_legs / 2;

    // The total minimum number of animals is the sum of cows and chickens.
    int total_animals = num_cows + num_chickens;

    cout << total_animals << "\n"; // Output the result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}