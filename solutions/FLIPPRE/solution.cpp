#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common for competitive programming

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    int balance = 0;
    int zero_balance_prefix_count = 0;

    // Iterate through the string to calculate prefix balances
    // S[i] corresponds to S_{i+1} in 1-based indexing for prefixes
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            balance++;
        } else { // S[i] == '1'
            balance--;
        }
        
        // If the balance is zero, it means the prefix S[0...i] (length i+1)
        // has an equal number of 0s and 1s.
        if (balance == 0) {
            zero_balance_prefix_count++;
        }
    }

    // The number of distinct strings is 2 raised to the power of 
    // the number of prefixes with equal 0s and 1s.
    // Use long long for the result because N can be up to 60,
    // so zero_balance_prefix_count can be up to 30 (e.g., for "0101...").
    // 2^30 is 1,073,741,824, which fits in a long long.
    long long result = 1LL << zero_balance_prefix_count;
    
    std::cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}