#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is requested
using namespace std;

void solve() {
    int X, A, B, C;
    cin >> X >> A >> B >> C; // Read X, A, B, C

    // Store prices in a vector to easily sort them
    vector<int> prices = {A, B, C};
    
    // Sort the prices in ascending order.
    // After sorting:
    // prices[0] will be the minimum price (let's call it P1).
    // prices[1] will be the second minimum price (let's call it P2).
    // prices[2] will be the maximum price (let's call it P3).
    sort(prices.begin(), prices.end());

    // The problem requires buying a total of X fruits and having at least 2 different kinds of fruits.
    // To minimize the total cost, we should always prioritize buying fruits with the lowest prices.
    //
    // To satisfy the "at least 2 different kinds" constraint with minimum cost, we must buy
    // at least one fruit of the cheapest kind (price P1) and at least one fruit of the
    // second cheapest kind (price P2).
    //
    // Strategy to achieve minimum cost:
    // 1. Buy one fruit of the second cheapest kind (price `prices[1]`).
    //    This ensures one of the two required distinct kinds is present.
    // 2. Buy the remaining `X-1` fruits of the cheapest kind (price `prices[0]`).
    //    Since `X >= 2`, `X-1 >= 1`, so this ensures at least one fruit of the cheapest kind
    //    is present.
    //
    // This strategy guarantees:
    // - A total of `(X-1) + 1 = X` fruits are bought.
    // - At least two different kinds of fruits are bought (one with price `prices[0]`, one with price `prices[1]`).
    //   The problem states "three different kinds of fruits with prices A, B and C", implying
    //   A, B, C refer to distinct types even if their prices are identical. So, picking
    //   the types corresponding to `prices[0]` and `prices[1]` satisfies the distinct kinds requirement.
    // - The cost is minimized because we are using the two cheapest prices, and for the bulk
    //   of fruits (`X-1`), we use the absolute cheapest price `prices[0]`.
    //
    // Total cost = (cost of X-1 fruits at P1) + (cost of 1 fruit at P2)
    //            = (X - 1) * prices[0] + prices[1]
    
    // Use long long for total_cost to prevent potential integer overflow,
    // although for the given constraints (X <= 1000, prices <= 100),
    // the maximum cost (999 * 100 + 100 = 100000) would fit in a standard int.
    long long total_cost = (long long)(X - 1) * prices[0] + prices[1];
    
    // Output the calculated minimum cost, followed by a newline
    cout << total_cost << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}