#include <bits/stdc++.h> // Includes iostream for input/output and algorithm for max()
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integer variables N and M for each test case.
        cin >> N >> M; // Read N (number of friends) and M (left shoes Chef has).

        // Calculate the number of left shoes Chef needs to buy.
        // If M < N, Chef needs N - M more left shoes.
        // If M >= N, Chef has enough left shoes, so he needs to buy 0 more.
        int left_shoes_to_buy = max(0, N - M);

        // Chef always needs to buy N right shoes, as he starts with none.
        int right_shoes_to_buy = N;

        // The total minimum number of extra shoes to buy is the sum of
        // left shoes to buy and right shoes to buy.
        int total_extra_shoes = left_shoes_to_buy + right_shoes_to_buy;

        // Output the result for the current test case, followed by a newline.
        cout << total_extra_shoes << "\n";
    }

    return 0; // Indicate successful program execution.
}