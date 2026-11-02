#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

void solve() {
    int N;
    std::cin >> N;
    
    // The problem asks for the minimal size of an initial array from which
    // the given array A can be obtained using "Copy-Paste" operations.
    // A "Copy-Paste" operation duplicates existing elements; it never introduces
    // new distinct values. Therefore, the set of unique elements in the initial
    // array must be the same as the set of unique elements in the final array A.
    // To minimize the initial array's size, it should contain each unique element
    // exactly once. Thus, the answer is simply the count of unique elements in A.

    // Constraints: 1 <= Ai <= 10^5.
    // We use a boolean vector to efficiently track which elements have been seen.
    // The size needs to be 100001 to cover indices from 0 to 100000.
    // Since Ai >= 1, index 0 will not be used.
    std::vector<bool> seen(100001, false); 
    int unique_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        // If this value has not been seen before, mark it as seen and increment the count.
        if (!seen[val]) {
            seen[val] = true;
            unique_count++;
        }
    }
    
    // Output the total count of unique elements.
    std::cout << unique_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }
    
    return 0;
}