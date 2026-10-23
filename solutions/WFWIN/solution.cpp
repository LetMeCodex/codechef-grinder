#include <cstdio>    // Required for scanf, printf
#include <algorithm> // Required for std::min

// Function to solve a single test case
void solve() {
    int M, P;
    // Use scanf for faster input
    scanf("%d %d", &M, &P);

    // To maximize the number of wrong submissions (W), we must minimize the
    // penalty incurred by the correct submission.
    // The earliest possible time for the correct submission, after W wrong
    // submissions, is M + W. This is because:
    // 1. The first submission can be made at minute M.
    // 2. Each wrong submission requires at least one minute wait before the next.
    // So, W wrong submissions would be made at M, M+1, ..., M+W-1.
    // The correct submission would then be made at M+W.
    // Let X_c be the time of the correct submission. We assume X_c = M + W.

    // Constraint 1: Total penalty must be <= 1000
    // Initial Penalty (P) + Penalty from W wrong submissions (W * 20) + Penalty from correct submission time (X_c) <= 1000
    // Substituting X_c = M + W:
    // P + (W * 20) + (M + W) <= 1000
    // P + M + (21 * W) <= 1000
    // 21 * W <= 1000 - P - M
    // W <= (1000 - P - M) / 21

    // Calculate the maximum W based on the penalty budget.
    int penalty_budget_for_W = 1000 - P - M;
    int max_w_by_penalty;
    if (penalty_budget_for_W < 0) {
        // If P + M > 1000, even with 0 wrong submissions and the earliest correct submission (at M),
        // the total penalty (P + M) already exceeds 1000.
        // In this scenario, no wrong submissions can be made while winning.
        max_w_by_penalty = 0;
    } else {
        // Otherwise, calculate how many wrong submissions are allowed by the penalty budget.
        // Integer division naturally floors the result for non-negative dividend.
        max_w_by_penalty = penalty_budget_for_W / 21;
    }

    // Constraint 2: The correct submission must be made strictly before the 300th minute.
    // X_c <= 299
    // Substituting X_c = M + W:
    // M + W <= 299
    // W <= 299 - M

    // Calculate the maximum W based on time availability.
    int max_w_by_time = 299 - M; // This will always be non-negative as M < 300.

    // The maximum number of wrong submissions is limited by both the penalty budget
    // and the available time. We take the minimum of these two limits.
    // Both max_w_by_penalty and max_w_by_time are guaranteed to be non-negative.
    int result = std::min(max_w_by_penalty, max_w_by_time);
    
    // Use printf for faster output
    printf("%d\n", result);
}

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); with scanf/printf
    int T; // Number of test cases
    scanf("%d", &T);
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}