#include <iostream> // For cin, cout
#include <vector>   // For vector
#include <string>   // For string
#include <numeric>  // For std::fill (also available in <algorithm>)

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Fast I/O: Unties cin from cout and disables synchronization with C-style I/O.
    // This significantly speeds up input/output operations, which is crucial in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    // Read the number of tweets (N) and the number of clicks (K).
    cin >> N >> K;

    // The original solution used `vector<bool>`. While memory-efficient,
    // `vector<bool>` is a specialized template that packs booleans into bits.
    // This can sometimes lead to slower performance for individual element access
    // and range operations like `std::fill` due to the overhead of bit manipulation.
    //
    // For N, K <= 1000, the overall complexity of K * O(N) for `CLOSEALL` operations
    // (worst case K `CLOSEALL`s) is 1000 * 1000 = 10^6 operations. This count
    // is typically acceptable within standard time limits (e.g., 1-2 seconds).
    //
    // The "Time Limit Exceeded" verdict suggests that the constant factor for
    // these operations, particularly `std::fill` on `vector<bool>`, might be
    // too high on the judging system.
    //
    // Switching to `vector<char>` (or `vector<int>`) avoids the `vector<bool>`
    // specialization. Each element will occupy a full byte (or more), making
    // element access direct and `std::fill` highly optimized (often using `memset`).
    // This should significantly reduce the constant factor overhead.
    //
    // We'll use 0 for closed and 1 for open.
    vector<char> is_open(N + 1, 0); 
    
    // `open_count` keeps track of the total number of tweets currently open.
    // Initially, no tweets are open.
    int open_count = 0; 

    // Process each of the K clicks.
    for (int i = 0; i < K; ++i) {
        string command;
        // Read the command for the current click.
        cin >> command;

        if (command == "CLICK") {
            int tweet_number;
            // If the command is "CLICK", read the tweet number.
            cin >> tweet_number;
            
            // Toggle the state of the specified tweet.
            // If it was open (1), close it (0) and decrement count.
            // If it was closed (0), open it (1) and increment count.
            if (is_open[tweet_number] == 1) { // If the tweet was open
                is_open[tweet_number] = 0;    // Close it
                open_count--;                 // Decrement the count
            } else {                          // If the tweet was closed
                is_open[tweet_number] = 1;    // Open it
                open_count++;                 // Increment the count
            }
        } else if (command == "CLOSEALL") {
            // If the command is "CLOSEALL", all tweets must be closed.
            // For `vector<char>`, `std::fill` is very efficient, often optimized
            // to a `memset` call, which is much faster than a bit-by-bit loop.
            // `is_open.begin() + 1` ensures we start from tweet 1 (skipping the unused `is_open[0]`).
            // `is_open.end()` points one past the last element, covering all tweets up to N.
            fill(is_open.begin() + 1, is_open.end(), 0); 
            
            // Since all tweets are now closed, reset the `open_count` to 0.
            open_count = 0; 
        }
        
        // After each click, output the current number of open tweets.
        // Using "\n" instead of `endl` is generally faster in competitive programming
        // because `endl` also flushes the output buffer, which is often not necessary
        // after every line.
        cout << open_count << "\n";
    }

    return 0; // Indicate successful execution.
}