#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for using std::vector
#include <algorithm> // Required for std::sort and std::min

void solve() {
    int N;
    std::cin >> N; // Read the number of rectangles

    // Declare vectors to store sequences A and B.
    // Using long long for elements to be safe, though int would suffice for A_i, B_i values.
    std::vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements of sequence A
    }

    std::vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i]; // Read elements of sequence B
    }

    // Sort both sequences A and B in non-decreasing order.
    // This is the crucial step to maximize the sum of minimums.
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    long long total_sum_of_diameters = 0; // Use long long for the sum to prevent overflow
    
    // Iterate through the sorted arrays and pair A[i] with B[i].
    // The diameter of the inscribed circle for a rectangle of dimensions L x W is min(L, W).
    // Sum these minimums to get the maximum possible total sum of diameters.
    for (int i = 0; i < N; ++i) {
        total_sum_of_diameters += std::min(A[i], B[i]);
    }

    std::cout << total_sum_of_diameters << "\n"; // Print the calculated maximum sum
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}