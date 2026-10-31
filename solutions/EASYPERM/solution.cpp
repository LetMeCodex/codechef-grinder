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
        // The goal is to minimize LCM(1+A_1, 2+A_2, ..., N+A_N).
        // To minimize LCM, we want the numbers (i + A_i) to be as small as possible
        // and share as many common factors as possible.
        //
        // Consider the sum i + A_i. If we can make these sums small and equal,
        // the LCM will be small.
        //
        // If we choose A_i = i, then i + A_i = 2*i. The LCM would be LCM(2, 4, 6, ..., 2N).
        // This is 2 * LCM(1, 2, 3, ..., N).
        //
        // If we choose A_i = N - i + 1 (a reversed permutation), then i + A_i = i + (N - i + 1) = N + 1.
        // In this case, all sums are N+1. The LCM would be LCM(N+1, N+1, ..., N+1) = N+1.
        // This seems like a very good candidate for minimization.
        //
        // Let's check the sample case N=2.
        // Permutation [1, 2]: sums are (1+1)=2, (2+2)=4. LCM(2, 4) = 4.
        // Permutation [2, 1]: sums are (1+2)=3, (2+1)=3. LCM(3, 3) = 3.
        // The reversed permutation [2, 1] gives LCM = N+1 = 2+1 = 3, which is minimal.
        //
        // Let's try N=3.
        // Reversed permutation [3, 2, 1]:
        // i=1, A_1=3: 1+3=4
        // i=2, A_2=2: 2+2=4
        // i=3, A_3=1: 3+1=4
        // LCM(4, 4, 4) = 4. This is N+1 = 3+1 = 4.
        //
        // Consider another permutation for N=3, e.g., [1, 2, 3]:
        // i=1, A_1=1: 1+1=2
        // i=2, A_2=2: 2+2=4
        // i=3, A_3=3: 3+3=6
        // LCM(2, 4, 6) = 12. Much larger.
        //
        // Consider permutation [2, 3, 1] for N=3:
        // i=1, A_1=2: 1+2=3
        // i=2, A_2=3: 2+3=5
        // i=3, A_3=1: 3+1=4
        // LCM(3, 5, 4) = 60.
        //
        // It appears that the permutation A_i = N - i + 1 (i.e., the reversed sequence)
        // results in i + A_i = i + (N - i + 1) = N + 1 for all i.
        // The LCM of N+1 repeated N times is N+1.
        //
        // Can we achieve a smaller LCM?
        // The smallest possible value for any i + A_i is 1+1=2.
        // The largest possible value for any i + A_i is N+N=2N.
        // The LCM must be at least the maximum value in the set, which is at most 2N.
        //
        // If N+1 is prime, then LCM(N+1, N+1, ..., N+1) = N+1.
        // If N+1 is composite, say N+1 = p*q, then LCM is still N+1.
        //
        // The strategy of reversing the permutation A_i = N - i + 1 seems to consistently produce
        // the sum N+1 for all i. This makes the LCM equal to N+1.
        //
        // Let's consider the case where N is even.
        // If N is even, say N=4. Reversed permutation [4, 3, 2, 1].
        // i=1, A_1=4: 1+4=5
        // i=2, A_2=3: 2+3=5
        // i=3, A_3=2: 3+2=5
        // i=4, A_4=1: 4+1=5
        // LCM(5, 5, 5, 5) = 5. This is N+1 = 4+1 = 5.
        //
        // What if we swap two elements in the reversed permutation?
        // For N=4, reversed is [4, 3, 2, 1]. Sums are all 5. LCM is 5.
        // Let's swap A_1 and A_2: [3, 4, 2, 1].
        // i=1, A_1=3: 1+3=4
        // i=2, A_2=4: 2+4=6
        // i=3, A_3=2: 3+2=5
        // i=4, A_4=1: 4+1=5
        // LCM(4, 6, 5, 5) = LCM(4, 6, 5) = 60. This is much larger.
        //
        // It seems the reversed permutation is indeed optimal.
        //
        // However, the problem statement says "Construct *any* permutation".
        // The sample output for N=2 is "2 1". This is indeed the reversed permutation.
        //
        // Let's consider the constraints: 2 <= N <= 1000.
        // The reversed permutation strategy is simple and seems to yield N+1.
        //
        // What if N is odd?
        // N=3. Reversed [3, 2, 1]. Sums: 1+3=4, 2+2=4, 3+1=4. LCM=4. N+1=4.
        //
        // The strategy A_i = N - i + 1 works for all N >= 2.
        //
        // Is there any other simple permutation that might be better?
        // Consider N=4. Reversed [4, 3, 2, 1] gives LCM=5.
        // What about [1, 2, 3, 4]? Sums: 1+1=2, 2+2=4, 3+3=6, 4+4=8. LCM(2,4,6,8)=24.
        // What about [2, 1, 4, 3]?
        // i=1, A_1=2: 1+2=3
        // i=2, A_2=1: 2+1=3
        // i=3, A_3=4: 3+4=7
        // i=4, A_4=3: 4+3=7
        // LCM(3, 3, 7, 7) = LCM(3, 7) = 21. Still larger than 5.
        //
        // The strategy of making all sums equal to N+1 is very strong.
        //
        // Let's consider the case where N is even.
        // If N is even, we can try to pair i with N-i+1.
        // For example, if N=4, we have pairs (1,4) and (2,3).
        // If we set A_1=4, A_2=3, A_3=2, A_4=1, we get sums 5, 5, 5, 5. LCM=5.
        //
        // What if we try to make sums equal to N?
        // For N=4, can we make sums equal to 4?
        // i=1, A_1=? -> 1+A_1=4 => A_1=3
        // i=2, A_2=? -> 2+A_2=4 => A_2=2
        // i=3, A_3=? -> 3+A_3=4 => A_3=1
        // i=4, A_4=? -> 4+A_4=4 => A_4=0 (not allowed, must be 1 to N)
        // So we cannot make all sums equal to N.
        //
        // What if we try to make sums equal to N+1?
        // i=1, A_1=? -> 1+A_1=N+1 => A_1=N
        // i=2, A_2=? -> 2+A_2=N+1 => A_2=N-1
        // ...
        // i=N, A_N=? -> N+A_N=N+1 => A_N=1
        // This gives the permutation A = [N, N-1, ..., 1], which is the reversed permutation.
        //
        // This strategy seems robust.
        //
        // Let's consider the case where N is even.
        // For N=2, output is 2 1.
        // For N=4, reversed is 4 3 2 1. Sums are 5, 5, 5, 5. LCM=5.
        //
        // What if we try to make sums equal to N+2?
        // For N=4, N+2=6.
        // i=1, A_1=? -> 1+A_1=6 => A_1=5 (not allowed)
        //
        // The strategy of reversing the permutation seems to be the simplest and most effective.
        //
        // Let's consider the problem constraints again. N <= 1000.
        // The reversed permutation is A = [N, N-1, ..., 1].
        // The sums are i + A_i = i + (N - i + 1) = N + 1.
        // The LCM is LCM(N+1, N+1, ..., N+1) = N+1.
        //
        // Is there any other permutation that can achieve a smaller LCM?
        // The smallest possible sum is 1+1=2. The largest is N+N=2N.
        // The LCM must be at least the maximum value in the set {1+A_1, ..., N+A_N}.
        // The maximum value is at most 2N.
        // So, the LCM is at least max(1+A_i).
        //
        // If N is even, say N=4. Reversed gives LCM=5.
        // What if we try to make sums smaller?
        // Consider the permutation [2, 1, 4, 3] for N=4.
        // Sums: 1+2=3, 2+1=3, 3+4=7, 4+3=7. LCM(3, 3, 7, 7) = 21.
        //
        // Consider the permutation [2, 3, 4, 1] for N=4.
        // Sums: 1+2=3, 2+3=5, 3+4=7, 4+1=5. LCM(3, 5, 7, 5) = LCM(3, 5, 7) = 105.
        //
        // Consider the permutation [1, 2, 3, 4] for N=4.
        // Sums: 1+1=2, 2+2=4, 3+3=6, 4+4=8. LCM(2, 4, 6, 8) = 24.
        //
        // The reversed permutation strategy seems to be the best.
        //
        // However, there's a slight variation for even N.
        // If N is even, say N=4.
        // Reversed: [4, 3, 2, 1]. Sums: 5, 5, 5, 5. LCM=5.
        //
        // What if we swap adjacent elements in the reversed permutation?
        // For N=4, reversed is [4, 3, 2, 1].
        // Swap A_1 and A_2: [3, 4, 2, 1]. Sums: 1+3=4, 2+4=6, 3+2=5, 4+1=5. LCM(4, 6, 5, 5) = 60.
        //
        // What if we swap A_i and A_{i+1} for i=1, 3, 5, ...?
        // For N=4, this means swapping A_1 and A_2, and A_3 and A_4.
        // Reversed: [4, 3, 2, 1].
        // Swap A_1, A_2: [3, 4, 2, 1].
        // Swap A_3, A_4: [3, 4, 1, 2].
        // Sums:
        // i=1, A_1=3: 1+3=4
        // i=2, A_2=4: 2+4=6
        // i=3, A_3=1: 3+1=4
        // i=4, A_4=2: 4+2=6
        // LCM(4, 6, 4, 6) = LCM(4, 6) = 12. Still larger than 5.
        //
        // The strategy of making all sums equal to N+1 is very compelling.
        //
        // Let's re-examine the sample case N=2. Output: 2 1.
        // This is indeed the reversed permutation.
        //
        // What if N is even?
        // For N=2, reversed is [2, 1]. Sums: 1+2=3, 2+1=3. LCM=3. N+1=3.
        //
        // Consider N=4. Reversed is [4, 3, 2, 1]. Sums: 5, 5, 5, 5. LCM=5. N+1=5.
        //
        // What if we try to make sums equal to N?
        // For N=4, we need sums to be 4.
        // i=1, A_1=3
        // i=2, A_2=2
        // i=3, A_3=1
        // i=4, A_4=0 (not allowed)
        //
        // What if we try to make sums equal to N+1?
        // For N=4, we need sums to be 5.
        // i=1, A_1=4
        // i=2, A_2=3
        // i=3, A_3=2
        // i=4, A_4=1
        // This is the reversed permutation [4, 3, 2, 1].
        //
        // What if we try to make sums equal to N+2?
        // For N=4, we need sums to be 6.
        // i=1, A_1=5 (not allowed)
        //
        // It seems the reversed permutation is always optimal.
        //
        // However, there is a common trick for even N.
        // If N is even, we can construct the permutation by swapping adjacent elements in the sequence 1, 2, ..., N.
        // For N=2: [2, 1]. Sums: 1+2=3, 2+1=3. LCM=3.
        // For N=4: [2, 1, 4, 3].
        // i=1, A_1=2: 1+2=3
        // i=2, A_2=1: 2+1=3
        // i=3, A_3=4: 3+4=7
        // i=4, A_4=3: 4+3=7
        // LCM(3, 3, 7, 7) = LCM(3, 7) = 21.
        // This is worse than the reversed permutation [4, 3, 2, 1] which gives LCM=5.
        //
        // Let's consider the sample explanation for N=2:
        // Permutation [2, 1]. LCM(1+2, 2+1) = LCM(3, 3) = 3.
        // This is N+1.
        //
        // The problem asks for *any* permutation that minimizes the LCM.
        // The reversed permutation A_i = N - i + 1 gives sums i + A_i = N + 1 for all i.
        // The LCM is N+1.
        //
        // Let's consider the case where N is even.
        // If N is even, say N=2k.
        // Consider the permutation: [2, 1, 4, 3, 6, 5, ..., 2k, 2k-1].
        // For i = 1, 3, 5, ..., 2k-1: A_i = i+1.
        //   i + A_i = i + (i+1) = 2i + 1.
        // For i = 2, 4, 6, ..., 2k: A_i = i-1.
        //   i + A_i = i + (i-1) = 2i - 1.
        //
        // Example N=4: [2, 1, 4, 3]
        // i=1, A_1=2: 1+2=3
        // i=2, A_2=1: 2+1=3
        // i=3, A_3=4: 3+4=7
        // i=4, A_4=3: 4+3=7
        // LCM(3, 3, 7, 7) = 21.
        //
        // This permutation strategy for even N is:
        // For i from 1 to N, if i is odd, A_i = i+1. If i is even, A_i = i-1.
        // This is equivalent to swapping adjacent elements: (1,2), (3,4), ..., (N-1, N).
        // The permutation is [2, 1, 4, 3, ..., N, N-1].
        //
        // Let's check the sums for this permutation:
        // For i = 1, 3, 5, ..., N-1:
        //   A_i = i+1
        //   i + A_i = i + (i+1) = 2i + 1
        // For i = 2, 4, 6, ..., N:
        //   A_i = i-1
        //   i + A_i = i + (i-1) = 2i - 1
        //
        // The set of sums is {3, 3, 7, 7, 11, 11, ..., 2(N-1)+1, 2(N-1)-1}
        // which is {3, 3, 7, 7, ..., 2N-1, 2N-3}.
        //
        // For N=2: [2, 1]. Sums: 1+2=3, 2+1=3. LCM(3,3)=3.
        // For N=4: [2, 1, 4, 3]. Sums: 1+2=3, 2+1=3, 3+4=7, 4+3=7. LCM(3,3,7,7)=21.
        //
        // The reversed permutation for N=4 is [4, 3, 2, 1]. Sums: 5, 5, 5, 5. LCM=5.
        //
        // It seems the reversed permutation is always optimal.
        //
        // Let's consider the problem statement again. "Construct *any* permutation".
        // The simplest strategy that seems to minimize the LCM is to make all sums i + A_i equal.
        // The only way to make all sums equal is if i + A_i = C for some constant C.
        // If i + A_i = C, then A_i = C - i.
        // Since A is a permutation of 1 to N, A_i must be between 1 and N.
        // So, 1 <= C - i <= N for all i from 1 to N.
        //
        // For i=1: 1 <= C - 1 <= N  =>  2 <= C <= N+1
        // For i=N: 1 <= C - N <= N  =>  N+1 <= C <= 2N
        //
        // Combining these, we need C to satisfy:
        // max(2, N+1) <= C <= min(N+1, 2N)
        //
        // If N >= 2, then N+1 >= 3, so max(2, N+1) = N+1.
        // If N >= 2, then N+1 <= 2N, so min(N+1, 2N) = N+1.
        //
        // Thus, the only possible value for C that allows A_i = C - i to be a permutation of 1 to N is C = N+1.
        //
        // If C = N+1, then A_i = N+1 - i.
        // For i=1, A_1 = N+1 - 1 = N.
        // For i=2, A_2 = N+1 - 2 = N-1.
        // ...
        // For i=N, A_N = N+1 - N = 1.
        //
        // This is exactly the reversed permutation: [N, N-1, ..., 1].
        //
        // The sums are i + A_i = i + (N+1 - i) = N+1 for all i.
        // The LCM is LCM(N+1, N+1, ..., N+1) = N+1.
        //
        // This strategy seems to be the only way to make all sums equal, and it yields the LCM N+1.
        //
        // Is it possible to achieve an LCM smaller than N+1?
        // The LCM must be at least the maximum value in the set {1+A_1, ..., N+A_N}.
        // The maximum possible value for any i+A_i is N+N = 2N.
        // The minimum possible value for any i+A_i is 1+1 = 2.
        //
        // If N+1 is prime, then any set of numbers whose LCM is N+1 must contain N+1.
        // If the set {1+A_1, ..., N+A_N} contains N+1, then the LCM is at least N+1.
        //
        // If N+1 is composite, say N+1 = p*q.
        // The reversed permutation gives LCM = N+1.
        //
        // Consider N=6. N+1=7 (prime). Reversed permutation [6, 5, 4, 3, 2, 1].
        // Sums: 7, 7, 7, 7, 7, 7. LCM=7.
        //
        // Consider N=8. N+1=9 (composite). Reversed permutation [8, 7, 6, 5, 4, 3, 2, 1].
        // Sums: 9, 9, 9, 9, 9, 9, 9, 9. LCM=9.
        //
        // It seems the reversed permutation is indeed the optimal strategy.
        //
        // The problem asks for *any* permutation. The reversed permutation is simple to construct.
        //
        // Let's consider the case where N is even.
        // The permutation [2, 1, 4, 3, ..., N, N-1] gives sums:
        // {3, 3, 7, 7, ..., 2N-1, 2N-3}.
        // For N=4, sums are {3, 3, 7, 7}. LCM = 21. Reversed gives LCM=5.
        //
        // The reversed permutation is the most straightforward and seems to be optimal.
        //
        // The output format requires printing the permutation.
        // For N, we need to print N N-1 N-2 ... 1.
        //
        // Example N=2: print 2 1.
        // Example N=3: print 3 2 1.
        // Example N=4: print 4 3 2 1.
        //
        // This matches the sample output for N=2.
        //
        // The logic seems sound. The reversed permutation makes all sums equal to N+1,
        // resulting in an LCM of N+1. It's hard to imagine achieving a smaller LCM,
        // as the LCM must be at least the maximum element in the set of sums,
        // and N+1 is a relatively small value in the range [2, 2N].
        //
        // The constraints are T <= 1000 and N <= 1000.
        // Constructing the reversed permutation takes O(N) time.
        // Printing it takes O(N) time.
        // Total time per test case is O(N).
        // Total time for T test cases is O(T*N), which is at most 1000 * 1000 = 10^6 operations, well within the time limit.
        // Space complexity is O(N) to store the permutation if needed, or O(1) if printed directly.
        // We can print directly.

        for (int i = n; i >= 1; --i) {
            std::cout << i << (i == 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}