#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // The problem asks for a binary string of length N such that
        // the count of "01" subsequences equals the count of "10" subsequences,
        // and the string contains at least one '0' and one '1'.
        //
        // Let's analyze the counts of "01" and "10" subsequences.
        // A "01" subsequence is formed by picking a '0' at index i and a '1' at index j, where i < j.
        // A "10" subsequence is formed by picking a '1' at index i and a '0' at index j, where i < j.
        //
        // Consider a string like "00...011...1".
        // If there are `c0` zeros and `c1` ones, the number of "01" subsequences is `c0 * c1`.
        // The number of "10" subsequences is 0. This doesn't work.
        //
        // Consider a string like "11...100...0".
        // If there are `c1` ones and `c0` zeros, the number of "10" subsequences is `c1 * c0`.
        // The number of "01" subsequences is 0. This doesn't work.
        //
        // Consider a string like "010101...".
        // If N is even, say N=4, "0101".
        // "01" subsequences: (0 at 0, 1 at 1), (0 at 0, 1 at 3), (0 at 2, 1 at 3). Count = 3.
        // "10" subsequences: (1 at 1, 0 at 2). Count = 1. Not equal.
        //
        // If N is odd, say N=3, "010".
        // "01" subsequences: (0 at 0, 1 at 1). Count = 1.
        // "10" subsequences: (1 at 1, 0 at 2). Count = 1. Equal!
        // This string "010" has length 3, has at least one '0' and one '1'.
        //
        // Let's try to generalize the pattern "010101..." or "101010...".
        //
        // If we have a string of alternating 0s and 1s, like "010101...",
        // the number of "01" subsequences is the number of pairs (0_i, 1_j) with i < j.
        // the number of "10" subsequences is the number of pairs (1_i, 0_j) with i < j.
        //
        // Let's consider the structure:
        // If we have `k` zeros and `N-k` ones.
        // The total number of pairs (i, j) with i < j is N*(N-1)/2.
        //
        // Consider the string formed by `(N-1)/2` ones, followed by a zero, followed by `(N-1)/2` zeros.
        // Example N=4: (4-1)/2 = 1. String: "1000".
        // "01": 0. "10": 1*3 = 3. Not equal.
        //
        // Consider the string formed by `(N-1)/2` zeros, followed by a one, followed by `(N-1)/2` ones.
        // Example N=4: (4-1)/2 = 1. String: "0111".
        // "01": 1*3 = 3. "10": 0. Not equal.
        //
        // The sample output for N=4 is "1001".
        // "1001":
        // "01" subsequences: (0 at 1, 1 at 3), (0 at 2, 1 at 3). Count = 2.
        // "10" subsequences: (1 at 0, 0 at 1), (1 at 0, 0 at 2). Count = 2. Equal!
        // This string has length 4, has at least one '0' and one '1'.
        //
        // The sample output for N=3 is "010".
        // "01" subsequences: (0 at 0, 1 at 1). Count = 1.
        // "10" subsequences: (1 at 1, 0 at 2). Count = 1. Equal!
        // This string has length 3, has at least one '0' and one '1'.
        //
        // Let's look at the structure of "1001" (N=4) and "010" (N=3).
        // "1001" has two 1s and two 0s.
        // "010" has one 1 and two 0s.
        //
        // The key insight might be related to the number of 0s and 1s.
        // Let `c0` be the count of '0's and `c1` be the count of '1's.
        //
        // Consider a string with `k` ones followed by `N-k` zeros.
        // Number of "10" subsequences = `k * (N-k)`.
        // Number of "01" subsequences = 0.
        //
        // Consider a string with `k` zeros followed by `N-k` ones.
        // Number of "01" subsequences = `k * (N-k)`.
        // Number of "10" subsequences = 0.
        //
        // The problem guarantees that an answer always exists.
        // The constraints are 3 <= N <= 1000.
        //
        // Let's try to construct a string that balances the counts.
        // A simple strategy is to have a block of 0s and a block of 1s, but this doesn't work.
        //
        // What if we put most of the characters of one type at the beginning and the rest at the end?
        //
        // Consider the string: `(N-1)/2` ones, then a zero, then `N - 1 - (N-1)/2` zeros.
        // If N=4, (N-1)/2 = 1. String: "1" + "0" + "00" = "1000".
        // c1=1, c0=3. "10" = 1*3 = 3. "01" = 0.
        //
        // If N=5, (N-1)/2 = 2. String: "11" + "0" + "00" = "11000".
        // c1=2, c0=3. "10" = 2*3 = 6. "01" = 0.
        //
        // This structure `1...100...0` or `0...011...1` always results in one count being zero.
        //
        // The sample "1001" for N=4 suggests a different structure. It has two 1s and two 0s.
        // The sample "010" for N=3 suggests a different structure. It has one 1 and two 0s.
        //
        // Let's consider the number of 0s and 1s.
        // For N=3, "010". c0=2, c1=1.
        // For N=4, "1001". c0=2, c1=2.
        //
        // It seems like we want to have roughly equal numbers of 0s and 1s, or a specific imbalance.
        //
        // Let's try to construct a string with `k` zeros and `N-k` ones.
        // The total number of "01" subsequences is the sum over all '0's at index `i` of (number of '1's after index `i`).
        // The total number of "10" subsequences is the sum over all '1's at index `i` of (number of '0's after index `i`).
        //
        // Consider the string: `(N-1)/2` zeros, followed by `1`, followed by `N - 1 - (N-1)/2` zeros.
        // This doesn't work because it has only one '1'.
        //
        // What if we construct a string with `(N-1)/2` zeros, then a '1', then `(N-1)/2` zeros, and then fill the remaining spots?
        //
        // Let's try to put `(N-1)/2` zeros at the beginning, then a '1', then `(N-1)/2` zeros.
        // Example N=4: (4-1)/2 = 1. String: "0" + "1" + "00" = "0100".
        // "01" subsequences: (0 at 0, 1 at 1). Count = 1.
        // "10" subsequences: (1 at 1, 0 at 2), (1 at 1, 0 at 3). Count = 2. Not equal.
        //
        // Let's try to put `(N-1)/2` ones at the beginning, then a '0', then `(N-1)/2` ones.
        // Example N=4: (4-1)/2 = 1. String: "1" + "0" + "11" = "1011".
        // "01" subsequences: (0 at 1, 1 at 2), (0 at 1, 1 at 3). Count = 2.
        // "10" subsequences: (1 at 0, 0 at 1). Count = 1. Not equal.
        //
        // The sample outputs are "1001" (N=4) and "010" (N=3).
        //
        // Let's analyze the counts of 0s and 1s in the sample outputs.
        // N=3, "010": two 0s, one 1.
        // N=4, "1001": two 0s, two 1s.
        //
        // It seems like we can construct a string by having a block of one character, then a block of the other, and then filling the rest.
        //
        // Consider the string: `(N-1)/2` zeros, followed by `1`, followed by `N - 1 - (N-1)/2` zeros.
        // This doesn't work.
        //
        // Let's try to construct a string with `(N-1)/2` zeros, then `1`, then `(N-1)/2` zeros.
        // This only works if N is odd.
        // If N=3, (3-1)/2 = 1. String: "0" + "1" + "0" = "010". This matches the sample!
        //
        // What about even N?
        // For N=4, (4-1)/2 = 1.
        // If we try "0" + "1" + "00" = "0100". "01"=1, "10"=2.
        // If we try "1" + "0" + "11" = "1011". "01"=2, "10"=1.
        //
        // The sample for N=4 is "1001".
        // This string has two 1s and two 0s.
        // It looks like `1` followed by `(N-2)/2` zeros, followed by `(N-2)/2` ones, followed by `1`.
        // For N=4, (N-2)/2 = 1. String: "1" + "0" + "1" + "1" = "1011". No, this is not "1001".
        //
        // Let's re-examine "1001" for N=4.
        // It has two 1s and two 0s.
        // It starts with '1', ends with '1'.
        // It has '0's in the middle.
        //
        // Consider the string: `1` followed by `(N-2)/2` zeros, followed by `(N-2)/2` zeros, followed by `1`.
        // For N=4, (N-2)/2 = 1. String: "1" + "0" + "0" + "1" = "1001". This matches the sample!
        //
        // Let's generalize this pattern:
        // For odd N: `(N-1)/2` zeros, then `1`, then `(N-1)/2` zeros.
        // Example N=3: (3-1)/2 = 1. String: "0" + "1" + "0" = "010".
        // Example N=5: (5-1)/2 = 2. String: "00" + "1" + "00" = "00100".
        // Let's check "00100" for N=5.
        // c0=4, c1=1.
        // "01" subsequences: (0 at 0, 1 at 2), (0 at 1, 1 at 2). Count = 2.
        // "10" subsequences: (1 at 2, 0 at 3), (1 at 2, 0 at 4). Count = 2. Equal!
        // This pattern works for odd N.
        //
        // For even N: `1` followed by `(N-2)/2` zeros, followed by `(N-2)/2` zeros, followed by `1`.
        // This means `1` + `(N-2)/2` zeros + `(N-2)/2` zeros + `1`.
        // Total length = 1 + (N-2)/2 + (N-2)/2 + 1 = 1 + N - 2 + 1 = N.
        // This structure is `1` + `N-2` zeros + `1`.
        // Example N=4: (4-2)/2 = 1. String: "1" + "0" + "0" + "1" = "1001".
        // Example N=6: (6-2)/2 = 2. String: "1" + "00" + "00" + "1" = "100001".
        // Let's check "100001" for N=6.
        // c0=4, c1=2.
        // "01" subsequences: (0 at 2, 1 at 5), (0 at 3, 1 at 5), (0 at 4, 1 at 5). Count = 3.
        // "10" subsequences: (1 at 0, 0 at 2), (1 at 0, 0 at 3), (1 at 0, 0 at 4). Count = 3. Equal!
        // This pattern works for even N.
        //
        // Let's verify the conditions:
        // 1. Count of "01" subsequences equals count of "10" subsequences.
        // 2. String has at least one '0' and one '1'.
        //
        // Case 1: N is odd. String is `(N-1)/2` zeros, then `1`, then `(N-1)/2` zeros.
        // Let `k = (N-1)/2`. The string is `0...0` (k times) + `1` + `0...0` (k times).
        // Total zeros = 2k. Total ones = 1.
        // The string looks like `00...0100...0`.
        // Any '01' subsequence must involve the single '1'.
        // The '1' is at index `k`.
        // Number of '0's before index `k` is `k`.
        // Number of '0's after index `k` is `k`.
        // A '01' subsequence is formed by a '0' at index `i` and '1' at index `j` where `i < j`.
        // Here, the only '1' is at index `k`.
        // So, we need '0's at index `i < k`. There are `k` such '0's.
        // This gives `k` "01" subsequences.
        // A '10' subsequence is formed by a '1' at index `i` and '0' at index `j` where `i < j`.
        // Here, the only '1' is at index `k`.
        // So, we need '0's at index `j > k`. There are `k` such '0's.
        // This gives `k` "10" subsequences.
        // So, the counts are equal (`k`).
        // Since N >= 3, `k = (N-1)/2 >= (3-1)/2 = 1`. So there are at least two '0's.
        // There is one '1'. So, both '0' and '1' exist.
        // This pattern works for odd N.
        //
        // Case 2: N is even. String is `1` + `(N-2)/2` zeros + `(N-2)/2` zeros + `1`.
        // Let `m = (N-2)/2`. The string is `1` + `0...0` (m times) + `0...0` (m times) + `1`.
        // This simplifies to `1` + `0...0` (2m times) + `1`.
        // Total length = 1 + 2m + 1 = 1 + (N-2) + 1 = N.
        // Total zeros = 2m = N-2. Total ones = 2.
        // The string looks like `100...001`.
        // The two '1's are at index 0 and index N-1.
        // The `N-2` zeros are at indices 1 to N-2.
        //
        // Let's count "01" subsequences.
        // A '0' is at index `i` (1 <= i <= N-2). A '1' is at index `j` (0 <= j <= N-1). We need `i < j`.
        // If the '0' is at index `i`, the possible '1's after it are:
        // - The '1' at index N-1. This is always after any '0' at index `i` (1 <= i <= N-2).
        //   So, for each of the `N-2` zeros, we can form a "01" with the last '1'. This gives `N-2` "01" subsequences.
        // - The '1' at index 0. This is never after any '0' at index `i` (1 <= i <= N-2).
        //
        // Let's count "10" subsequences.
        // A '1' is at index `i` (0 <= i <= N-1). A '0' is at index `j` (1 <= j <= N-2). We need `i < j`.
        // If the '1' is at index 0:
        //   The possible '0's after it are at indices 1 to N-2. There are `N-2` such '0's.
        //   This gives `N-2` "10" subsequences.
        // If the '1' is at index N-1:
        //   There are no '0's after it.
        //
        // So, the total count of "01" subsequences is `N-2`.
        // The total count of "10" subsequences is `N-2`.
        // The counts are equal.
        //
        // Since N >= 3, for even N, the minimum is N=4.
        // If N=4, `N-2 = 2`. String is "1001". Two '1's, two '0's. Both exist.
        // If N=6, `N-2 = 4`. String is "100001". Two '1's, four '0's. Both exist.
        // This pattern works for even N.
        //
        // Summary of construction:
        // If N is odd: print (N-1)/2 zeros, then '1', then (N-1)/2 zeros.
        // If N is even: print '1', then (N-2)/2 zeros, then (N-2)/2 zeros, then '1'.
        // This can be simplified for even N: print '1', then N-2 zeros, then '1'.
        //
        // Let's double check the even case construction:
        // String: '1' + (N-2 zeros) + '1'.
        // Example N=4: '1' + (2 zeros) + '1' = "1001". Correct.
        // Example N=6: '1' + (4 zeros) + '1' = "100001". Correct.
        //
        // Let's implement this.

        if (n % 2 != 0) { // N is odd
            int num_zeros = (n - 1) / 2;
            for (int i = 0; i < num_zeros; ++i) {
                std::cout << '0';
            }
            std::cout << '1';
            for (int i = 0; i < num_zeros; ++i) {
                std::cout << '0';
            }
            std::cout << "\n";
        } else { // N is even
            // The pattern is '1' followed by N-2 zeros, followed by '1'.
            std::cout << '1';
            for (int i = 0; i < n - 2; ++i) {
                std::cout << '0';
            }
            std::cout << '1';
            std::cout << "\n";
        }
    }
    return 0;
}