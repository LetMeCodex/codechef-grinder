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
        long long x;
        std::cin >> n >> x;
        std::vector<long long> a(n);
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            total_sum += a[i];
        }

        long long max_sweets = total_sum / x;
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            long long sum_without_current = total_sum - a[i];
            if (sum_without_current >= x) {
                // If removing this banknote still allows buying at least one sweet,
                // it means this banknote might be "extra" if the customer
                // intended to buy a number of sweets that could be afforded
                // even without this banknote.
                // The condition for an "adequate" customer is that if you throw away
                // ANY banknote, the resulting amount is NOT enough to buy the wanted number of sweets.
                // This implies that for the *actual* number of sweets K,
                // total_sum >= K * x, AND for every i, total_sum - a[i] < K * x.

                // We are looking for the largest K such that:
                // 1. K > 0
                // 2. total_sum >= K * x
                // 3. For all i, total_sum - a[i] < K * x

                // Let's rephrase condition 3: K * x > total_sum - a[i] for all i.
                // This means K * x must be strictly greater than the minimum of (total_sum - a[i]) over all i.
                // Let min_sum_without_one = min(total_sum - a[i]) for all i.
                // Then K * x > min_sum_without_one.
                // So, K > min_sum_without_one / x.
                // The smallest integer K satisfying this is floor(min_sum_without_one / x) + 1.

                // However, the problem states "if you throw away any banknote, the resulting amount of money won't be enough to buy the wanted number of sweets."
                // This means for the *actual* number of sweets K, the following must hold:
                // 1. K * x <= total_sum
                // 2. For every i, K * x > total_sum - a[i]

                // We want to find the largest K that satisfies these.
                // From condition 2, K * x > total_sum - a[i] for all i.
                // This implies K * x must be strictly greater than the minimum value of (total_sum - a[i]).
                // Let min_sum_after_removing_one = total_sum - max(a[i]).
                // So, K * x > total_sum - max(a[i]).
                // K > (total_sum - max(a[i])) / x.
                // The largest possible K is floor(total_sum / x).
                // We need to check if this largest K satisfies condition 2.
                // For the largest K = floor(total_sum / x), we need to check if
                // K * x > total_sum - a[i] for all i.
                // This is equivalent to checking if (floor(total_sum / x)) * x > total_sum - a[i] for all i.
                // Or, a[i] > total_sum - (floor(total_sum / x)) * x for all i.
                // Let R = total_sum % x. Then floor(total_sum / x) * x = total_sum - R.
                // So we need a[i] > total_sum - (total_sum - R) for all i.
                // This simplifies to a[i] > R for all i.

                // If there is any banknote a[i] such that a[i] <= R, then removing this banknote
                // would leave total_sum - a[i] >= total_sum - R.
                // If K = floor(total_sum / x), then K * x = total_sum - R.
                // So, if a[i] <= R, then total_sum - a[i] >= K * x.
                // This means that if we remove a[i] (where a[i] <= R), the remaining amount is still enough to buy K sweets.
                // This violates the condition that removing any banknote should make the amount insufficient.
                // Therefore, if any a[i] <= R, the customer is inadequate.

                // Let's re-evaluate the condition: "if you throw away any banknote, the resulting amount of money won't be enough to buy the wanted number of sweets."
                // Let K be the number of sweets.
                // The total sum is S.
                // We know S >= K * X.
                // For every banknote a_i, S - a_i < K * X.
                // This means K * X > S - a_i for all i.
                // This is equivalent to K * X > max(S - a_i) for all i.
                // max(S - a_i) = S - min(a_i).
                // So, K * X > S - min(a_i).
                // K > (S - min(a_i)) / X.
                // The largest possible K is floor(S / X).
                // Let K_max = floor(S / X).
                // We need to check if K_max satisfies the condition:
                // For all i, S - a_i < K_max * X.
                // This is equivalent to a_i > S - K_max * X for all i.
                // Let R = S % X. Then K_max * X = S - R.
                // So, we need a_i > S - (S - R) for all i.
                // This simplifies to a_i > R for all i.

                // If there exists any a_i such that a_i <= R, then the customer is inadequate.
                // Because if we remove such an a_i, the remaining sum is S - a_i.
                // Since a_i <= R, S - a_i >= S - R = K_max * X.
                // So, the remaining sum is still enough to buy K_max sweets, which is a contradiction.

                // So, the condition for being adequate is:
                // 1. K > 0
                // 2. K * X <= total_sum
                // 3. For all i, total_sum - a[i] < K * X

                // We are looking for the largest K. The maximum possible K is floor(total_sum / x).
                // Let K_candidate = floor(total_sum / x).
                // If K_candidate == 0, then it's impossible to buy a positive number of sweets.
                // If K_candidate > 0, we need to check if for this K_candidate, the condition holds:
                // For all i, total_sum - a[i] < K_candidate * x.
                // This is equivalent to checking if a[i] > total_sum - K_candidate * x for all i.
                // Let remainder = total_sum % x. Then K_candidate * x = total_sum - remainder.
                // So, we need to check if a[i] > total_sum - (total_sum - remainder) for all i.
                // This simplifies to a[i] > remainder for all i.

                // If there is any a[i] <= remainder, then the customer is inadequate.
                // In this case, the largest possible K is not floor(total_sum / x).
                // We need to find the largest K such that K * x <= total_sum AND K * x > total_sum - a[i] for all i.
                // The second part means K * x > max(total_sum - a[i]) = total_sum - min(a[i]).
                // So, K > (total_sum - min(a[i])) / x.
                // The largest integer K satisfying this is floor((total_sum - min(a[i])) / x).
                // Let K_lower_bound = floor((total_sum - min(a[i])) / x) + 1.
                // We need the largest K such that K_lower_bound <= K <= floor(total_sum / x).
                // The largest such K is floor(total_sum / x) if floor(total_sum / x) >= K_lower_bound.
                // Otherwise, it's impossible.

                // Let's simplify.
                // The customer wants to buy K sweets.
                // Total sum S. Cost per sweet X.
                // S >= K * X.
                // For any banknote a_i, S - a_i < K * X.
                // This means K * X must be strictly greater than S - a_i for all i.
                // So, K * X > max(S - a_i) = S - min(a_i).
                // K > (S - min(a_i)) / X.
                // The smallest integer K satisfying this is floor((S - min(a_i)) / X) + 1.
                // Let K_min_required = floor((S - min(a_i)) / X) + 1.
                // We also need K * X <= S, so K <= floor(S / X).
                // We are looking for the largest K such that K_min_required <= K <= floor(S / X).
                // The largest such K is floor(S / X) if floor(S / X) >= K_min_required.
                // If floor(S / X) < K_min_required, then no such K exists, and it's impossible (-1).
                // Also, K must be positive.

                // Let's find min_a.
                long long min_a = a[0];
                for(int j=1; j<n; ++j) {
                    if (a[j] < min_a) {
                        min_a = a[j];
                    }
                }

                // Calculate the maximum possible number of sweets if the customer is adequate.
                // This is the largest K such that K*X <= total_sum AND K*X > total_sum - a[i] for all i.
                // The second condition implies K*X > total_sum - min(a_i).
                // So, K > (total_sum - min_a) / x.
                // The smallest integer K satisfying this is floor((total_sum - min_a) / x) + 1.
                // Let K_lower_bound = (total_sum - min_a) / x + 1; // Integer division floors.
                // If total_sum - min_a is perfectly divisible by x, then (total_sum - min_a) / x is exact.
                // If total_sum - min_a is not perfectly divisible by x, then (total_sum - min_a) / x is floor.
                // So K > (total_sum - min_a) / x.
                // The smallest integer K is floor((total_sum - min_a) / x) + 1.
                // Example: S=70, min_a=20, X=10.
                // K*10 > 70 - 20 = 50. K > 5. Smallest integer K is 6.
                // floor((70-20)/10) + 1 = floor(50/10) + 1 = 5 + 1 = 6. Correct.
                // Example: S=27, min_a=4, X=7.
                // K*7 > 27 - 4 = 23. K > 23/7 = 3.28... Smallest integer K is 4.
                // floor((27-4)/7) + 1 = floor(23/7) + 1 = 3 + 1 = 4. Correct.

                long long k_lower_bound_val;
                if ((total_sum - min_a) % x == 0) {
                    k_lower_bound_val = (total_sum - min_a) / x + 1;
                } else {
                    k_lower_bound_val = (total_sum - min_a) / x + 1;
                }
                // A simpler way for K > V is K >= floor(V) + 1.
                // K > (total_sum - min_a) / x.
                // If (total_sum - min_a) is perfectly divisible by x, say V = Q, then K > Q, so K >= Q+1.
                // If (total_sum - min_a) is not perfectly divisible by x, say V = Q.f, then K > Q.f, so K >= Q+1.
                // So K_min_required is always floor((total_sum - min_a) / x) + 1.
                // Let's use long double for precision if needed, but integer arithmetic should be fine.
                // K * X > total_sum - min_a
                // K > (total_sum - min_a) / X
                // The smallest integer K is floor((total_sum - min_a) / X) + 1.
                // If total_sum - min_a < 0, this logic needs care, but a_i are positive, so total_sum >= min_a.
                // If total_sum - min_a = 0, then K > 0, so K >= 1. floor(0/X)+1 = 1. Correct.

                long long k_min_required;
                if (total_sum - min_a < 0) { // Should not happen with positive a_i
                    k_min_required = 1;
                } else {
                    k_min_required = (total_sum - min_a) / x + 1;
                }


                // The maximum possible K is floor(total_sum / x).
                long long k_max_possible = total_sum / x;

                // We need to find the largest K such that k_min_required <= K <= k_max_possible.
                // If k_max_possible < k_min_required, then no such K exists.
                // Also, K must be positive.
                if (k_max_possible < k_min_required || k_max_possible <= 0) {
                    possible = false;
                    break;
                } else {
                    // The largest possible K is k_max_possible.
                    // We have already established that if this K is chosen,
                    // then for all i, total_sum - a[i] < K * x if and only if a[i] > total_sum - K * x.
                    // This is equivalent to a[i] > total_sum % x.
                    // So, if any a[i] <= total_sum % x, then K = floor(total_sum / x) is not valid.
                    // In that case, the largest valid K is floor((total_sum - min_a) / x).
                    // Let's re-think the condition for inadequacy.
                    // The customer is inadequate if there exists a K > 0 such that:
                    // 1. K * X <= total_sum
                    // 2. For ALL i, total_sum - a[i] >= K * X.
                    // This means K * X <= min(total_sum - a[i]) = total_sum - max(a[i]).
                    // So, K <= (total_sum - max(a[i])) / X.
                    // If there exists a K > 0 such that K <= (total_sum - max(a[i])) / X,
                    // AND K * X <= total_sum, then the customer is inadequate.
                    // The largest such K is floor((total_sum - max(a[i])) / X).
                    // If this K is positive, then the customer is inadequate.

                    // Let's use the sample cases to guide.
                    // Sample 1: N=4, X=7. A = [10, 4, 8, 5].
                    // Total sum S = 27.
                    // Max possible K = 27 / 7 = 3.
                    // Check K=3:
                    // 3 * 7 = 21 <= 27. (OK)
                    // Check S - a_i < K * X for all i:
                    // S - 10 = 17. Is 17 < 21? Yes.
                    // S - 4 = 23. Is 23 < 21? No. (Customer is inadequate if they want 3 sweets)
                    // S - 8 = 19. Is 19 < 21? Yes.
                    // S - 5 = 22. Is 22 < 21? No. (Customer is inadequate if they want 3 sweets)

                    // The condition is: "if you throw away ANY banknote, the resulting amount of money won't be enough to buy the wanted number of sweets."
                    // This means for the wanted number of sweets K, and for ALL i:
                    // total_sum - a[i] < K * x.
                    // This implies K * x > total_sum - a[i] for all i.
                    // So, K * x > max(total_sum - a[i]) = total_sum - min(a[i]).
                    // K > (total_sum - min(a[i])) / x.
                    // The smallest integer K satisfying this is floor((total_sum - min(a[i])) / x) + 1.
                    // Let K_min_req = floor((total_sum - min(a[i])) / x) + 1.

                    // Also, K must be positive and K * x <= total_sum.
                    // So, K <= floor(total_sum / x).
                    // We are looking for the largest K such that K_min_req <= K <= floor(total_sum / x).
                    // The largest such K is floor(total_sum / x) if floor(total_sum / x) >= K_min_req.
                    // Otherwise, it's impossible (-1).

                    // Let's re-calculate for Sample 1:
                    // N=4, X=7. A = [10, 4, 8, 5].
                    // Total sum S = 27.
                    // min(a_i) = 4.
                    // K_min_req = floor((27 - 4) / 7) + 1 = floor(23 / 7) + 1 = 3 + 1 = 4.
                    // K_max_possible = floor(27 / 7) = 3.
                    // Is K_max_possible >= K_min_req? Is 3 >= 4? No.
                    // So, it's impossible. Output -1. This matches sample output.

                    // Sample 2: N=1, X=10. A = [12].
                    // Total sum S = 12.
                    // min(a_i) = 12.
                    // K_min_req = floor((12 - 12) / 10) + 1 = floor(0 / 10) + 1 = 0 + 1 = 1.
                    // K_max_possible = floor(12 / 10) = 1.
                    // Is K_max_possible >= K_min_req? Is 1 >= 1? Yes.
                    // Largest K is K_max_possible = 1. Output 1. Matches sample output.

                    // Sample 3: N=2, X=10. A = [20, 50].
                    // Total sum S = 70.
                    // min(a_i) = 20.
                    // K_min_req = floor((70 - 20) / 10) + 1 = floor(50 / 10) + 1 = 5 + 1 = 6.
                    // K_max_possible = floor(70 / 10) = 7.
                    // Is K_max_possible >= K_min_req? Is 7 >= 6? Yes.
                    // Largest K is K_max_possible = 7. Output 7. Matches sample output.

                    // This logic seems correct.
                    // The condition for inadequacy is when K_max_possible < K_min_req.
                    // If K_max_possible >= K_min_req, then the largest possible K is K_max_possible.
                    // We also need K > 0. If K_max_possible is 0, then it's impossible.

                    // Let's implement this.
                    // We need min_a.
                    // We need K_min_req = floor((total_sum - min_a) / x) + 1.
                    // We need K_max_possible = floor(total_sum / x).
                    // If K_max_possible >= K_min_req AND K_max_possible > 0, output K_max_possible.
                    // Otherwise, output -1.

                    // The loop `for (int i = 0; i < n; ++i)` is not needed for this logic.
                    // We just need total_sum and min_a.
                    // The `possible` flag and `break` are also not needed if we calculate directly.
                    // Let's restart the logic for the current test case.
                    goto calculate_result; // Exit the loop and proceed to calculation
                }
            }
        }

    calculate_result:;
        long long min_a = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] < min_a) {
                min_a = a[i];
            }
        }

        long long k_max_possible = total_sum / x;

        // Calculate K_min_req: smallest K such that K*X > total_sum - a[i] for all i.
        // This means K*X > total_sum - min_a.
        // K > (total_sum - min_a) / x.
        // The smallest integer K is floor((total_sum - min_a) / x) + 1.
        long long k_min_req;
        if (total_sum - min_a < 0) { // Should not happen with positive a_i
            k_min_req = 1; // If total_sum - min_a is negative, K > negative value, smallest positive K is 1.
        } else {
            k_min_req = (total_sum - min_a) / x + 1;
        }

        // We need to find the largest K such that k_min_req <= K <= k_max_possible.
        // Also K must be positive.
        if (k_max_possible >= k_min_req && k_max_possible > 0) {
            std::cout << k_max_possible << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
    return 0;
}