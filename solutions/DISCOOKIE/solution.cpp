#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// It's common practice in competitive programming to use the entire std namespace
// to avoid prefixing std:: to every standard library element.
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, M; // N: number of kids, M: initial number of cookies
    cin >> N >> M;

    // Calculate the remainder when M is divided by N.
    // This tells us how many cookies are "left over" if we try to distribute M cookies
    // as evenly as possible without making/destroying.
    long long rem = M % N;

    // If the remainder is 0, M is already a multiple of N.
    // Since M >= 1 and N >= 1 (from constraints), M/N will be an integer and M/N >= 1,
    // so each kid can get M/N cookies.
    // No changes needed, so time taken is 0.
    if (rem == 0) {
        cout << 0 << "\n";
    } else {
        // If rem != 0, M is not a multiple of N. We need to change M.
        // We have two main options to reach a total number of cookies M' that is a multiple of N:

        // Option 1: Increase cookies to the next multiple of N.
        // The current M is (M/N)*N + rem.
        // The next multiple of N is (M/N + 1)*N.
        // The number of cookies per kid would be (M/N + 1). This is always >= 1
        // because M/N is at least 0 (since M, N >= 1), so M/N + 1 is at least 1.
        // The cost for this option is (M/N + 1)*N - M = N - rem.
        long long cost_to_increase = N - rem;

        // Option 2: Decrease cookies to the previous multiple of N.
        // The previous multiple of N is (M/N)*N.
        // The number of cookies per kid would be (M/N).
        // The cost for this option is M - (M/N)*N = rem.
        // This option is only valid if (M/N) >= 1, meaning each kid gets at least 1 cookie.
        // If M < N, then M/N is 0, which means 0 cookies per kid, which is not allowed.

        // Check if decreasing cookies is a valid option (i.e., M/N >= 1).
        // This is equivalent to checking if M >= N.
        if (M >= N) {
            // Both options are valid. We choose the one with minimum cost.
            long long cost_to_decrease = rem;
            cout << min(cost_to_increase, cost_to_decrease) << "\n";
        } else {
            // M < N, so M/N is 0. Decreasing cookies to 0 is not allowed.
            // Only the option to increase cookies is valid.
            // In this case, M/N is 0, so (M/N + 1)*N = N.
            // The cost is N - M (which is N - rem, since rem = M when M < N).
            cout << cost_to_increase << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}