#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <numeric>  // Required for std::gcd
#include <map>      // Required for std::map
#include <algorithm> // Required for std::max

// Function to calculate GCD of an array of positive integers.
// Assumes arr is not empty and contains positive integers.
int calculate_array_gcd(const std::vector<int>& arr) {
    // Initialize result with the first element.
    // Constraints state N >= 1, so arr will not be empty.
    int result = arr[0];
    // Iterate from the second element to calculate GCD cumulatively.
    for (size_t i = 1; i < arr.size(); ++i) {
        result = std::gcd(result, arr[i]);
        // Optimization: If GCD becomes 1, it cannot get any smaller.
        // The overall GCD of the array will be 1.
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

// Function to find all positive divisors of a given positive integer n.
std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    // Iterate up to sqrt(n) to find divisors.
    // If i divides n, then n/i also divides n.
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            // If i*i is not equal to n, then i and n/i are distinct divisors.
            // If i*i == n, then i and n/i are the same, so add only once.
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

void solve() {
    int n;
    std::cin >> n; // Read the size of the array

    std::vector<int> a(n); // Declare vector to store array elements
    std::map<int, int> freq; // Map to store frequencies of elements in array A

    // Read array elements and populate frequency map
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    // Edge case: If N=1, the array already has all elements equal. 0 moves.
    // This is handled correctly by the general logic as well (GCD will be A[0],
    // A[0] will be in freq map with count 1, N - 1 = 0 moves).
    if (n == 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Calculate the greatest common divisor (GCD) of all elements in the array.
    // The target value K must be a divisor of all A_i, hence K must be a divisor of their GCD.
    int common_gcd = calculate_array_gcd(a);

    // Find all divisors of the common_gcd. These are the candidate target values K.
    std::vector<int> divisors_of_gcd = get_divisors(common_gcd);

    // We want to maximize the number of elements that are already equal to the target K.
    // This means finding a K (which is a divisor of common_gcd) that appears most frequently in A.
    int max_freq_for_target = 0;

    // Iterate through all candidate target values (divisors of common_gcd)
    for (int d : divisors_of_gcd) {
        // Check if this candidate target value 'd' exists in the original array A.
        if (freq.count(d)) {
            // If it exists, update max_freq_for_target with the frequency of 'd'.
            max_freq_for_target = std::max(max_freq_for_target, freq[d]);
        }
    }

    // The minimum number of moves is N minus the maximum number of elements
    // that are already equal to the chosen target value K.
    std::cout << n - max_freq_for_target << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}