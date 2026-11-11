#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Not strictly needed for this solution, but often useful
#include <map>      // For std::map to count frequencies
#include <algorithm> // For std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array

    // Use a map to store frequencies of each number in array A.
    // std::map provides sorted keys, but for this problem, order doesn't matter.
    // std::unordered_map could also be used for potentially faster average-case performance.
    std::map<int, int> counts; 
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read each element of array A
        counts[A_i]++;   // Increment its frequency
    }

    int min_max_freq_B = 0; // This will store the minimum possible value of the maximum frequency in B

    // Iterate through the frequencies of distinct elements in A
    for (auto const& pair : counts) {
        // 'pair.first' is the value (A_i), 'pair.second' is its frequency (count)
        int count = pair.second;

        // For each distinct value 'V' that appears 'count' times in A,
        // we can transform these 'count' occurrences into two groups in array B:
        // 1. 'count_minus' elements equal to 'V - X'
        // 2. 'count_plus' elements equal to 'V + X'
        // where count_minus + count_plus = count.
        // To minimize the frequency of any single value originating from 'V',
        // we should make 'count_minus' and 'count_plus' as balanced as possible.
        // This means count_minus = ceil(count / 2.0) and count_plus = floor(count / 2.0) (or vice versa).
        // The maximum frequency contributed by these 'count' elements will be ceil(count / 2.0).
        // In integer arithmetic, ceil(k / 2.0) can be computed as (k + 1) / 2.
        
        // We can always choose an integer X (X != 0) such that for any two distinct values V1, V2 in A,
        // the four values V1-X, V1+X, V2-X, V2+X are all distinct.
        // The only potential collision is if |V1 - V2| = 2X.
        // Since the set of possible differences |V1 - V2| is finite, we can always pick an X
        // such that 2X is not equal to any of these differences. For example, pick X large enough.
        // Thus, the maximum frequency in B will be the maximum of ceil(count / 2.0) over all distinct values in A.
        
        min_max_freq_B = std::max(min_max_freq_B, (count + 1) / 2);
    }

    std::cout << min_max_freq_B << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}