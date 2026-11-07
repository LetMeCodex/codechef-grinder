#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this problem, but common in competitive programming

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    int possible_max_count = 0;

    // Case 1: A_1 can be the maximum
    // This is possible if A_1 > A_2, which means S_1 = '1'.
    // In 0-indexed string S, S_1 corresponds to S[0].
    if (S[0] == '1') {
        possible_max_count++;
    }

    // Case 2: A_N can be the maximum
    // This is possible if A_{N-1} < A_N, which means S_{N-1} = '0'.
    // In 0-indexed string S, S_{N-1} corresponds to S[N-2].
    // Note: N-2 is a valid index because N >= 2, so N-1 >= 1, and string length is N-1.
    if (S[N - 2] == '0') {
        possible_max_count++;
    }

    // Case 3: A_i can be the maximum for 1 < i < N (i.e., i from 2 to N-1)
    // This is possible if A_{i-1} < A_i AND A_i > A_{i+1}.
    // In terms of S, this means S_{i-1} = '0' AND S_i = '1'.
    // In 0-indexed string S:
    // S_{i-1} corresponds to S[i-2]
    // S_i corresponds to S[i-1]
    // The loop for array index 'i' goes from 2 up to N-1.
    // The corresponding string indices S[i-2] and S[i-1] will be valid.
    // For i=2, we check S[0] and S[1].
    // For i=N-1, we check S[N-3] and S[N-2].
    // This loop runs for N >= 3. If N=2, the loop range (2 to 1) is empty, which is correct.
    for (int i = 2; i < N; ++i) {
        if (S[i - 2] == '0' && S[i - 1] == '1') {
            possible_max_count++;
        }
    }

    std::cout << possible_max_count << "\n";
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