#include <iostream> // Required for standard input/output operations (std::cin, std::cout)
// #include <vector>   // Not strictly necessary for this problem as we only iterate, but often useful
// #include <numeric>  // Not needed for this specific problem, but generally useful for competitive programming

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the permutation P

    int pos1 = -1; // Stores the 1-based index of element '1'
    int posN = -1; // Stores the 1-based index of element 'N'

    // Iterate through the permutation to find the positions of '1' and 'N'
    // The loop variable 'i' represents the 1-based index of the current element.
    for (int i = 1; i <= N; ++i) {
        int P_i;
        std::cin >> P_i; // Read the current element P_i
        if (P_i == 1) {
            pos1 = i; // If P_i is '1', record its index
        }
        if (P_i == N) {
            posN = i; // If P_i is 'N', record its index
        }
    }

    // Calculate the total number of operations
    // 'operations' is declared as long long to be safe, though int would suffice for N <= 10^5
    long long operations = 0;

    // Step 1: Calculate operations to move '1' to the first position (index 1).
    // If '1' is at pos1, it needs to move (pos1 - 1) steps to the left.
    operations += (pos1 - 1);

    // Step 2: Calculate operations to move 'N' to the last position (index N).
    // If 'N' is at posN, it needs to move (N - posN) steps to the right.
    operations += (N - posN);

    // Step 3: Adjust for the case where '1' is initially to the right of 'N'.
    // If pos1 > posN, it means '1' is to the right of 'N' in the initial permutation.
    // For '1' to move left and 'N' to move right to their target positions, they must
    // effectively "cross" each other. One adjacent swap operation can achieve
    // both moving '1' one step left AND moving 'N' one step right (if they are adjacent).
    // This means one operation is "saved" or "double-counted" in the sum of individual movements.
    // So, we subtract 1 from the total.
    if (pos1 > posN) {
        operations -= 1;
    }

    // Output the minimum number of operations for the current test case
    std::cout << operations << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations by disabling synchronization with C's stdio.
    // std::cin.tie(NULL) prevents std::cin from flushing std::cout before each input operation,
    // further improving I/O performance.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful program execution
}