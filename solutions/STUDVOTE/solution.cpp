#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector

// It's common in competitive programming to use 'using namespace std;'
// and '#include <bits/stdc++.h>' for convenience.
// For this problem, specific includes are sufficient.

void solve() {
    int N, K;
    std::cin >> N >> K; // Read N (number of students) and K (required votes)

    // vote_counts[j] will store the number of votes student j received.
    // We use N+1 size for 1-indexed student IDs (from 1 to N).
    std::vector<int> vote_counts(N + 1, 0);

    // self_voted[j] will be true if student j voted for themselves.
    // We use N+1 size for 1-indexed student IDs.
    std::vector<bool> self_voted(N + 1, false);

    // Pass 1: Process all N votes
    for (int i = 0; i < N; ++i) {
        int voted_for_student_id;
        std::cin >> voted_for_student_id; // Read who the (i+1)-th student voted for

        int voter_student_id = i + 1; // The current student casting the vote is (i+1)

        // Increment the vote count for the student who received the vote
        vote_counts[voted_for_student_id]++;

        // Check if the student voted for themselves
        if (voter_student_id == voted_for_student_id) {
            self_voted[voter_student_id] = true;
        }
    }

    int government_size = 0; // Counter for eligible students

    // Pass 2: Determine eligible students
    for (int student_id = 1; student_id <= N; ++student_id) {
        // Check if the student received at least K votes AND did not vote for themselves
        if (vote_counts[student_id] >= K && !self_voted[student_id]) {
            government_size++; // This student is eligible
        }
    }

    std::cout << government_size << "\n"; // Output the final size of the student government
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}