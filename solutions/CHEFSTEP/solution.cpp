#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <string>   // Required for using std::string to build the output
// #include <vector> // Not strictly necessary for this problem, but often useful

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE on large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int N;       // Variable to store the number of distances for the current test case
        long long K; // Variable to store Chef's step length. Using long long for K and D_i
                     // because they can be up to 10^9, which fits in 'int' on most systems
                     // but 'long long' is safer and guarantees 64-bit storage.
        std::cin >> N >> K; // Read N and K for the current test case

        std::string result_string = ""; // Initialize an empty string to build the output for this test case

        for (int i = 0; i < N; ++i) { // Loop N times to read each distance D_i
            long long D_i; // Variable to store the current distance
            std::cin >> D_i; // Read the current distance D_i

            // Check if D_i is traversable: a distance D_i is traversable if it's a multiple of K.
            // This is true if the remainder of D_i divided by K is 0.
            if (D_i % K == 0) {
                result_string += '1'; // If traversable, append '1' to the result string
            } else {
                result_string += '0'; // If not traversable, append '0' to the result string
            }
        }
        std::cout << result_string << "\n"; // Print the complete result string for the current test case, followed by a newline
    }

    return 0; // Indicate successful program execution
}