#include <iostream> // For std::cin, std::cout

// No using namespace std; to be explicit.

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    long long current_sum = 0; // Use long long for safety, though int would suffice
    // Calculate the initial sum of the array
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        current_sum += val;
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int L, R;
        std::cin >> L >> R;
        
        // The total sum changes by +1 if L and R have the same parity.
        // L and R are 1-based indices.
        // (L % 2) == (R % 2) correctly checks if L and R have the same parity.
        // This is equivalent to (R - L + 1) being odd, meaning the alternating sum is +1.
        if ((L % 2) == (R % 2)) {
            current_sum++;
        }
    }

    std::cout << current_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}