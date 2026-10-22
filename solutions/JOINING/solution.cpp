#include <iostream> // For input/output operations

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K; // Read N and K for the current test case

    // The problem states that candidate K turns down their offer.
    // This causes all candidates with numbers greater than K to shift up by one position.
    // Candidate i (where i > K) originally had position i.
    // After K withdraws, candidate i moves to position i-1.

    // The joining day for a candidate at position p is ceil(p / 5).
    // Using integer division, this is (p - 1) / 5 + 1.

    // Original joining day for candidate i: D_orig(i) = (i - 1) / 5 + 1
    // New joining day for candidate i (for i > K): D_new(i) = ((i - 1) - 1) / 5 + 1 = (i - 2) / 5 + 1

    // A candidate's joining day changes if D_orig(i) != D_new(i).
    // This inequality (i - 1) / 5 != (i - 2) / 5 holds if and only if
    // (i - 1) is a multiple of 5.
    // So, candidate i (where i > K) changes their joining day if and only if i-1 is a multiple of 5.
    // This means i must be of the form 5m + 1 for some integer m.
    // We need to count how many such candidates i exist in the range (K, N].
    // This is equivalent to counting i such that K < i <= N and i % 5 == 1.

    // We can count this efficiently using a formula.
    // The number of integers x in the range [1, X] such that x % 5 == 1 is floor((X - 1) / 5) + 1.
    // We want to count i in [K + 1, N] such that i % 5 == 1.
    // This is (count of i in [1, N] with i % 5 == 1) - (count of i in [1, K] with i % 5 == 1).

    // Count of i in [1, N] with i % 5 == 1:
    // The numbers are 1, 6, 11, ..., 5*m + 1 <= N
    // 5*m <= N - 1
    // m <= (N - 1) / 5
    // m ranges from 0 to floor((N - 1) / 5).
    // Number of values for m is floor((N - 1) / 5) + 1.
    int count_up_to_N = (N - 1) / 5 + 1;

    // Count of i in [1, K] with i % 5 == 1:
    // The numbers are 1, 6, 11, ..., 5*m + 1 <= K
    // 5*m <= K - 1
    // m <= (K - 1) / 5
    // m ranges from 0 to floor((K - 1) / 5).
    // Number of values for m is floor((K - 1) / 5) + 1.
    int count_up_to_K = (K - 1) / 5 + 1;

    // The number of candidates i in (K, N] with i % 5 == 1 is:
    // count_up_to_N - count_up_to_K
    // = (floor((N - 1) / 5) + 1) - (floor((K - 1) / 5) + 1)
    // = floor((N - 1) / 5) - floor((K - 1) / 5)
    // Using integer division in C++ for floor:
    int changed_days_count = (N - 1) / 5 - (K - 1) / 5;

    std::cout << changed_days_count << "\n"; // Output the total count for this test case
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from C's stdio and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}