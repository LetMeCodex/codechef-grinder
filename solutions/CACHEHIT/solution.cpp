#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions

// Using the standard namespace as requested by problem instructions
using namespace std;

void solve() {
    int N, B, M;
    cin >> N >> B >> M;

    // current_block_in_cache stores the ID of the block currently loaded in the cache.
    // Initialize with -1 to signify that the cache is empty initially.
    // Valid block IDs are non-negative (0, 1, 2, ...).
    int current_block_in_cache = -1; 
    
    // load_count keeps track of how many times a block has been loaded into the cache.
    int load_count = 0;

    // Iterate through each of the M accesses Chef wants to make.
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x; // Read the index of the element A_x to be accessed.

        // Calculate the block ID for the current element A_x.
        // Integer division `x / B` correctly determines which block A_x belongs to.
        // For example, if B=3:
        // Indices 0, 1, 2 are in block 0 (0/3=0, 1/3=0, 2/3=0)
        // Indices 3, 4, 5 are in block 1 (3/3=1, 4/3=1, 5/3=1)
        int target_block_id = x / B;

        // If the target block is different from the one currently loaded in the cache,
        // a new block load is required. This also covers the initial state where
        // current_block_in_cache is -1 (empty cache).
        if (target_block_id != current_block_in_cache) {
            load_count++; // Increment the count of block loads.
            current_block_in_cache = target_block_id; // Update the cache to hold the new block.
        }
        // If target_block_id == current_block_in_cache,
        // the element A_x is in the block already present in the cache,
        // so no new load occurs.
    }

    // Print the total number of block loads for this test case, followed by a newline.
    cout << load_count << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve(); // Call the function to solve the current test case.
    }

    return 0; // Indicate successful program execution.
}