#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int W, P, K;
    cin >> W >> P >> K; // Read input using cin

    // To maximize stylishness, Chef should prioritize buying wooden chairs
    // because each wooden chair increases stylishness by 2,
    // while each plastic chair increases stylishness by 1.

    // Determine the number of wooden chairs to buy.
    // This is limited by two factors:
    // 1. The total number of wooden chairs available (W).
    // 2. The total number of chairs Chef wants to buy (K).
    // So, Chef can buy at most min(W, K) wooden chairs.
    int num_wooden_chairs = min(W, K); // std::min is now min due to using namespace std;

    // The remaining chairs must be plastic chairs to reach the total of K chairs.
    // The number of plastic chairs needed is K - num_wooden_chairs.
    int num_plastic_chairs = K - num_wooden_chairs;

    // It's guaranteed that K <= W + P. This constraint ensures that:
    // 1. If K <= W: num_wooden_chairs = K. num_plastic_chairs = K - K = 0.
    //    Since P >= 1 (from constraints), 0 <= P is always true.
    // 2. If K > W: num_wooden_chairs = W. num_plastic_chairs = K - W.
    //    The guarantee K <= W + P implies K - W <= P. So, num_plastic_chairs will not exceed P.
    // Therefore, we don't need to explicitly check if num_plastic_chairs > P
    // or adjust num_wooden_chairs downwards. The greedy choice of maximizing
    // wooden chairs first, up to min(W, K), is always valid and optimal.

    // Calculate the total stylishness.
    // Wooden chairs contribute 2 stylishness each, plastic chairs contribute 1 each.
    int total_stylishness = (num_wooden_chairs * 2) + (num_plastic_chairs * 1);

    cout << total_stylishness << "\n"; // Output using cout
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}