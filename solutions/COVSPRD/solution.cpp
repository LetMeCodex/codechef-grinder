#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::min

// It's generally good practice to avoid 'using namespace std;' in headers or large projects,
// but for competitive programming, it's common and often requested.
using namespace std;

void solve() {
    long long N, D;
    cin >> N >> D;

    long long infected_count = 1;

    if (D == 0) {
        // At the end of day 0, a single person is infected.
        infected_count = 1;
    } else if (D <= 10) {
        // During the next 10 days (Day 1 to Day 10), the number of infected people doubles each day.
        // Calculate 2^D. Use 1LL to ensure the shift operation is done with long long.
        infected_count = 1LL << D;
        // Cap the infected count at N (total population).
        infected_count = min(N, infected_count);
    } else { // D > 10
        // First, calculate the number of infected people at the end of Day 10.
        long long infected_at_day_10 = 1LL << 10; // 2^10 = 1024
        infected_at_day_10 = min(N, infected_at_day_10);

        // If the population N was already fully infected by day 10,
        // it cannot increase further.
        if (infected_at_day_10 == N) {
            infected_count = N;
        } else {
            // From day 11 onwards, the number of infected people triples each day.
            // Start with the count from day 10.
            infected_count = infected_at_day_10;
            long long days_to_triple = D - 10;

            // Simulate tripling for `days_to_triple` days.
            // This loop will run a small number of times (at most ~17-18)
            // because `infected_count` will quickly reach `N` due to exponential growth.
            for (int i = 0; i < days_to_triple; ++i) {
                // Check if multiplying by 3 would exceed N.
                // This prevents overflow and correctly caps the count at N.
                // If infected_count > N / 3, then infected_count * 3 would be > N.
                // Example: N=10, N/3=3. If infected_count=4, 4 > 3 is true.
                // So infected_count becomes N=10. Correct.
                // This check is robust for all N >= 1.
                if (infected_count > N / 3) {
                    infected_count = N;
                    break; // Population fully infected, no need to triple further.
                }
                infected_count *= 3;
            }
            // No need for a final min(N, infected_count) here, as the loop logic already ensures it.
        }
    }

    cout << infected_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}