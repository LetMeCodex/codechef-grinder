#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // The problem asks for the minimum possible final score.
        // We start with S = {0, 1, 2, ..., N}. N is even.
        // We perform operations until S has only one element.
        // In each operation, we remove X, Y (distinct), add max(X, Y) to score,
        // and reinsert X & Y if it's not already in S.

        // To minimize the score, we want to maximize the number of times we
        // add small values to the score, and minimize the number of times
        // we add large values.
        // The operation adds max(X, Y) to the score.
        // The operation also potentially reinserts X & Y.

        // Consider the elements from N down to 0.
        // If we pick X and Y such that X & Y is already present, we don't reinsert.
        // If we pick X and Y such that X & Y is not present, we reinsert it.

        // Let's analyze the goal: to have a single element remaining.
        // We start with N+1 elements. We perform (N+1) - 1 = N operations.
        // Each operation removes 2 elements and adds at most 1 element back.
        // Net change in set size per operation is -1.
        // So, N operations reduce the size from N+1 to 1.

        // To minimize the score, we want to pair larger numbers with smaller numbers
        // such that the larger number is added to the score, and the bitwise AND
        // is a number that is either already present or is small.

        // Consider the largest number, N.
        // If we pair N with any other number Y, we add N to the score.
        // To minimize the score, we want to avoid adding N to the score if possible.
        // However, N must be removed at some point.

        // Let's think about the final remaining element.
        // If the final element is 0, it means all other numbers eventually got paired up
        // and their bitwise ANDs were either 0 or other numbers that were also paired up.

        // Consider pairing N with N-1.
        // Score increases by N.
        // N & (N-1) is N-1 if N is a power of 2, or something else.
        // Example N=2: S={0,1,2}.
        // Pair 1, 2. Score += 2. 1&2 = 0. Set becomes {0}. Final score 2.
        // Pair 0, 1. Score += 1. 0&1 = 0. Set becomes {0,2}.
        // Pair 0, 2. Score += 2. 0&2 = 0. Set becomes {0,1}.
        // Pair 1, 2. Score += 2. 1&2 = 0. Set becomes {0}. Final score 2.

        // Example N=4: S={0,1,2,3,4}.
        // Goal: minimize score.
        // We need to perform 4 operations.
        // If we pair 4 with something, score += 4.
        // If we pair 3 with something, score += 3.
        // If we pair 2 with something, score += 2.
        // If we pair 1 with something, score += 1.
        // If we pair 0 with something, score += 0.

        // Let's try to keep 0 as the final element.
        // To do this, we need to ensure that whenever we pick X, Y, their X & Y is either 0 or already present.
        // If we can always make X & Y = 0, then 0 will always be in the set and never removed.
        // This strategy seems promising for minimizing the score.

        // Consider pairing numbers in pairs (i, i+1) for i = 1, 3, 5, ..., N-1.
        // For N=2: S={0,1,2}. Pair (1,2). Score += 2. 1&2=0. Set={0}. Final score 2.
        // For N=4: S={0,1,2,3,4}.
        // Pair (1,2). Score += 2. 1&2=0. Set={0,3,4}.
        // Pair (3,4). Score += 4. 3&4=0. Set={0}. Final score 2+4=6.
        // This strategy seems to work for N=2 and N=4.

        // Let's verify this strategy:
        // Pair (1, 2), (3, 4), ..., (N-1, N).
        // For each pair (2k-1, 2k) where k = 1, 2, ..., N/2:
        // - Remove 2k-1 and 2k.
        // - Add max(2k-1, 2k) = 2k to the score.
        // - Calculate (2k-1) & (2k).
        //   - If 2k-1 is odd and 2k is even, their binary representations differ in the last bit.
        //   - For example, 1 (01) & 2 (10) = 0.
        //   - 3 (11) & 4 (100) = 0.
        //   - 5 (101) & 6 (110) = 4 (100). This is not 0.
        //   - So, (2k-1) & (2k) is not always 0.

        // The strategy of pairing (2k-1, 2k) is not guaranteed to result in X&Y=0.
        // If X&Y is not 0, it might be a new number that gets inserted.

        // Let's reconsider the goal: minimize the score.
        // The score is the sum of max(X, Y) over all operations.
        // We want to pick pairs such that the maximum is as small as possible.

        // Consider the numbers from N down to 1.
        // N must be removed. If we pair N with Y, score += N.
        // N-1 must be removed. If we pair N-1 with Y, score += N-1.
        // ...
        // 1 must be removed. If we pair 1 with Y, score += 1.
        // 0 will remain if it's never picked, or if it's picked and its AND partner is 0.

        // What if we pair N with 0? Score += N. N & 0 = 0. Set becomes {1, 2, ..., N-1}.
        // Then pair N-1 with 0? Score += N-1. (N-1) & 0 = 0. Set becomes {1, 2, ..., N-2}.
        // This strategy seems to remove all numbers from N down to 1, adding them to the score,
        // and always leaving 0 in the set.
        // The total score would be N + (N-1) + ... + 1 = N*(N+1)/2.
        // This is likely not minimal.

        // Let's look at the sample cases again.
        // N=2: S={0,1,2}. Output: 2.
        // Our strategy: Pair (1,2). Score += 2. 1&2=0. Set={0}. Final score 2. This matches.

        // N=4: S={0,1,2,3,4}. Output: 6.
        // Our strategy: Pair (1,2). Score += 2. 1&2=0. Set={0,3,4}.
        // Pair (3,4). Score += 4. 3&4=0. Set={0}. Final score 2+4=6. This matches.

        // N=50: S={0, ..., 50}. Output: 650.
        // Let's try our strategy:
        // Pair (1,2). Score += 2. 1&2=0.
        // Pair (3,4). Score += 4. 3&4=0.
        // ...
        // Pair (49,50). Score += 50. 49&50 = 48.
        // Wait, 49 is 110001, 50 is 110010. 49&50 = 110000 = 48.
        // So, if we pair (49, 50), score += 50. Set becomes {0, ..., 48, 49, 50} - {49, 50} + {48} = {0, ..., 48}.
        // This means 48 is now in the set.
        // This strategy is problematic because X&Y might be a number that was supposed to be paired later.

        // Let's re-examine the operation:
        // Remove X, Y. Add max(X, Y) to score. Reinsert X & Y if not present.
        // The set size decreases by 1.
        // We start with N+1 elements. We need N operations to reach 1 element.

        // Consider the numbers from N down to 1.
        // N must be removed. If we pair N with Y, score += N.
        // N-1 must be removed. If we pair N-1 with Y, score += N-1.
        // ...
        // 1 must be removed. If we pair 1 with Y, score += 1.
        // 0 is special. If 0 is always present, it can be used as a partner.

        // What if we pair N with N-1? Score += N. N & (N-1) = N-1 (if N is power of 2) or something else.
        // If N=4, S={0,1,2,3,4}.
        // Pair (3,4). Score += 4. 3&4=0. Set={0,1,2}.
        // Pair (1,2). Score += 2. 1&2=0. Set={0}. Final score 6.
        // This strategy seems to be: pair (N-1, N), then (N-3, N-2), ..., (1, 2).
        // For N=4: (3,4) -> score 4, 3&4=0. Set={0,1,2}. Then (1,2) -> score 2, 1&2=0. Set={0}. Total 6.
        // For N=2: (1,2) -> score 2, 1&2=0. Set={0}. Total 2.
        // For N=6: S={0,1,2,3,4,5,6}.
        // Pair (5,6). Score += 6. 5&6 = 4. Set={0,1,2,3,4}.
        // Pair (3,4). Score += 4. 3&4 = 0. Set={0,1,2}.
        // Pair (1,2). Score += 2. 1&2 = 0. Set={0}.
        // Total score = 6 + 4 + 2 = 12.

        // Let's check N=50.
        // Pairs: (49,50), (47,48), ..., (1,2).
        // Score += 50. 49&50 = 48. Set={0,1,...,48}.
        // Score += 48. 47&48 = 48. Set={0,1,...,47}.
        // Score += 46. 45&46 = 44. Set={0,1,...,45}.
        // This is not working as expected. The bitwise AND is not always 0.

        // The key must be that N is even.
        // Consider the numbers from N down to 1.
        // We need to perform N operations.
        // The total score is the sum of N numbers.
        // To minimize the sum, we want these N numbers to be as small as possible.

        // Let's consider the numbers that will be added to the score.
        // These are the `max(X, Y)` values.
        // The numbers that are NOT added to the score are the `X & Y` values that are reinserted.

        // If we can always ensure that X & Y is already present, we don't add anything back.
        // This means we are effectively removing two elements and adding one to the score.
        // This is the ideal scenario for reducing set size.

        // Consider the strategy:
        // Pair N with N-1. Score += N. N & (N-1) = N-1 if N is power of 2.
        // If N is not a power of 2, N & (N-1) is the number N with its least significant bit flipped to 0.
        // Example N=6 (110). N-1=5 (101). N&(N-1) = 4 (100).
        // If we pair (5,6), score += 6. 5&6=4. Set={0,1,2,3,4}.
        // Now we have {0,1,2,3,4}. N'=4.
        // Pair (3,4). Score += 4. 3&4=0. Set={0,1,2}.
        // Now we have {0,1,2}. N''=2.
        // Pair (1,2). Score += 2. 1&2=0. Set={0}.
        // Total score = 6 + 4 + 2 = 12.

        // This strategy seems to be:
        // Take the largest available pair (i, i+1) where i is odd.
        // Remove i, i+1. Add i+1 to score. Reinsert i & (i+1).
        // Repeat until only one element remains.

        // Let's trace N=50.
        // S = {0, 1, ..., 50}.
        // 1. Pair (49, 50). Score += 50. 49 & 50 = 48. S = {0, ..., 48}.
        // 2. Pair (47, 48). Score += 48. 47 & 48 = 48. S = {0, ..., 47}.
        // 3. Pair (45, 46). Score += 46. 45 & 46 = 44. S = {0, ..., 45} U {44}. Wait, 44 is already there. S = {0, ..., 45}.
        // 4. Pair (43, 44). Score += 44. 43 & 44 = 40. S = {0, ..., 43} U {40}. Wait, 40 is already there. S = {0, ..., 43}.
        // This is not right. The set is {0, 1, ..., N}. When we remove X, Y and reinsert X&Y, the new set is S \ {X, Y} U {X&Y}.

        // Let's retrace N=6. S={0,1,2,3,4,5,6}.
        // 1. Pair (5,6). Score += 6. 5&6 = 4. S = {0,1,2,3,4}.
        // 2. Pair (3,4). Score += 4. 3&4 = 0. S = {0,1,2}.
        // 3. Pair (1,2). Score += 2. 1&2 = 0. S = {0}.
        // Final score = 6 + 4 + 2 = 12.

        // Let's retrace N=4. S={0,1,2,3,4}.
        // 1. Pair (3,4). Score += 4. 3&4 = 0. S = {0,1,2}.
        // 2. Pair (1,2). Score += 2. 1&2 = 0. S = {0}.
        // Final score = 4 + 2 = 6.

        // Let's retrace N=2. S={0,1,2}.
        // 1. Pair (1,2). Score += 2. 1&2 = 0. S = {0}.
        // Final score = 2.

        // The strategy seems to be:
        // Repeatedly pick the largest two available numbers X, Y such that X = Y-1.
        // Add Y to the score.
        // Reinsert X & Y.
        // This process continues until only one element is left.
        // Since N is even, we can pair (N-1, N), (N-3, N-2), ..., (1, 2).
        // The numbers added to the score are N, N-2, N-4, ..., 2.
        // The sum is N + (N-2) + ... + 2.
        // This is an arithmetic progression with first term 2, last term N, and common difference 2.
        // Number of terms = (N - 2)/2 + 1 = N/2 - 1 + 1 = N/2.
        // Sum = (Number of terms / 2) * (First term + Last term)
        // Sum = (N/2 / 2) * (2 + N) = (N/4) * (N+2). This is not an integer if N is not divisible by 4.
        // Let's use the formula for sum of first k even numbers: 2 + 4 + ... + 2k = k(k+1).
        // Here, the terms are 2, 4, ..., N. So 2k = N => k = N/2.
        // The sum is (N/2) * (N/2 + 1).

        // Let's check this formula:
        // N=2: Sum = (2/2) * (2/2 + 1) = 1 * (1 + 1) = 2. Correct.
        // N=4: Sum = (4/2) * (4/2 + 1) = 2 * (2 + 1) = 2 * 3 = 6. Correct.
        // N=50: Sum = (50/2) * (50/2 + 1) = 25 * (25 + 1) = 25 * 26.
        // 25 * 26 = 25 * (25 + 1) = 625 + 25 = 650. Correct.

        // Why does this strategy work?
        // When we pair (i, i+1) where i is odd, i+1 is even.
        // i in binary ends with 1. i+1 in binary ends with 0.
        // i = ...1
        // i+1 = ...0
        // i & (i+1) will have the last bit as 0.
        // Example:
        // i=1 (01), i+1=2 (10). 1&2=0.
        // i=3 (11), i+1=4 (100). 3&4=0.
        // i=5 (101), i+1=6 (110). 5&6=4 (100).
        // i=7 (111), i+1=8 (1000). 7&8=0.
        // i=9 (1001), i+1=10 (1010). 9&10=8 (1000).

        // The claim that (i & (i+1)) is always 0 for odd i is FALSE.
        // However, the strategy of pairing (N-1, N), (N-3, N-2), ..., (1, 2) seems to be optimal.
        // Let's analyze the reinsertion.
        // When we pair (i, i+1), we add i+1 to the score.
        // We reinsert i & (i+1).
        // The set initially is {0, 1, ..., N}.
        // After pairing (N-1, N): S = {0, 1, ..., N-2} U {(N-1)&N}.
        // The number (N-1)&N is always less than or equal to N-2.
        // Proof:
        // Let N = 2k. N-1 = 2k-1.
        // N = ...b_m ... b_1 0
        // N-1 = ...b_m ... b_1 0 - 1.
        // If b_1 is 0, N = ...00. N-1 = ...0(-1) -> ...(-1)1.
        // If N = ...X00, N-1 = ...X(-1)1.
        // If N = ...X10, N-1 = ...X01.
        // If N = ...X0, N-1 = ...X-1.
        // Let's look at the bits.
        // N = b_p ... b_1 b_0
        // N-1: Find the rightmost '1' bit in N. Let it be at position k.
        // N = ... X 1 00...0 (k zeros)
        // N-1 = ... X 0 11...1 (k ones)
        // N & (N-1) = ... X 0 00...0. This is N with the rightmost '1' bit flipped to '0'.
        // This value is strictly less than N.
        // Is it always less than or equal to N-2?
        // If N = 2 (binary 10), N-1 = 1 (binary 01). N & (N-1) = 0. 0 <= 2-2 = 0. Yes.
        // If N = 4 (binary 100), N-1 = 3 (binary 011). N & (N-1) = 0. 0 <= 4-2 = 2. Yes.
        // If N = 6 (binary 110), N-1 = 5 (binary 101). N & (N-1) = 4 (binary 100). 4 <= 6-2 = 4. Yes.
        // If N = 8 (binary 1000), N-1 = 7 (binary 0111). N & (N-1) = 0. 0 <= 8-2 = 6. Yes.
        // If N = 10 (binary 1010), N-1 = 9 (binary 1001). N & (N-1) = 8 (binary 1000). 8 <= 10-2 = 8. Yes.
        // If N = 12 (binary 1100), N-1 = 11 (binary 1011). N & (N-1) = 8 (binary 1000). 8 <= 12-2 = 10. Yes.

        // It seems that (N-1) & N is always <= N-2.
        // Let's prove this.
        // N is even. N = ...b_1 0.
        // N-1 = ...b_1 0 - 1.
        // If b_1 = 0, N = ...00. N-1 = ...(-1)1.
        // If N = ...X00, N-1 = ...X-11.
        // N & (N-1) = ...X00. This is N. This is wrong.
        // Let's use the property: N & (N-1) is N with the rightmost set bit cleared.
        // N is even, so its last bit is 0.
        // N = ...b_k 1 0...0 (k zeros, b_k is the rightmost 1)
        // N-1 = ...b_k 0 1...1 (k ones)
        // N & (N-1) = ...b_k 0 0...0.
        // This value is N - 2^k.
        // We need to show N - 2^k <= N-2.
        // This means -2^k <= -2, or 2^k >= 2.
        // This is true if k >= 1.
        // The rightmost set bit in N must exist since N >= 2.
        // If N=2 (10), k=1. N & (N-1) = 2 - 2^1 = 0. 0 <= 2-2=0.
        // If N=4 (100), k=2. N & (N-1) = 4 - 2^2 = 0. 0 <= 4-2=2.
        // If N=6 (110), k=1. N & (N-1) = 6 - 2^1 = 4. 4 <= 6-2=4.
        // If N=8 (1000), k=3. N & (N-1) = 8 - 2^3 = 0. 0 <= 8-2=6.
        // So, (N-1) & N is always <= N-2.
        // This means when we pair (N-1, N), the reinserted element (N-1)&N is already present in the set {0, 1, ..., N-2}.
        // So, the set becomes {0, 1, ..., N-2}.
        // Then we pair (N-3, N-2). Score += N-2. (N-3)&(N-2) <= N-4.
        // The set becomes {0, 1, ..., N-4}.
        // This continues until we pair (1, 2). Score += 2. 1&2=0. Set becomes {0}.

        // The numbers added to the score are N, N-2, N-4, ..., 2.
        // This is the sum of even numbers from 2 to N.
        // Sum = 2 + 4 + ... + N.
        // Let N = 2k. Sum = 2 + 4 + ... + 2k = 2 * (1 + 2 + ... + k) = 2 * (k * (k+1) / 2) = k * (k+1).
        // Since k = N/2, the sum is (N/2) * (N/2 + 1).

        long long k = n / 2;
        long long result = k * (k + 1);
        std::cout << result << "\n";
    }
    return 0;
}