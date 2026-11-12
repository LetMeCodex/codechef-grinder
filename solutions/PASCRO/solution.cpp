#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to determine the winner of a single round
// Returns 1 if Chef wins, -1 if Chefina wins, 0 if it's a draw.
int get_round_outcome(char chef_move, char chefina_move) {
    if (chef_move == chefina_move) {
        return 0; // Draw
    }
    if (chef_move == 'R') {
        if (chefina_move == 'S') return 1; // Rock beats Scissors
        if (chefina_move == 'P') return -1; // Paper beats Rock
    } else if (chef_move == 'P') {
        if (chefina_move == 'R') return 1; // Paper beats Rock
        if (chefina_move == 'S') return -1; // Scissors beats Paper
    } else if (chef_move == 'S') {
        if (chefina_move == 'P') return 1; // Scissors beats Paper
        if (chefina_move == 'R') return -1; // Rock beats Scissors
    }
    return 0; // Should not be reached with valid inputs 'R', 'P', 'S'
}

void solve() {
    int N;
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;

    int chef_wins_count = 0;
    int chefina_wins_count = 0;
    int draw_count = 0;

    // Calculate initial scores and categorize rounds
    for (int i = 0; i < N; ++i) {
        int outcome = get_round_outcome(A[i], B[i]);
        if (outcome == 1) {
            chef_wins_count++;
        } else if (outcome == -1) {
            chefina_wins_count++;
        } else { // outcome == 0
            draw_count++;
        }
    }

    // If Chef already wins, 0 changes are needed.
    if (chef_wins_count > chefina_wins_count) {
        std::cout << 0 << "\n";
        return;
    }

    // Chef needs to win, meaning Chef's final score must be strictly greater than Chefina's final score.
    // Let S_A be Chef's initial score and S_B be Chefina's initial score.
    // We need S_A' > S_B'.
    // The current difference is D = S_A - S_B. Since S_A <= S_B, D <= 0.
    // We need the final difference D' = S_A' - S_B' >= 1.
    // The required increase in difference is at least 1 - D.
    int current_diff = chef_wins_count - chefina_wins_count;
    int diff_needed = 1 - current_diff; // This will be >= 1 since current_diff <= 0

    int changes = 0;

    // Strategy:
    // 1. Prioritize converting Chefina's wins to Chef's wins.
    //    Each such conversion costs 1 change and increases the score difference by 2.
    //    We have `chefina_wins_count` such rounds available.
    // 2. If more difference is needed, convert draws to Chef's wins.
    //    Each such conversion costs 1 change and increases the score difference by 1.
    //    We have `draw_count` such rounds available.

    // Calculate how many Chefina-win conversions (k1) are ideally needed.
    // We need 2 * k1 >= diff_needed.
    // Minimum k1 = ceil(diff_needed / 2.0)
    // Using integer division: k1_needed = (diff_needed + 1) / 2
    int k1_needed = (diff_needed + 1) / 2;

    if (k1_needed <= chefina_wins_count) {
        // We can achieve the goal by only converting Chefina's wins.
        changes = k1_needed;
    } else {
        // We must convert all Chefina's wins first.
        changes = chefina_wins_count;
        int diff_achieved_by_k1 = 2 * chefina_wins_count;
        
        // Calculate the remaining difference needed after converting all Chefina's wins.
        int remaining_diff_needed = diff_needed - diff_achieved_by_k1;
        
        // Now we need to cover the remaining difference using draws.
        // Each draw conversion gives +1 difference.
        int k2_needed = remaining_diff_needed;
        
        // Add the draw conversions to the total changes.
        // We assume k2_needed will be covered by draw_count, as it's always possible to win.
        changes += k2_needed;
    }

    std::cout << changes << "\n";
}

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}