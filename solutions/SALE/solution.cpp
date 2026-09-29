#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    // Calculate the sum of all prices
    int total_sum = A + B + C;

    // Find the minimum price among A, B, C.
    // std::min can take an initializer list in C++11 and later,
    // which is convenient for finding the minimum of multiple values.
    int min_price = min({A, B, C});
    
    // The amount Chef needs to pay is the total sum of prices
    // minus the price of the lowest-cost item (which is free).
    int amount_to_pay = total_sum - min_price;

    cout << amount_to_pay << "\n";
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0;
}