#include <iostream>
#include <algorithm> // Required for std::max
#include <cstring>   // Required for strcmp

void solve() {
    int n;
    std::cin >> n;
    int count_A = 0;
    int count_B = 0;
    int count_O = 0;
    int count_AB = 0;

    // Use char array for faster string input and comparison
    char blood_type_arr[3]; // Max "AB" + null terminator

    for (int i = 0; i < n; ++i) {
        std::cin >> blood_type_arr; // Reads into char array
        if (strcmp(blood_type_arr, "A") == 0) {
            count_A++;
        } else if (strcmp(blood_type_arr, "B") == 0) {
            count_B++;
        } else if (strcmp(blood_type_arr, "O") == 0) {
            count_O++;
        } else if (strcmp(blood_type_arr, "AB") == 0) {
            count_AB++;
        }
    }

    // The maximum number of people in a chain is formed by:
    // 1. All 'O' type people (universal donors).
    // 2. The maximum of 'A' people or 'B' people, as 'A' and 'B' cannot donate to each other.
    // 3. All 'AB' type people (universal recipients, but can only donate to 'AB').
    int max_chain_length = count_O + std::max(count_A, count_B) + count_AB;
    
    std::cout << max_chain_length << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}