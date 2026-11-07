# Elections (USELEC)
- **Difficulty Rating**: 1133
- **Solved in**: 2 attempt(s)

## Problem Summary
In an election with $N$ states, candidate A and candidate B are competing. For each state $i$, we are given the number of votes candidate A has ($A_i$) and the number of votes candidate B has ($B_i$). Candidate A wins a state if $A_i > B_i$. Chef can add votes to candidate A's tally in any state. Chef has a total of $X$ votes to distribute. Chef wants to know if it's possible for candidate A to win a strict majority of the states (i.e., more than $N/2$ states) after distributing the $X$ votes.

## Intuition & Mathematical Observation

The core of the problem is to determine if Chef can achieve a majority for candidate A by strategically distributing the $X$ votes. A strict majority means winning at least $\lfloor N/2 \rfloor + 1$ states.

First, let's identify the states where candidate A *already* wins. These states contribute to the initial win count and don't require any additional votes.

For states where candidate A does *not* currently win (i.e., $A_i \le B_i$), Chef needs to add votes to make $A_i$ strictly greater than $B_i$. The minimum number of votes Chef needs to add in state $i$ for A to win is $(B_i - A_i) + 1$. Let's call this the "cost" to win state $i$.

The problem then becomes a resource allocation problem: Chef has $X$ votes (resources) and wants to win as many additional states as possible to reach the majority threshold. To maximize the number of states won with a limited budget of $X$ votes, Chef should prioritize winning states with the *lowest cost*. This is a classic greedy approach.

We can calculate the cost for each state where A doesn't currently win. Then, we sort these costs in ascending order and start "buying" states from the cheapest until either Chef runs out of votes ($X$) or reaches the required majority.

The constraints on $A_i$ and $B_i$ are up to $1000$. This means the maximum cost to win a state is $1000 - 1 + 1 = 1000$ (when $A_i=1, B_i=1000$) or $1000 - 1000 + 1 = 1$ (when $A_i=1000, B_i=1000$). This limited range of costs (1 to 1000) allows for an efficient counting sort-like approach. Instead of explicitly sorting, we can count the occurrences of each cost.

**Algorithm Outline:**
1. Initialize `current_wins` to 0.
2. Create a frequency map (or an array since costs are bounded) to store the counts of states for each possible cost (1 to 1000).
3. Iterate through all $N$ states:
    - If $A_i > B_i$, increment `current_wins`.
    - If $A_i \le B_i$, calculate `cost = (B_i - A_i) + 1` and increment the count for this `cost` in the frequency map.
4. Calculate the `required_wins = (N / 2) + 1`.
5. If `current_wins >= required_wins`, output "YES".
6. Otherwise, iterate through the costs from 1 to 1000:
    - For each `cost`, check how many states have this cost (`count_at_cost`).
    - If Chef has enough votes to afford at least one state of this cost (`X >= cost`):
        - Determine how many states of this cost Chef can afford: `num_to_buy = min(count_at_cost, X / cost)`.
        - Subtract the cost of these states from $X$: `X -= num_to_buy * cost`.
        - Add these states to `current_wins`: `current_wins += num_to_buy`.
    - If `current_wins >= required_wins` at any point, break the loop and output "YES".
    - If `X < cost`, Chef cannot afford any more states of this cost or higher, so break the loop.
7. After iterating through all affordable costs, if `current_wins >= required_wins`, output "YES". Otherwise, output "NO".

The use of `long long` for $X$ is crucial because $X$ can be up to $10^8$, and intermediate calculations like `num_states_to_win_at_this_cost * cost` could exceed the capacity of a 32-bit integer.

## Complexity Analysis

- **Time Complexity**: $O(N + C)$, where $N$ is the number of states and $C$ is the maximum possible cost (which is 1000 in this problem).
    - Reading input and calculating initial wins/costs: $O(N)$.
    - Iterating through costs to distribute votes: $O(C)$.
    - Since $C$ is a constant (1000), the time complexity is effectively $O(N)$.

- **Space Complexity**: $O(C)$, where $C$ is the maximum possible cost.
    - We use a vector `cost_counts` of size 1001 to store the frequency of costs.
    - Since $C$ is a constant, the space complexity is effectively $O(1)$.

## Solution Code

```cpp
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
```