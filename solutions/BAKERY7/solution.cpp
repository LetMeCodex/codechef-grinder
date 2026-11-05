#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

using namespace std; // Allows using standard library components without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin/cout from C's stdio, and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store input N (number of cakes) and K (bribe amount).
    // Given constraints (N <= 10, K <= 1000), int is sufficient for all calculations.
    int N, K;

    // Read N and K from standard input.
    cin >> N >> K;

    // Calculate the total cost if we choose NOT to bribe Chef's son.
    // In this scenario, each cake costs 100 rupees.
    int cost_no_bribe = N * 100;

    // Calculate the total cost if we choose to bribe Chef's son.
    // We pay K rupees once for the bribe, and then each cake costs 60 rupees.
    int cost_with_bribe = K + (N * 60);

    // The minimum cost is the smaller of the two calculated options.
    int min_total_cost = min(cost_no_bribe, cost_with_bribe);

    // Output the minimum total cost followed by a newline character.
    cout << min_total_cost << "\n";

    return 0; // Indicate successful program execution.
}