#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::max, std::min

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of participants

    int pos_count = 0;  // Count of participants with positive scores
    int neg_count = 0;  // Count of participants with negative scores
    int zero_count = 0; // Count of participants with zero scores

    // Iterate through the scores to count positives, negatives, and zeros
    for (int i = 0; i < N; ++i) {
        long long A_i; // Use long long for A_i to safely handle values up to 10^9
        std::cin >> A_i;
        if (A_i > 0) {
            pos_count++;
        } else if (A_i < 0) {
            neg_count++;
        } else {
            zero_count++;
        }
    }

    int max_group_size;
    int min_group_size;

    // Determine max_group_size and min_group_size based on counts
    if (pos_count == 0 && neg_count == 0) {
        // Case 1: All participants have a score of zero.
        // To maximize the total score (which will be 0), all participants must be in one group.
        // This group will contain all 'zero_count' participants.
        max_group_size = zero_count; // This is N
        min_group_size = zero_count; // This is N
    } else if (pos_count == 0) {
        // Case 2: All non-zero scores are negative.
        // To maximize the total score, all negative scores must be grouped together.
        // All zeros can be added to this group without changing the sum or score.
        // Thus, there will be one group containing all 'neg_count' negative scores and all 'zero_count' zeros.
        max_group_size = neg_count + zero_count;
        min_group_size = neg_count + zero_count;
    } else if (neg_count == 0) {
        // Case 3: All non-zero scores are positive.
        // To maximize the total score, all positive scores must be grouped together.
        // All zeros can be added to this group without changing the sum or score.
        // Thus, there will be one group containing all 'pos_count' positive scores and all 'zero_count' zeros.
        max_group_size = pos_count + zero_count;
        min_group_size = pos_count + zero_count;
    } else {
        // Case 4: Both positive and negative scores exist.
        // Optimal strategy is two groups: one for positives, one for negatives.
        // Zeros can be distributed between these two groups.

        // To find the maximum possible group size:
        // Assign all 'zero_count' zeros to the group that already has more members (or either if counts are equal).
        // The largest possible size among these is max(pos_count, neg_count) + zero_count.
        max_group_size = std::max(pos_count, neg_count) + zero_count;

        // To find the minimum possible group size:
        // We have two mandatory groups: one for 'pos_count' positives and one for 'neg_count' negatives.
        // To make the smallest group as small as possible, we should assign all 'zero_count' zeros to the *larger* of the two groups.
        // This leaves the other group with its base size.
        // Therefore, the minimum group size is min(pos_count, neg_count).
        min_group_size = std::min(pos_count, neg_count);
    }

    // Print the results for the current test case
    std::cout << max_group_size << " " << min_group_size << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}