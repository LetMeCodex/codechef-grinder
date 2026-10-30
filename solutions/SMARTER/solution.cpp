#include <iostream> // Required for std::cin, std::cout
#include <cmath>    // Required for std::floor

// Function to solve a single test case
void solve() {
    long long L, V1, V2; // L, V1, V2 can be up to 1000. long long is used for safety, int would also suffice.
    std::cin >> L >> V1 >> V2;

    // 1. Calculate the tortoise's reported time.
    // The tortoise takes L/V1 seconds. This time is rounded up.
    // For positive integers A, B, ceil(A/B) can be calculated as (A + B - 1) / B using integer division.
    long long tortoise_reported_time = (L + V1 - 1) / V1;

    // 2. Determine the maximum integer 'W' (wait time) for the hare.
    // The winning condition is: Hare's reported time < Tortoise's reported time.
    // Let K = tortoise_reported_time.
    // Hare's actual running time = L/V2.
    // Hare's total actual time (waiting + running) = W + L/V2.
    // Hare's reported time = ceil(W + L/V2).
    //
    // So, the condition is: ceil(W + L/V2) < K.
    // Since reported times are integers, "strictly less than K" means "less than or equal to K-1".
    // Thus, ceil(W + L/V2) <= K - 1.
    //
    // For any real number X and integer Y, if ceil(X) <= Y, it implies X <= Y.
    // So, W + L/V2 <= K - 1.
    //
    // Rearranging to solve for W:
    // W <= K - 1 - L/V2.
    //
    // To find the maximum integer W that satisfies W <= some_value, we take floor(some_value).
    // Let's calculate 'some_value' using double-precision floating point numbers.
    double value_for_floor = static_cast<double>(tortoise_reported_time) - 1.0 - (static_cast<double>(L) / V2);

    // The maximum integer W is floor(value_for_floor).
    long long max_wait_time = static_cast<long long>(std::floor(value_for_floor));

    // 3. Output the result.
    // If the calculated max_wait_time is negative, it means even waiting 0 seconds
    // does not allow the hare to win. In this scenario, the problem asks to print -1.
    if (max_wait_time < 0) {
        std::cout << -1 << "\n";
    } else {
        std::cout << max_wait_time << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}