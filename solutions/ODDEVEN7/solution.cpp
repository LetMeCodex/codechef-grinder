#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    int count_odd = 0;
    int count_even = 0;

    // Iterate through the array elements and count odd/even numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read each element
        if (A_i % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    // Calculate the maximum size of a subset that can form a good array.
    // We can always pair up min(count_odd, count_even) odd numbers with
    // min(count_odd, count_even) even numbers to form an alternating sequence.
    // This gives 2 * min(count_odd, count_even) elements.
    int result = 2 * std::min(count_odd, count_even);

    // If the total counts of odd and even numbers are not equal, it means one parity
    // has more elements than the other. We can pick one additional element from the
    // more frequent parity to extend the alternating sequence by 1. This maintains
    // the |odd_count - even_count| <= 1 property.
    if (count_odd != count_even) {
        result += 1;
    }

    std::cout << result << "\n"; // Output the maximum size
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}