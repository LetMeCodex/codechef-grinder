#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

void solve() {
    int N;
    std::cin >> N;
    
    // Create a vector to store all 2N elements from arrays A and B.
    std::vector<int> combined_elements(2 * N);
    
    // Read elements of array A
    for (int i = 0; i < N; ++i) {
        std::cin >> combined_elements[i];
    }
    
    // Read elements of array B
    for (int i = 0; i < N; ++i) {
        std::cin >> combined_elements[N + i];
    }

    // Sort all 2N elements.
    std::sort(combined_elements.begin(), combined_elements.end());

    // Initialize minimum difference to a very large value.
    int min_diff = INT_MAX;

    // Iterate through all possible windows of N consecutive elements.
    // A window starting at index 'i' will contain elements from combined_elements[i]
    // to combined_elements[i + N - 1].
    // The loop runs from i = 0 up to i = N.
    // When i = 0, the window is [0, N-1].
    // When i = N, the window is [N, 2N-1].
    for (int i = 0; i <= N; ++i) {
        int current_max = combined_elements[i + N - 1];
        int current_min = combined_elements[i];
        min_diff = std::min(min_diff, current_max - current_min);
    }

    std::cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}