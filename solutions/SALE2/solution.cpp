#include <iostream> // Required for cin, cout
// For competitive programming, it's common to include <bits/stdc++.h>
// which includes most standard libraries.
#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: prefix
using namespace std;

// Function to solve a single test case
void solve() {
    int N, X;
    cin >> N >> X; // Read N (number of items) and X (cost per item)

    // Calculate the number of full "buy 2 get 1 free" cycles.
    // Each cycle gives 3 items for the price of 2.
    int num_full_cycles = N / 3;

    // Calculate the cost for these full cycles.
    // For each cycle, Chef pays for 2 items.
    // So, num_full_cycles * 2 items are paid for.
    // The total cost for these items is (num_full_cycles * 2) * X.
    // Using long long for total_cost to prevent potential overflow,
    // though for the given constraints (N, X <= 1000), int would suffice.
    long long total_cost = (long long)num_full_cycles * 2 * X;

    // Calculate the number of remaining items after full cycles.
    int remaining_items = N % 3;

    // For the remaining items, Chef has to pay for them individually.
    // If remaining_items is 1, Chef pays for 1 item.
    // If remaining_items is 2, Chef pays for 2 items.
    // This logic correctly finds the minimum cost for exactly 'remaining_items'.
    // If remaining_items is 2, paying for 2 items gives 2 items for 2*X.
    // Using the offer (pay for 2, get 1 free) would give 3 items for 2*X.
    // Both cost 2*X, but the latter gives more items. Since we need "at least N items",
    // both options are valid for the cost, and 2*X is the minimum.
    total_cost += (long long)remaining_items * X;

    // Output the minimum money required
    cout << total_cost << "\n";
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