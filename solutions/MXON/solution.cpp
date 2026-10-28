#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Not strictly needed, but good practice for competitive programming

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;

    int current_ones = 0;
    int last_one_idx = -1;

    // Count initial ones and find the rightmost '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            current_ones++;
            last_one_idx = i;
        }
    }

    // If there are no '1's initially, no '0' can ever become '1'.
    // The count of '1's remains 0.
    if (last_one_idx == -1) {
        std::cout << 0 << "\n";
        return;
    }

    // Apply operations greedily from right to left, starting from the position
    // just to the left of the rightmost '1'.
    // The logic is that a '1' at S[i+1] can turn S[i] into '1'.
    // If S[i] becomes '1', it can then be used to turn S[i-1] into '1', and so on.
    // By iterating from right to left, we ensure that S[i+1] is already in its
    // final (or current '1') state when we consider S[i].
    for (int i = last_one_idx - 1; i >= 0; --i) {
        if (K == 0) {
            break; // No more operations left
        }
        
        // If S[i] is '0', we can turn it into '1' using S[i+1] (which is either
        // an original '1' or was just turned into '1' in the previous iteration).
        if (S[i] == '0') {
            current_ones++; // Increment the count of '1's
            K--;            // Use one operation
            // Conceptually, S[i] is now '1'. This allows S[i-1] to potentially become '1'.
            // The loop naturally handles this by moving to i-1.
        }
        // If S[i] is already '1', we don't need to do anything for this position.
    }

    std::cout << current_ones << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}