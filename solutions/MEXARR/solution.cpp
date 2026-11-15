#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort, std::abs

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    // Declare a vector to store the array elements.
    // A_i values are between 0 and N, so 'int' is sufficient for individual elements.
    std::vector<int> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read each element
    }

    // Step 1: Sort the array A.
    // This is crucial because to minimize the sum of absolute differences
    // between two sets of numbers, both sets must be sorted and then paired element-wise.
    std::sort(A.begin(), A.end());

    // Step 2: Calculate the minimum operations.
    // The goal is to achieve the maximum possible MEX.
    // For an array of length N, the maximum possible MEX is N.
    // This requires the array to contain all integers from 0 to N-1.
    // So, our target array is effectively [0, 1, ..., N-1].
    // We pair the i-th smallest element of A (which is A[i] after sorting)
    // with the i-th smallest target value (which is i).
    // The cost for this pairing is |A[i] - i|.
    // The total sum of operations can be large, so 'long long' is necessary.
    long long total_operations = 0;
    for (int i = 0; i < N; ++i) {
        total_operations += std::abs(A[i] - i);
    }

    // Output the minimum number of operations for the current test case.
    std::cout << total_operations << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}