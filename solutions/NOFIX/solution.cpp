#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    // 'operations_count' tracks the number of elements inserted so far.
    // Each inserted element shifts all subsequent elements' indices by 1.
    int operations_count = 0;
    
    for (int i = 0; i < n; ++i) {
        int current_A_val;
        std::cin >> current_A_val; // Read the i-th element of the original array
        
        // Calculate the 1-based index this element would currently occupy.
        // 'i' is 0-based, so (i + 1) is its original 1-based index.
        // 'operations_count' adds the cumulative shift from previous insertions.
        int effective_index = (i + 1 + operations_count);
        
        // Check if the current element's value equals its effective index.
        if (current_A_val == effective_index) {
            // If it's a fixed point, we must perform an operation.
            // This operation effectively inserts an element, shifting 'current_A_val'
            // and all subsequent elements one position to the right.
            // Incrementing 'operations_count' accounts for this shift for all future elements.
            // It also ensures that 'current_A_val' itself is no longer a fixed point,
            // as its new index would be (effective_index + 1), which is no longer equal to current_A_val.
            operations_count++;
        }
    }
    
    std::cout << operations_count << "\n";
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