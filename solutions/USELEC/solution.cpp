#include <iostream> // For cin, cout
#include <vector>   // For std::vector
#include <algorithm> // For std::min

// Using the standard namespace as per problem instructions
using namespace std;

// Function to solve a single test case
void solve() {
    int n; // Number of states
    long long x; // Chef's additional votes. Can be up to 10^8, so long long is necessary.
    cin >> n >> x;

    vector<int> a(n); // Votes for candidate A in each state
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n); // Votes for candidate B in each state
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int current_wins = 0; // Number of states A currently wins
    // Using an array for counting sort. Max cost is 1000, so size 1001 for indices 0-1000.
    // Initialize to zeros.
    vector<int> cost_counts(1001, 0); 

    // Iterate through each state to determine initial wins and costs
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            // Candidate A already wins in this state (A_i > B_i)
            current_wins++;
        } else {
            // Candidate A does not win (A_i <= B_i).
            // Calculate minimum votes Chef needs to add for A to win this state.
            // A_i + votes > B_i  => votes > B_i - A_i
            // Minimum integer votes needed = (B_i - A_i) + 1
            int cost = b[i] - a[i] + 1;
            // Costs are guaranteed to be between 1 and 1000 based on constraints A_i, B_i >= 1.
            // If A_i = B_i, cost = 1. If A_i=1, B_i=1000, cost = 1000.
            cost_counts[cost]++;
        }
    }

    // Candidate A needs to win more than half of the states.
    // Since N is odd, this is (N/2) + 1.
    // For example, if N=3, N/2=1, required_wins=2.
    // If N=1, N/2=0, required_wins=1.
    int required_wins = (n / 2) + 1;

    // If A already has enough wins, no need for Chef's votes
    if (current_wins >= required_wins) {
        cout << "YES\n";
        return;
    }

    // To maximize the number of additional states won with limited votes (X),
    // Chef should prioritize winning states that require the fewest additional votes.
    // Iterate through costs from 1 to 1000 (cheapest to most expensive).
    for (int cost = 1; cost <= 1000; ++cost) {
        // If we've already secured enough wins, stop
        if (current_wins >= required_wins) {
            break; 
        }
        
        // If Chef doesn't have enough votes for this cost, cannot afford any more states.
        // Since costs are processed in ascending order, if X < cost, Chef cannot afford
        // any states of this cost or any higher costs.
        if (x < cost) {
            break; 
        }

        // Calculate how many states of this 'cost' Chef can afford.
        // It's the minimum of:
        // 1. The number of states available at this cost (cost_counts[cost]).
        // 2. The number of states Chef can afford with remaining votes X (X / cost).
        // Note: cost_counts[cost] is int, X is long long. Cast cost_counts[cost] to long long for min.
        long long num_states_to_win_at_this_cost = min((long long)cost_counts[cost], x / cost);

        // Update votes and wins
        x -= num_states_to_win_at_this_cost * cost;
        current_wins += num_states_to_win_at_this_cost;
    }

    // After distributing votes, check if A has enough wins
    if (current_wins >= required_wins) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}