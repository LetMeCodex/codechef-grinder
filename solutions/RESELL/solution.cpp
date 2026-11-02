#include <bits/stdc++.h> // Includes iostream, vector, algorithm, functional etc.

// It's generally good practice to avoid 'using namespace std;' in headers or large projects
// but for competitive programming, it's standard and accepted.
using namespace std; 

void solve() {
    int N, K;
    cin >> N >> K; // Read N (total items) and K (discounted items count)

    vector<int> A(N); // Declare a vector of size N to store item resell prices
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read each item's resell price
    }

    // Sort the array A in descending order.
    // This ensures that items with higher resell prices (A_i) are considered first.
    // std::greater<int>() is a comparator that makes std::sort sort in descending order.
    sort(A.begin(), A.end(), greater<int>());

    long long total_profit = 0; // Initialize total profit. Use long long to be safe, though int is sufficient here.

    // Chef can buy the first K items at a cost of 5 coins each.
    // These are the K items with the highest resell prices due to sorting.
    for (int i = 0; i < K; ++i) {
        // An item is bought only if it yields a positive profit.
        // Profit for these items is A[i] - 5.
        // If A[i] - 5 > 0 (i.e., A[i] > 5), Chef makes a profit.
        if (A[i] > 5) {
            total_profit += (A[i] - 5);
        }
    }

    // After the first K items, any subsequent items Chef buys will cost 10 coins each.
    // These are the remaining N-K items in the sorted array.
    for (int i = K; i < N; ++i) {
        // An item is bought only if it yields a positive profit.
        // Profit for these items is A[i] - 10.
        // If A[i] - 10 > 0 (i.e., A[i] > 10), Chef makes a profit.
        if (A[i] > 10) {
            total_profit += (A[i] - 10);
        }
    }

    // Output the maximum total profit for the current test case.
    cout << total_profit << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}