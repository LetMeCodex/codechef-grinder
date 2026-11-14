#include <cstdio>   // For scanf/printf
#include <algorithm> // Required for std::min

// Declare a global char array to avoid repeated memory allocation/deallocation
// Max N is 10^5, so 100005 characters + 1 for null terminator is sufficient.
char s_arr[100005]; 

void solve() {
    int n;
    // Use scanf for faster input
    scanf("%d", &n);
    scanf("%s", s_arr); // Read string into the char array

    // If N is 0, it's already equal (empty string), but constraints say N >= 1.
    // If N is 1, it's already equal. The logic below handles this correctly.
    // For example, if S="0", count0_blocks=1, count1_blocks=0. min(1,0)=0.
    // If S="1", count0_blocks=0, count1_blocks=1. min(0,1)=0.

    int count0_blocks = 0;
    int count1_blocks = 0;

    // The first character always starts a block.
    if (s_arr[0] == '0') {
        count0_blocks = 1;
    } else { // s_arr[0] == '1'
        count1_blocks = 1;
    }

    // Iterate from the second character to count subsequent blocks.
    // A new block starts whenever the current character is different from the previous one.
    for (int i = 1; i < n; ++i) {
        if (s_arr[i] != s_arr[i-1]) {
            // A new block starts
            if (s_arr[i] == '0') {
                count0_blocks++;
            } else { // s_arr[i] == '1'
                count1_blocks++;
            }
        }
    }

    // Use printf for faster output
    printf("%d\n", std::min(count0_blocks, count1_blocks));
}

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    // when using scanf/printf.

    int t;
    scanf("%d", &t); // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}