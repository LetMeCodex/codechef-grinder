#include <iostream> // For standard input/output operations (cin, cout)
#include <numeric>  // For std::gcd (though we'll implement our own for robustness)
#include <algorithm> // For std::swap, used in the custom GCD function

// Custom GCD function using the Euclidean algorithm
// This is a robust and efficient implementation, often preferred in competitive programming
// to avoid potential platform-specific issues with std::gcd or older C++ standards.
long long custom_gcd(long long a, long long b) {
    while (b) { // Continue as long as b is not zero
        a %= b; // Replace a with the remainder of a divided by b
        std::swap(a, b); // Swap a and b. The old b becomes the new a, and the remainder becomes the new b.
    }
    return a; // When b becomes zero, a holds the greatest common divisor
}

void solve() {
    long long B, C; // Declare B and C as long long to handle values up to 10^9
    std::cin >> B >> C; // Read B and C for the current test case
    
    // Calculate the greatest common divisor of B and C using our custom function
    long long common_divisor = custom_gcd(B, C); 
    
    // According to the mathematical derivation, the minimum positive A is C / gcd(B, C)
    long long A = C / common_divisor; 
    
    std::cout << A << "\n"; // Output the result followed by a newline character
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with a large number of test cases (T=10^5).
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Declare T for the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful program execution
}