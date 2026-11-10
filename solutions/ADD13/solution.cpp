#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid prefixing std:: to standard library components
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, M; // Declare N and M as long long to handle values up to 10^9.
                    // This is crucial because 3 * N can be up to 3 * 10^9,
                    // which exceeds the typical 2 * 10^9 limit of a 32-bit signed integer.
    cin >> N >> M; // Read the number of turns (N) and the target final value (M)

    // Let 'k' be the number of times we choose to add 3.
    // Since there are N turns in total, the number of times we add 1 must be (N - k).
    // The total sum X will be:
    // X = (k * 3) + ((N - k) * 1)
    // X = 3k + N - k
    // X = 2k + N

    // We are checking if it's possible for the final value X to be M.
    // So, we need to find if there exists an integer 'k' such that:
    // M = 2k + N

    // From this equation, we can derive 'k':
    // M - N = 2k
    // k = (M - N) / 2

    // For 'M' to be achievable, 'k' must satisfy three conditions:

    // Condition 1: 'k' must be a non-negative number of turns.
    // This means k >= 0.
    // (M - N) / 2 >= 0  =>  M - N >= 0  =>  M >= N.
    // The minimum possible sum is N (achieved by adding 1 in all N turns).
    // If M is less than N, it's impossible.
    if (M < N) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // Condition 2: 'k' cannot exceed the total number of turns N.
    // This means k <= N.
    // (M - N) / 2 <= N  =>  M - N <= 2N  =>  M <= 3N.
    // The maximum possible sum is 3N (achieved by adding 3 in all N turns).
    // If M is greater than 3N, it's impossible.
    if (M > 3 * N) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // Condition 3: 'k' must be an integer.
    // This means (M - N) must be an even number, so (M - N) % 2 must be 0.
    // This is equivalent to M and N having the same parity (both even or both odd).
    if ((M - N) % 2 != 0) {
        cout << "NO\n";
        return; // Exit the function for this test case
    }

    // If all three conditions are met, it is possible to form M.
    cout << "YES\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input
    while (T--) { // Loop T times, processing one test case in each iteration
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}