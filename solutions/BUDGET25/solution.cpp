#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N; // Number of sectors
    long long X; // Minimum budget requirement for each sector
    std::cin >> N >> X;
    
    // sectors_met_initial counts sectors that initially have A_i >= X
    int sectors_met_initial = 0;
    // total_surplus accumulates all transferable budget from sectors with A_i >= X
    // Must be long long as sum can exceed 2*10^9 (int max)
    long long total_surplus = 0;
    // deficits stores the amount needed by sectors with A_i < X
    // Elements (X - A_i) fit in int, but long long is used for consistency and safety.
    std::vector<long long> deficits;
    
    // Read initial allocations and categorize them
    for (int i = 0; i < N; ++i) {
        long long current_A; // Current sector's allocation
        std::cin >> current_A;
        
        if (current_A >= X) {
            // This sector already meets the minimum requirement
            sectors_met_initial++;
            // It can contribute its surplus (current_A - X) to other sectors
            total_surplus += (current_A - X);
        } else {
            // This sector does not meet the minimum requirement
            // It needs (X - current_A) to reach the minimum
            deficits.push_back(X - current_A);
        }
    }
    
    // To maximize the number of sectors meeting the budget,
    // we should use the available total_surplus to cover the smallest deficits first.
    std::sort(deficits.begin(), deficits.end());
    
    // Iterate through the sorted deficits and try to cover them
    for (long long deficit_amount : deficits) {
        if (total_surplus >= deficit_amount) {
            // If we have enough surplus, cover this deficit
            total_surplus -= deficit_amount;
            sectors_met_initial++; // This sector now also meets the budget
        } else {
            // If we don't have enough surplus for this deficit,
            // we won't have enough for any subsequent (larger) deficits either.
            // So, we can stop here.
            break;
        }
    }
    
    // Output the maximum number of sectors that can meet the minimum budget
    std::cout << sectors_met_initial << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    
    return 0;
}