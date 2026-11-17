#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max (though manual max finding is also fine)

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array

    std::vector<int> A(N);
    int max_val = 0; // Initialize max_val to 0, as A_i >= 0.

    // Read array elements and find the maximum value
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    // Check if there are any "intermediate" values.
    // An intermediate value is one that is neither 0 nor the maximum value.
    // If such a value exists, it's impossible to make all elements equal to max_val.
    bool has_intermediate_value = false;
    for (int i = 0; i < N; ++i) {
        if (A[i] != 0 && A[i] != max_val) {
            has_intermediate_value = true;
            break; // Found an intermediate value, no need to check further
        }
    }

    // Output "NO" if an intermediate value was found, otherwise "YES".
    if (has_intermediate_value) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}