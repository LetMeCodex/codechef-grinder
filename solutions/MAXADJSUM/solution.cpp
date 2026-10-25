#include <bits/stdc++.h> // Includes all standard libraries, as requested by problem instructions

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    // Declare a vector to store array elements.
    // Using long long for elements is safe, though int would suffice for A_i values (up to 10^4).
    // The sum will definitely require long long.
    std::vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read array elements
    }

    // Sort the array in non-decreasing order.
    // This places the smallest elements at the beginning (A[0], A[1])
    // and the largest elements at the end.
    std::sort(A.begin(), A.end());

    // Calculate the total sum of all elements in the array.
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        total_sum += A[i];
    }
    
    // The maximum value of f(A) is 2 * (total sum of elements) - (smallest element) - (second smallest element).
    // A[0] is the smallest element, A[1] is the second smallest element after sorting.
    long long max_f_A = 2 * total_sum - A[0] - A[1];

    std::cout << max_f_A << "\n"; // Output the result followed by a newline
}

int main() {
    // Use `using namespace std;` as requested by problem instructions.
    using namespace std; 

    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}