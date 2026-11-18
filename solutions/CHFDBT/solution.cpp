#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        // The condition F(X) = F(2*X) implies that for any X,
        // F(X) = F(2X) = F(4X) = F(8X) = ...
        // This means that F(k) will have the same value for all k that are
        // powers of 2 multiplied by some base value.
        // To maximize the number of distinct elements, we want to assign
        // different values to F(k) whenever possible.
        //
        // Consider the binary representation of numbers.
        // If X has a binary representation ending in '1', then 2*X will have
        // a binary representation ending in '0'.
        // For example, X = 3 (binary 11), 2*X = 6 (binary 110). F(3) = F(6).
        // X = 5 (binary 101), 2*X = 10 (binary 1010). F(5) = F(10).
        //
        // The condition F(X) = F(2*X) essentially means that the value of F(k)
        // is determined by the odd part of k.
        // Let k = odd_part * 2^p. Then F(k) = F(odd_part * 2^p) = F(odd_part * 2^(p-1)) = ... = F(odd_part).
        // So, F(k) depends only on the largest odd divisor of k.
        //
        // To maximize distinct values in F(1), F(2), ..., F(N), we should try to
        // make F(odd_part) distinct for as many distinct odd_parts as possible
        // that are less than or equal to N.
        //
        // The odd parts of numbers from 1 to N are the odd numbers themselves
        // that are less than or equal to N.
        // For example, if N=5:
        // F(1) depends on odd part 1.
        // F(2) depends on odd part 1 (2 = 1 * 2^1). So F(2) = F(1).
        // F(3) depends on odd part 3.
        // F(4) depends on odd part 1 (4 = 1 * 2^2). So F(4) = F(1).
        // F(5) depends on odd part 5.
        //
        // The distinct values we can potentially have are F(1), F(3), F(5), ...
        // These correspond to the odd numbers less than or equal to N.
        //
        // However, the problem asks for the *maximum* number of distinct elements.
        // This means we can *choose* the function F.
        // We can assign F(odd_part) to be distinct for each odd_part.
        //
        // Let's re-examine the condition F(X) = F(2X).
        // This means that for any number k, its value F(k) is the same as F(k/2) if k is even.
        // F(k) = F(k/2) if k is even.
        // F(k) = F(k/4) if k is even and k/2 is even.
        // ...
        // F(k) = F(k / 2^p) where k / 2^p is the largest odd divisor of k.
        //
        // So, F(k) is determined by the largest odd divisor of k.
        // To maximize the number of distinct values in F(1), ..., F(N), we can assign
        // distinct values to F(odd_number) for each odd_number <= N.
        //
        // The odd numbers less than or equal to N are 1, 3, 5, ..., up to the largest odd number <= N.
        // The number of odd numbers up to N is ceil(N/2).
        //
        // Let's check the sample cases:
        // N = 2: Odd numbers <= 2 are 1. So we can have F(1). F(2) = F(1). Max distinct = 1.
        // N = 5: Odd numbers <= 5 are 1, 3, 5. We can have F(1), F(3), F(5) be distinct.
        // F(1) = F(2) = F(4)
        // F(3)
        // F(5)
        // The distinct values can be F(1), F(3), F(5). Max distinct = 3.
        //
        // The number of distinct values is the number of distinct largest odd divisors for numbers from 1 to N.
        // The largest odd divisor of k is k divided by the highest power of 2 that divides k.
        //
        // Consider the numbers from 1 to N.
        // For each number `i` from 1 to N, we can determine its largest odd divisor.
        // `i = odd_part * 2^p`. F(i) = F(odd_part).
        // We want to count how many distinct `odd_part` values exist for `i` in [1, N].
        //
        // The `odd_part` of `i` is `i` after removing all factors of 2.
        // Example:
        // i=1, odd_part=1
        // i=2, odd_part=1
        // i=3, odd_part=3
        // i=4, odd_part=1
        // i=5, odd_part=5
        // i=6, odd_part=3
        // i=7, odd_part=7
        // i=8, odd_part=1
        //
        // The set of distinct odd parts for numbers from 1 to N are precisely the odd numbers `o` such that `o <= N`.
        // Why?
        // If `o` is an odd number and `o <= N`, then `F(o)` can be assigned a distinct value.
        // For any number `k <= N`, let its largest odd divisor be `odd_k`. Then `F(k) = F(odd_k)`.
        // If `odd_k <= N`, then `F(odd_k)` is one of the values we can potentially make distinct.
        // If `odd_k > N`, this is impossible because `odd_k` is a divisor of `k`, and `k <= N`.
        // So, the largest odd divisor of any `k <= N` must also be `<= N`.
        //
        // Therefore, the set of distinct values of F(k) for k in [1, N] is determined by the set of
        // largest odd divisors of numbers in [1, N].
        // This set of largest odd divisors is exactly the set of odd numbers less than or equal to N.
        //
        // The number of odd integers from 1 to N is `(N + 1) / 2` using integer division.
        // For N=2, (2+1)/2 = 3/2 = 1. Correct.
        // For N=5, (5+1)/2 = 6/2 = 3. Correct.
        //
        // This logic seems sound. The maximum number of distinct elements is achieved when
        // F(odd_number) is distinct for each odd_number <= N.
        //
        // Let's consider the constraints. N can be up to 10^9.
        // The calculation `(N + 1) / 2` is efficient and handles large N.
        //
        // The problem statement says "maximum number of distinct elements".
        // This implies we can choose the function F.
        // The condition F(X) = F(2X) is the only constraint.
        //
        // Let's consider the set of values {F(1), F(2), ..., F(N)}.
        // We know F(k) = F(k / 2^p) where k / 2^p is the largest odd divisor of k.
        // Let `odd_part(k)` be the largest odd divisor of k.
        // Then F(k) = F(odd_part(k)).
        //
        // The set of values {F(1), F(2), ..., F(N)} is equal to the set {F(odd_part(1)), F(odd_part(2)), ..., F(odd_part(N))}.
        //
        // We want to maximize the number of distinct values in this set.
        // This is equivalent to maximizing the number of distinct values in {F(o) | o is an odd number and o = odd_part(k) for some k in [1, N]}.
        //
        // What are the possible values for `odd_part(k)` where `k` is in `[1, N]`?
        // If `o` is an odd number and `o <= N`, then `odd_part(o) = o`. So `o` is a possible odd part.
        // If `k <= N` and `k = o * 2^p` where `o` is odd and `p >= 1`, then `odd_part(k) = o`.
        // Since `k <= N`, we have `o * 2^p <= N`. This implies `o <= N / 2^p`.
        // Since `p >= 1`, `o <= N/2`.
        // In general, `o <= N`.
        //
        // So, the set of all possible `odd_part(k)` for `k` in `[1, N]` is exactly the set of odd numbers `o` such that `o <= N`.
        //
        // To maximize the distinct values of F, we can assign a unique value to F(o) for each odd `o <= N`.
        // For example, we can define F(o) = o for all odd `o <= N`.
        // And for any `k = o * 2^p`, we define F(k) = F(o) = o.
        //
        // With this definition, the values in the array [F(1), ..., F(N)] will be:
        // For k=1, F(1) = F(odd_part(1)) = F(1) = 1.
        // For k=2, F(2) = F(odd_part(2)) = F(1) = 1.
        // For k=3, F(3) = F(odd_part(3)) = F(3) = 3.
        // For k=4, F(4) = F(odd_part(4)) = F(1) = 1.
        // For k=5, F(5) = F(odd_part(5)) = F(5) = 5.
        //
        // The distinct values in [F(1), ..., F(N)] will be {F(o) | o is odd and o <= N}.
        // If we choose F(o) = o, then the distinct values are {o | o is odd and o <= N}.
        // The number of such values is the count of odd numbers up to N.
        //
        // This count is `(N + 1) / 2` using integer division.
        //
        // Example N=10^9.
        // (10^9 + 1) / 2 = 1000000001 / 2 = 500000000.
        // This fits within standard integer types if N is `int`.
        // However, N is up to 10^9, so `int` is fine.
        // The problem statement says N is a positive integer, and constraints are 1 <= N <= 10^9.
        // So `int` is sufficient for N.
        // The result `(N+1)/2` will also fit in `int`.

        // The number of odd integers from 1 to N is ceil(N/2).
        // In integer arithmetic, this is (N + 1) / 2.
        // For N=1, (1+1)/2 = 1.
        // For N=2, (2+1)/2 = 1.
        // For N=3, (3+1)/2 = 2.
        // For N=4, (4+1)/2 = 2.
        // For N=5, (5+1)/2 = 3.
        // This matches the logic.

        std::cout << (n + 1) / 2 << "\n";
    }
    return 0;
}