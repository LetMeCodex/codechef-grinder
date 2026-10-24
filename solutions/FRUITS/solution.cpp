#include <bits/stdc++.h> // Includes most standard libraries like iostream, cmath, algorithm

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

void solve() {
    int N, M, K;
    // Read the number of apples (N), oranges (M), and gold coins (K) for the current test case.
    cin >> N >> M >> K;

    // Calculate the initial absolute difference between the number of apples and oranges.
    // Chef wants to minimize this difference.
    int initial_diff = abs(N - M);

    // Chef can spend K gold coins. Each coin can be used to buy one fruit.
    // To reduce the difference, Chef should always buy the fruit type that he has less of.
    // For example, if N > M, he should buy an orange. This increases M by 1, reducing N-M by 1.
    // If M > N, he should buy an apple. This increases N by 1, reducing M-N by 1.
    // In either case, each coin spent optimally reduces the absolute difference by 1.

    // Chef can reduce the difference by at most K.
    // So, the difference after spending K coins would ideally be initial_diff - K.

    // However, the difference cannot be negative. The minimum possible difference is 0.
    // If `initial_diff - K` results in a negative value, it means Chef has enough coins
    // (or more than enough) to make the number of apples and oranges equal.
    // In such a scenario, he can spend exactly `initial_diff` coins to equalize the counts
    // and achieve a difference of 0. He doesn't need to spend any remaining coins.
    // Therefore, the minimum possible difference is the maximum of 0 and `initial_diff - K`.
    
    int min_possible_diff = max(0, initial_diff - K);
    
    // Output the calculated minimum possible difference, followed by a newline.
    cout << min_possible_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard I/O.
    // `cin.tie(NULL)` prevents `cout` from flushing before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t;
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}