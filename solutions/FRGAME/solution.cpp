#include <iostream> // Required for standard input/output operations (cin, cout)

// Function to solve a single test case
void solve() {
    int A, B, C, D;
    // Read the initial number of coins for Nitin (A) and Sobhagya (B),
    // and the coins Ritik (C) and Satyarth (D) will give.
    std::cin >> A >> B >> C >> D;

    // --- Ritik's turn ---
    // Determine who is currently winning based on A and B.
    // Sobhagya wins if B > A. Nitin wins if A >= B.
    // Ritik gives C coins to the player who is NOT winning.
    if (B > A) {
        // Sobhagya is winning, so Nitin is not winning.
        // Nitin receives C coins.
        A += C;
    } else {
        // Nitin is winning (A >= B), so Sobhagya is not winning.
        // Sobhagya receives C coins.
        B += C;
    }

    // --- Satyarth's turn ---
    // Determine who is currently winning based on the UPDATED A and B.
    // Satyarth gives D coins to the player who is NOT winning.
    if (B > A) {
        // Sobhagya is currently winning, so Nitin is not winning.
        // Nitin receives D coins.
        A += D;
    } else {
        // Nitin is currently winning (A >= B), so Sobhagya is not winning.
        // Sobhagya receives D coins.
        B += D;
    }

    // --- Determine the final winner ---
    // After both Ritik and Satyarth have given their coins,
    // check the final coin counts.
    if (B > A) {
        // Sobhagya has more coins, so Sobhagya is the final winner.
        std::cout << "S\n";
    } else {
        // Nitin has more or equal coins, so Nitin is the final winner.
        std::cout << "N\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases.
    std::cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}