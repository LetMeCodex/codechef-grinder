#include <iostream> // For input/output operations
#include <string>   // For std::string

// It's generally good practice in competitive programming to avoid 'using namespace std;'
// to prevent potential name collisions, especially in larger projects or when including many headers.
// Instead, qualify standard library elements with 'std::'.

void solve() {
    long long N; // N can be up to 500, so 'int' would suffice, but 'long long' is harmless and safer for larger constraints.
    std::cin >> N;

    long long partner_berth_number;
    std::string partner_berth_type;

    // Calculate N modulo 8.
    // For N = 1, 2, ..., 7, N % 8 will be 1, 2, ..., 7 respectively.
    // For N = 8, 16, 24, ..., N % 8 will be 0.
    long long mod_N = N % 8;

    if (mod_N == 1) { // Current berth is 1LB (e.g., 1, 9, 17...)
        partner_berth_number = N + 3;
        partner_berth_type = "LB";
    } else if (mod_N == 2) { // Current berth is 2MB (e.g., 2, 10, 18...)
        partner_berth_number = N + 3;
        partner_berth_type = "MB";
    } else if (mod_N == 3) { // Current berth is 3UB (e.g., 3, 11, 19...)
        partner_berth_number = N + 3;
        partner_berth_type = "UB";
    } else if (mod_N == 4) { // Current berth is 4LB (e.g., 4, 12, 20...)
        partner_berth_number = N - 3;
        partner_berth_type = "LB";
    } else if (mod_N == 5) { // Current berth is 5MB (e.g., 5, 13, 21...)
        partner_berth_number = N - 3;
        partner_berth_type = "MB";
    } else if (mod_N == 6) { // Current berth is 6UB (e.g., 6, 14, 22...)
        partner_berth_number = N - 3;
        partner_berth_type = "UB";
    } else if (mod_N == 7) { // Current berth is 7SL (e.g., 7, 15, 23...)
        partner_berth_number = N + 1;
        partner_berth_type = "SU"; // Partner of 7SL is 8SU
    } else { // mod_N == 0, meaning N is a multiple of 8 (e.g., 8, 16, 24...)
             // Current berth is 8SU
        partner_berth_number = N - 1;
        partner_berth_type = "SL"; // Partner of 8SU is 7SL
    }

    std::cout << partner_berth_number << partner_berth_type << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();
    }
    return 0;
}