#include <iostream> // For std::cin, std::cout
#include <vector>   // Not strictly needed if processing on the fly, but good for general competitive programming
#include <algorithm> // For std::min, std::max
#include <limits>    // For std::numeric_limits (LLONG_MAX, LLONG_MIN)

// Using namespace std; is requested by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Initialize min_val and max_val with extreme values to correctly find
    // the actual minimum and maximum elements in the array.
    // A_i can be up to 10^9, so long long is used for min_val/max_val to be safe,
    // though int would technically suffice for storing A_i values themselves.
    // The products definitely need long long.
    long long min_val = numeric_limits<long long>::max();
    long long max_val = numeric_limits<long long>::min();
    
    for (int i = 0; i < N; ++i) {
        long long current_A_i;
        cin >> current_A_i;
        min_val = min(min_val, current_A_i);
        max_val = max(max_val, current_A_i);
    }
    
    // The minimum and maximum interesting values will always be achieved by
    // one of these three products:
    // 1. min_val * min_val (from a subarray containing only the global minimum element)
    // 2. max_val * max_val (from a subarray containing only the global maximum element)
    // 3. min_val * max_val (from a subarray containing both global min and max, e.g., the entire array)
    
    long long prod1 = min_val * min_val;
    long long prod2 = max_val * max_val;
    long long prod3 = min_val * max_val;
    
    // Calculate the overall minimum interesting value
    long long min_interesting_value = min({prod1, prod2, prod3});
    
    // Calculate the overall maximum interesting value
    long long max_interesting_value = max({prod1, prod2, prod3});
    
    cout << min_interesting_value << " " << max_interesting_value << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}