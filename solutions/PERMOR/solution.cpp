#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // The problem guarantees that a solution always exists.
        // A simple construction that works is to print numbers in decreasing order,
        // starting from N, then N-1, ..., 1.
        // Let's verify this construction: A_i = N - i + 1.
        // We need to check A_i != A_{i-1} | A_{i-2} for 3 <= i <= N.
        //
        // Consider the sequence: N, N-1, N-2, ..., 1.
        // A_i = N - i + 1
        // A_{i-1} = N - (i-1) + 1 = N - i + 2
        // A_{i-2} = N - (i-2) + 1 = N - i + 3
        //
        // We need to check if (N - i + 1) != (N - i + 2) | (N - i + 3) for 3 <= i <= N.
        //
        // Let's test with small N:
        // N=3: 3 2 1.
        // i=3: A_3=1, A_2=2, A_1=3. Check A_3 != A_2 | A_1. 1 != 2 | 3. 2 | 3 = 3. 1 != 3. OK.
        //
        // N=4: 4 3 2 1.
        // i=3: A_3=2, A_2=3, A_1=4. Check A_3 != A_2 | A_1. 2 != 3 | 4. 3 | 4 = 7. 2 != 7. OK.
        // i=4: A_4=1, A_3=2, A_2=3. Check A_4 != A_3 | A_2. 1 != 2 | 3. 2 | 3 = 3. 1 != 3. OK.
        //
        // N=5: 5 4 3 2 1.
        // i=3: A_3=3, A_2=4, A_1=5. Check A_3 != A_2 | A_1. 3 != 4 | 5. 4 | 5 = 5. 3 != 5. OK.
        // i=4: A_4=2, A_3=3, A_2=4. Check A_4 != A_3 | A_2. 2 != 3 | 4. 3 | 4 = 7. 2 != 7. OK.
        // i=5: A_5=1, A_4=2, A_3=3. Check A_5 != A_4 | A_3. 1 != 2 | 3. 2 | 3 = 3. 1 != 3. OK.
        //
        // The construction N, N-1, ..., 1 seems to work.
        // Let's try to prove it.
        // We need to show that for 3 <= i <= N, (N - i + 1) != (N - i + 2) | (N - i + 3).
        // Let x = N - i + 1. Then the condition is x != (x+1) | (x+2).
        //
        // Consider the binary representations of x, x+1, x+2.
        // If x is even, say x = ...0. Then x+1 = ...1, x+2 = ...10.
        // (x+1) | (x+2) = (...1) | (...10) = ...11.
        // If x is odd, say x = ...01. Then x+1 = ...10, x+2 = ...11.
        // (x+1) | (x+2) = (...10) | (...11) = ...11.
        // If x ends in ...00, then x+1 ends in ...01, x+2 ends in ...10.
        // (x+1) | (x+2) = (...01) | (...10) = ...11.
        //
        // In general, for any non-negative integer x, the bitwise OR of x+1 and x+2 will have at least the same bits set as x+1 and x+2.
        // Let's consider the most significant bit where x, x+1, x+2 differ.
        //
        // Case 1: x is even.
        // x = ...b0
        // x+1 = ...b1
        // x+2 = ...c0 (where c is the bit after b, possibly flipped if b was 1)
        //
        // Example: x = 4 (100)
        // x+1 = 5 (101)
        // x+2 = 6 (110)
        // (x+1) | (x+2) = 5 | 6 = 101 | 110 = 111 (7)
        // x = 4, (x+1)|(x+2) = 7. 4 != 7.
        //
        // Example: x = 2 (010)
        // x+1 = 3 (011)
        // x+2 = 4 (100)
        // (x+1) | (x+2) = 3 | 4 = 011 | 100 = 111 (7)
        // x = 2, (x+1)|(x+2) = 7. 2 != 7.
        //
        // Let's consider the bits.
        // If x has a 0 at some position k, and x+1 and x+2 also have 0s at that position, then the OR will have 0.
        // However, x+1 and x+2 are consecutive numbers.
        // At least one of them must have a 1 at a position where x has a 0, or vice versa.
        //
        // Consider the highest bit where x and x+1 differ. This is the lowest set bit of x+1.
        // Consider the highest bit where x+1 and x+2 differ. This is the lowest set bit of x+2.
        //
        // Let's consider the property that for any non-negative integer k, k | (k+1) >= k+1.
        // Also, k | (k+2) >= k+2.
        //
        // We need to show x != (x+1) | (x+2).
        //
        // If x+1 and x+2 have no common set bits that are not set in x, then the OR might be equal to x.
        // But this is unlikely for consecutive numbers.
        //
        // Let's consider the most significant bit (MSB) of x.
        // If MSB of x is at position k, then x is in range [2^k, 2^(k+1)-1].
        // x+1 and x+2 are also in this range or the next.
        //
        // If x+1 and x+2 are both less than 2^k, then their OR is also less than 2^k.
        // This happens if x+2 < 2^k. This implies x < 2^k - 2.
        // But x is in range [2^k, 2^(k+1)-1]. This is a contradiction.
        // So, at least one of x+1 or x+2 must have a bit set at or above the MSB of x.
        //
        // Let's consider the case where x+1 and x+2 are such that their OR is equal to x.
        // This means every bit set in x+1 or x+2 must also be set in x.
        // This is impossible because x+1 has at least one bit set that is not set in x (the lowest set bit of x+1).
        //
        // More formally, let k be the position of the least significant bit of x+1.
        // Then x+1 has a 1 at position k, and x has a 0 at position k.
        // So, (x+1) | (x+2) will have a 1 at position k.
        // Since x has a 0 at position k, x != (x+1) | (x+2).
        // This holds as long as x+1 is not 0. Since N >= 3, x = N-i+1 >= 1. So x+1 >= 2.
        //
        // The only edge case might be when x+1 or x+2 are very small.
        // The smallest possible value for x is when i=N, so x = N-N+1 = 1.
        // If x=1:
        // x=1 (01)
        // x+1=2 (10)
        // x+2=3 (11)
        // (x+1)|(x+2) = 2|3 = 10|11 = 11 (3).
        // x=1, (x+1)|(x+2)=3. 1 != 3. OK.
        //
        // The construction N, N-1, ..., 1 is indeed a valid permutation.
        //
        // Let's consider the sample outputs to see if there's a simpler pattern or if the problem setter intended a different construction.
        // N=3: 1 3 2.
        // i=3: A_3=2, A_2=3, A_1=1. Check A_3 != A_2 | A_1. 2 != 3 | 1. 3 | 1 = 3. 2 != 3. OK.
        // This is different from 3 2 1.
        //
        // N=4: 1 2 4 3.
        // i=3: A_3=4, A_2=2, A_1=1. Check A_3 != A_2 | A_1. 4 != 2 | 1. 2 | 1 = 3. 4 != 3. OK.
        // i=4: A_4=3, A_3=4, A_2=2. Check A_4 != A_3 | A_2. 3 != 4 | 2. 4 | 2 = 6. 3 != 6. OK.
        // This is different from 4 3 2 1.
        //
        // N=5: 2 1 5 3 4.
        // i=3: A_3=5, A_2=1, A_1=2. Check A_3 != A_2 | A_1. 5 != 1 | 2. 1 | 2 = 3. 5 != 3. OK.
        // i=4: A_4=3, A_3=5, A_2=1. Check A_4 != A_3 | A_2. 3 != 5 | 1. 5 | 1 = 5. 3 != 5. OK.
        // i=5: A_5=4, A_4=3, A_3=5. Check A_5 != A_4 | A_3. 4 != 3 | 5. 3 | 5 = 7. 4 != 7. OK.
        // This is different from 5 4 3 2 1.
        //
        // The sample outputs suggest a different construction.
        // Let's look at the sample outputs again:
        // N=3: 1 3 2
        // N=4: 1 2 4 3
        // N=5: 2 1 5 3 4
        //
        // It seems like they are trying to keep numbers small initially and then introduce larger numbers.
        //
        // Consider the construction: N, N-1, ..., 1. This is simple and proven correct.
        // The problem statement says "If multiple such permutations exist, you may print any."
        // So, N, N-1, ..., 1 should be acceptable.
        //
        // Let's re-check the constraints and problem statement.
        // "A_i != A_{i-1} | A_{i-2} for all 3 <= i <= N"
        //
        // What if we print N, N-1, ..., 1?
        // For N=3, output: 3 2 1.
        // For N=4, output: 4 3 2 1.
        // For N=5, output: 5 4 3 2 1.
        //
        // These are valid permutations. The sample outputs are just *one* possible solution.
        // The construction N, N-1, ..., 1 is the simplest to implement and prove.
        //
        // Let's consider the constraints again. N up to 10^5. Sum of N up to 10^6.
        // Printing N numbers takes O(N) time. Total time complexity O(Sum of N). This is efficient.
        // Space complexity O(N) to store the permutation, or O(1) if printed directly.
        //
        // Let's stick with the N, N-1, ..., 1 construction.
        //
        // Alternative construction idea from sample outputs:
        // N=3: 1 3 2. (1, N, N-1)
        // N=4: 1 2 4 3. (1, 2, N, N-1)
        // N=5: 2 1 5 3 4. (2, 1, N, N-2, N-1) - This doesn't look like a simple pattern.
        //
        // Let's try to construct a permutation that matches the sample outputs.
        // For N=3: 1 3 2.
        // For N=4: 1 2 4 3.
        // For N=5: 2 1 5 3 4.
        //
        // What if we print 1, 2, ..., N?
        // N=3: 1 2 3.
        // i=3: A_3=3, A_2=2, A_1=1. Check A_3 != A_2 | A_1. 3 != 2 | 1. 2 | 1 = 3. 3 != 3 is FALSE.
        // So 1, 2, ..., N does not work.
        //
        // The construction N, N-1, ..., 1 is simple and correct.
        // Let's implement that.
        
        for (int i = n; i >= 1; --i) {
            std::cout << i << (i == 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}