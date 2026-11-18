#include <iostream>
// #include <numeric> // No longer needed for std::gcd
#include <algorithm> // Required for std::min and std::swap

// Custom GCD function to avoid potential issues with std::gcd on some judges
long long my_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Function to calculate LCM of two numbers
// Uses the property: lcm(a, b) = (a * b) / gcd(a, b)
// The division by gcd is done first to prevent potential overflow if a*b is very large.
long long calculate_lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // LCM is 0 if either number is 0. (Not reachable given constraints A,B >= 1)
    // For positive integers, a and b are at least 1, so my_gcd(a,b) is at least 1.
    // (a / my_gcd(a, b)) ensures that the intermediate result fits in long long
    // before multiplying by b.
    return (a / my_gcd(a, b)) * b;
}

void solve() {
    long long A, B;
    std::cin >> A >> B;

    // Candidate 1: Choose X = my_gcd(A, B)
    // Value: A - my_gcd(A, B)
    long long common_divisor = my_gcd(A, B);
    long long candidate1 = A - common_divisor;

    // Candidate 2: Choose X = B
    // Value: lcm(A, B) - B
    long long common_multiple = calculate_lcm(A, B);
    long long candidate2 = common_multiple - B;

    // The minimum value is the smaller of these two candidates.
    std::cout << std::min(candidate1, candidate2) << "\n";
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