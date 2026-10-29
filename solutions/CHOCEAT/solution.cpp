#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The goal is to maximize satisfaction.
        // Satisfaction increases if the number of milk chocolates eaten so far
        // is NOT equal to the number of dark chocolates eaten so far.
        // This means satisfaction increases in every step EXCEPT when the counts are equal.
        // To maximize satisfaction, we want to minimize the number of times the counts are equal.
        // The counts can be equal at 0, 1, 2, ... up to min(a, b).
        //
        // Consider the total number of chocolates eaten, which is a + b.
        // Let m be the number of milk chocolates eaten and d be the number of dark chocolates eaten.
        // Satisfaction increases when m != d.
        //
        // If we eat chocolates such that m and d are always different, satisfaction is a + b.
        // This is possible if we can always maintain m != d.
        //
        // Let's analyze the condition m != d.
        // If we have eaten k chocolates in total, and m = d, then k must be even.
        // The first time m can be equal to d is when we have eaten 2 chocolates (1 milk, 1 dark).
        // The second time m can be equal to d is when we have eaten 4 chocolates (2 milk, 2 dark).
        // ...
        // The k-th time m can be equal to d is when we have eaten 2k chocolates (k milk, k dark).
        // This can happen as long as we have at least k milk chocolates and k dark chocolates available.
        // So, the maximum k for which m can be equal to d is min(a, b).
        //
        // This means the counts m and d can be equal at most min(a, b) + 1 times (including the initial state where m=0, d=0).
        // However, the problem states "After eating it, his satisfaction increases if and only if the number of milk chocolates eaten so far is not equal to the number of dark chocolates eaten so far."
        // This implies that satisfaction is counted *after* eating a chocolate.
        // So, the initial state (0 milk, 0 dark) does not contribute to satisfaction.
        //
        // The number of times m can be equal to d *after* eating a chocolate is min(a, b).
        // For example, if a=1, b=2:
        // Eat D: m=0, d=1. m!=d. Satisfaction +1. Total eaten: 1.
        // Eat D: m=0, d=2. m!=d. Satisfaction +1. Total eaten: 2.
        // Eat M: m=1, d=2. m!=d. Satisfaction +1. Total eaten: 3.
        // Total satisfaction = 3.
        //
        // If a=1, b=1:
        // Eat M: m=1, d=0. m!=d. Satisfaction +1. Total eaten: 1.
        // Eat D: m=1, d=1. m==d. Satisfaction +0. Total eaten: 2.
        // Total satisfaction = 1.
        //
        // If a=4, b=2:
        // We want to avoid m==d as much as possible.
        // The total number of chocolates is a + b.
        // The number of times m can be equal to d after eating is min(a, b).
        // Each time m == d, we lose 1 point of satisfaction.
        // So, the maximum satisfaction is (total chocolates) - (number of times m == d).
        // Maximum satisfaction = (a + b) - min(a, b).
        //
        // Let's verify this formula:
        // a=1, b=2: (1+2) - min(1,2) = 3 - 1 = 2. This is incorrect. Sample output is 3.
        //
        // Let's re-read: "his satisfaction increases if and only if the number of milk chocolates eaten so far is not equal to the number of dark chocolates eaten so far."
        // This means satisfaction is gained in every step where m != d.
        //
        // Consider the sequence of eating.
        // Let's say we eat m_i milk chocolates and d_i dark chocolates after the i-th step.
        // Satisfaction increases at step i if m_i != d_i.
        //
        // Total steps = A + B.
        // We want to maximize the number of steps i where m_i != d_i.
        // This is equivalent to minimizing the number of steps i where m_i == d_i.
        //
        // The number of milk chocolates eaten so far can be at most A.
        // The number of dark chocolates eaten so far can be at most B.
        //
        // The counts m and d can be equal only when the total number of chocolates eaten is even.
        // Let k be the number of milk chocolates eaten and k be the number of dark chocolates eaten.
        // This state (k milk, k dark) can be reached if we have at least k milk and k dark chocolates.
        // The maximum such k is min(A, B).
        //
        // So, the states where m == d can occur for (0,0), (1,1), (2,2), ..., (min(A,B), min(A,B)).
        //
        // If we eat chocolates in an alternating fashion as much as possible, we can delay or avoid the m==d state.
        //
        // Example: A=4, B=2. Total = 6. min(A,B) = 2.
        // Possible states where m==d: (0,0), (1,1), (2,2).
        //
        // Strategy: Try to keep the counts as far apart as possible.
        // If A > B, eat A chocolates first, then B.
        // If B > A, eat B chocolates first, then A.
        // If A == B, it doesn't matter.
        //
        // Let's assume A >= B.
        // Eat B dark chocolates: m=0, d=B. Satisfaction: B (since m!=d for all steps from 1 to B).
        // Now we have A milk chocolates left.
        // Eat 1 milk chocolate: m=1, d=B. m!=d. Satisfaction +1.
        // Eat 1 milk chocolate: m=2, d=B. m!=d. Satisfaction +1.
        // ...
        // Eat 1 milk chocolate: m=B, d=B. m==d. Satisfaction +0.
        // Now we have A-B milk chocolates left.
        // Eat 1 milk chocolate: m=B+1, d=B. m!=d. Satisfaction +1.
        // ...
        // Eat 1 milk chocolate: m=A, d=B. m!=d. Satisfaction +1.
        //
        // This strategy is not optimal. We want to maximize satisfaction.
        //
        // The satisfaction is gained in every step where m != d.
        // Total steps = A + B.
        // The number of steps where m == d is the number of times we reach a state (k, k) after eating a chocolate.
        // This can happen for k = 1, 2, ..., min(A, B).
        // So, there are min(A, B) such "bad" states.
        //
        // If we can arrange the eating such that we reach these states (k, k) at most min(A, B) times,
        // then the total satisfaction would be (A + B) - min(A, B).
        //
        // Let's re-examine the sample cases with this formula:
        // Sample 1: A=1, B=2. Formula: (1+2) - min(1,2) = 3 - 1 = 2. Sample output: 3. Formula is wrong.
        // Sample 2: A=1, B=1. Formula: (1+1) - min(1,1) = 2 - 1 = 1. Sample output: 1. Formula matches.
        // Sample 3: A=4, B=2. Formula: (4+2) - min(4,2) = 6 - 2 = 4. Sample output: 6. Formula is wrong.
        //
        // The problem is about maximizing satisfaction.
        // Satisfaction increases if m != d.
        //
        // Consider the total number of chocolates eaten, N = A + B.
        // Let's say we eat m_i milk and d_i dark chocolates at step i.
        // Satisfaction at step i is 1 if m_i != d_i, and 0 if m_i == d_i.
        // Total satisfaction = sum_{i=1}^{A+B} [m_i != d_i]
        // where [condition] is 1 if condition is true, 0 otherwise.
        //
        // Total satisfaction = (A + B) - sum_{i=1}^{A+B} [m_i == d_i]
        // We want to minimize sum_{i=1}^{A+B} [m_i == d_i].
        //
        // The state m_i == d_i can only happen if the total number of chocolates eaten so far (i) is even.
        // Let's say at step i, we have eaten k milk and k dark chocolates.
        // This requires k <= A and k <= B.
        // So, k can range from 1 to min(A, B).
        //
        // If A=1, B=2. Total=3. min(A,B)=1.
        // Possible states where m==d: (0,0), (1,1).
        //
        // Sequence 1: D, D, M
        // Step 1: Eat D. m=0, d=1. m!=d. Sat=1.
        // Step 2: Eat D. m=0, d=2. m!=d. Sat=1.
        // Step 3: Eat M. m=1, d=2. m!=d. Sat=1.
        // Total Sat = 3.
        //
        // Sequence 2: M, D, D
        // Step 1: Eat M. m=1, d=0. m!=d. Sat=1.
        // Step 2: Eat D. m=1, d=1. m==d. Sat=0.
        // Step 3: Eat D. m=1, d=2. m!=d. Sat=1.
        // Total Sat = 2.
        //
        // The maximum satisfaction is achieved by maximizing the number of steps where m != d.
        //
        // Consider the difference |m - d|. We want this difference to be non-zero as often as possible.
        //
        // Let's think about the number of "equal states" we are forced to enter.
        // If we have A milk and B dark chocolates.
        // Suppose A >= B.
        // We can eat B dark chocolates. Then m=0, d=B. All these B steps give satisfaction.
        // Now we have A milk chocolates left.
        // If we eat them one by one:
        // Eat M: m=1, d=B. Sat +1.
        // ...
        // Eat M: m=B, d=B. Sat +0. (This is the first time m==d after step 0).
        // Eat M: m=B+1, d=B. Sat +1.
        // ...
        // Eat M: m=A, d=B. Sat +1.
        //
        // The number of times m==d occurs is related to min(A, B).
        //
        // Let's consider the total number of chocolates eaten, N = A + B.
        // The number of steps where satisfaction is NOT gained is when m == d.
        // This can happen at most min(A, B) times (for k=1, 2, ..., min(A, B)).
        //
        // If A = B, say A=B=k. Total = 2k. min(A,B) = k.
        // We can eat M, D, M, D, ..., M, D.
        // Step 1: M. m=1, d=0. Sat=1.
        // Step 2: D. m=1, d=1. Sat=0.
        // Step 3: M. m=2, d=1. Sat=1.
        // Step 4: D. m=2, d=2. Sat=0.
        // ...
        // Step 2k-1: M. m=k, d=k-1. Sat=1.
        // Step 2k: D. m=k, d=k. Sat=0.
        //
        // In this case (A=B=k), the satisfaction is gained in steps 1, 3, 5, ..., 2k-1.
        // There are k such steps. Total satisfaction = k.
        // Formula (A+B) - min(A,B) = 2k - k = k. Matches.
        //
        // If A=1, B=2. Total=3. min(A,B)=1.
        // We want to avoid m==d.
        // The only state where m==d is (1,1). This happens after eating 2 chocolates.
        //
        // Sequence: D, D, M
        // Step 1: D. m=0, d=1. m!=d. Sat=1.
        // Step 2: D. m=0, d=2. m!=d. Sat=1.
        // Step 3: M. m=1, d=2. m!=d. Sat=1.
        // Total Sat = 3.
        //
        // Here, the state (1,1) was never reached.
        //
        // The number of times m==d can occur is min(A, B).
        // If we can avoid reaching these states, satisfaction is A+B.
        //
        // When are we FORCED to reach m==d?
        // Suppose A > B.
        // We can eat B dark chocolates. m=0, d=B. All B steps give satisfaction.
        // Now we have A milk chocolates left.
        // We need to eat A more chocolates.
        // If we eat them all as milk:
        // Eat M: m=1, d=B. Sat +1.
        // ...
        // Eat M: m=B, d=B. Sat +0. (This is the first time m==d after step 0).
        // Eat M: m=B+1, d=B. Sat +1.
        // ...
        // Eat M: m=A, d=B. Sat +1.
        //
        // The number of steps where m==d is exactly 1 (when m=B, d=B).
        // Total satisfaction = (A+B) - 1.
        //
        // Let's check this new hypothesis:
        // If A=1, B=2. Assume A <= B.
        // We can eat A milk chocolates first. m=A, d=0. All A steps give satisfaction.
        // Now we have B dark chocolates left.
        // Eat D: m=A, d=1. Sat +1.
        // ...
        // Eat D: m=A, d=A. Sat +0. (This is the first time m==d after step 0).
        // Eat D: m=A, d=A+1. Sat +1.
        // ...
        // Eat D: m=A, d=B. Sat +1.
        //
        // The number of steps where m==d is exactly 1 (when m=A, d=A).
        // Total satisfaction = (A+B) - 1.
        //
        // This seems to hold if A != B.
        // If A=1, B=2. A < B. (1+2) - 1 = 2. Still not 3.
        //
        // The sample explanation for A=1, B=2 says:
        // "Chef first eats a dark chocolate, then another dark chocolate, and then a milk chocolate. In this way, his satisfaction increases by 1 in each step, and thus he gets a satisfaction of 3."
        // D: m=0, d=1. m!=d. Sat=1.
        // D: m=0, d=2. m!=d. Sat=1.
        // M: m=1, d=2. m!=d. Sat=1.
        // Total Sat = 3.
        //
        // In this sequence, m never equals d after eating a chocolate.
        // This is possible because we have more dark chocolates than milk chocolates.
        // We can eat all the dark chocolates first (or almost all) and then eat milk chocolates.
        //
        // If A > B:
        // Eat B dark chocolates: m=0, d=B. All B steps give satisfaction.
        // Now we have A milk chocolates.
        // Eat A milk chocolates:
        // m=1, d=B. Sat +1.
        // ...
        // m=B, d=B. Sat +0. (This is the first time m==d).
        // m=B+1, d=B. Sat +1.
        // ...
        // m=A, d=B. Sat +1.
        //
        // The number of steps where m==d is 1 (when m=B, d=B).
        // Total satisfaction = (A+B) - 1.
        //
        // If B > A:
        // Eat A milk chocolates: m=A, d=0. All A steps give satisfaction.
        // Now we have B dark chocolates.
        // Eat B dark chocolates:
        // m=A, d=1. Sat +1.
        // ...
        // m=A, d=A. Sat +0. (This is the first time m==d).
        // m=A, d=A+1. Sat +1.
        // ...
        // m=A, d=B. Sat +1.
        //
        // The number of steps where m==d is 1 (when m=A, d=A).
        // Total satisfaction = (A+B) - 1.
        //
        // This formula (A+B) - 1 works for A=1, B=2 (gives 2, sample is 3) and A=4, B=2 (gives 5, sample is 6).
        //
        // The key must be that we can AVOID the m==d state if one count is sufficiently larger than the other.
        //
        // Let's consider the number of chocolates of the minority type. Let this be `min_val = min(A, B)`.
        // Let the number of chocolates of the majority type be `max_val = max(A, B)`.
        //
        // If we eat all `min_val` chocolates of the minority type first.
        // Case 1: A <= B. Eat A milk chocolates.
        // Step 1: M. m=1, d=0. Sat=1.
        // ...
        // Step A: M. m=A, d=0. Sat=1.
        // Total satisfaction so far = A.
        // Now we have B dark chocolates left.
        // We need to eat B more chocolates.
        // Step A+1: D. m=A, d=1. Sat=1.
        // ...
        // Step A+k: D. m=A, d=k.
        // Satisfaction is gained if m != d, i.e., A != k.
        // This is true for k = 1, 2, ..., A-1.
        // When k = A, we have m=A, d=A. Satisfaction is 0. This is the first time m==d.
        // This happens at step A+A = 2A.
        // After this step, we have B-A dark chocolates left.
        // We eat the remaining B-A dark chocolates.
        // Step 2A+1: D. m=A, d=A+1. Sat=1.
        // ...
        // Step A+B: D. m=A, d=B. Sat=1.
        //
        // The steps where satisfaction is NOT gained are when m==d.
        // This happens only once: when m=A and d=A.
        // This occurs after eating A milk chocolates and A dark chocolates.
        // Total chocolates eaten = 2A.
        //
        // So, if A <= B, we can eat A milk chocolates, then A dark chocolates, then B-A dark chocolates.
        // Sequence: M (A times), D (A times), D (B-A times).
        //
        // Let's trace satisfaction:
        // Eating A milk chocolates: m=1..A, d=0. m!=d always. Satisfaction = A.
        // Eating A dark chocolates:
        //   m=A, d=1. m!=d. Sat=1.
        //   ...
        //   m=A, d=A-1. m!=d. Sat=1.
        //   m=A, d=A. m==d. Sat=0. (This is the first time m==d).
        // Eating B-A dark chocolates:
        //   m=A, d=A+1. m!=d. Sat=1.
        //   ...
        //   m=A, d=B. m!=d. Sat=1.
        //
        // Total satisfaction = A (from first A steps) + (A-1) (from next A-1 steps) + (B-A) (from last B-A steps)
        // Total satisfaction = A + (A-1) + (B-A) = 2A - 1 + B - A = A + B - 1.
        //
        // This formula (A+B) - 1 works if A <= B.
        //
        // Let's check sample cases again with this logic:
        // A=1, B=2. A <= B. Formula: (1+2) - 1 = 2. Sample output: 3. Still wrong.
        //
        // The sample explanation for A=1, B=2 is crucial:
        // "Chef first eats a dark chocolate, then another dark chocolate, and then a milk chocolate. In this way, his satisfaction increases by 1 in each step, and thus he gets a satisfaction of 3."
        // Sequence: D, D, M
        // D: m=0, d=1. m!=d. Sat=1.
        // D: m=0, d=2. m!=d. Sat=1.
        // M: m=1, d=2. m!=d. Sat=1.
        // Total Sat = 3.
        //
        // In this sequence, m never equals d.
        // This is possible because B > A. We can eat all B dark chocolates first.
        // If B > A:
        // Eat B dark chocolates: m=0, d=1..B. All B steps give satisfaction.
        // Now we have A milk chocolates left.
        // Eat A milk chocolates:
        // m=1, d=B. m!=d. Sat=1.
        // ...
        // m=A, d=B. m!=d. Sat=1.
        //
        // In this case (B > A), m is always 0 or positive, and d is always B or positive.
        // If we eat all B dark chocolates first:
        // D: m=0, d=1. m!=d.
        // D: m=0, d=2. m!=d.
        // ...
        // D: m=0, d=B. m!=d.
        // M: m=1, d=B. m!=d.
        // ...
        // M: m=A, d=B. m!=d.
        //
        // This sequence is possible if B > A.
        // In this sequence, m is always <= A, and d is always >= 1.
        // If B > A, then d is always strictly greater than m (since m is at most A, and d is at least 1, and B > A).
        // Specifically, after eating k dark chocolates, m=0, d=k. m!=d.
        // After eating k dark and j milk chocolates, m=j, d=k.
        // If we eat all B dark chocolates first, then all A milk chocolates:
        // D: m=0, d=1. m!=d.
        // ...
        // D: m=0, d=B. m!=d.
        // M: m=1, d=B. m!=d.
        // ...
        // M: m=A, d=B. m!=d.
        //
        // In this scenario (eating all of the majority type first), m never equals d.
        // This is possible if the number of majority chocolates is strictly greater than the number of minority chocolates.
        //
        // If B > A: Eat all B dark chocolates, then all A milk chocolates.
        // D: m=0, d=1. Sat=1.
        // ...
        // D: m=0, d=B. Sat=1.
        // M: m=1, d=B. Sat=1.
        // ...
        // M: m=A, d=B. Sat=1.
        // Total satisfaction = B + A = A + B.
        // This is possible if B > A.
        //
        // If A > B: Eat all A milk chocolates, then all B dark chocolates.
        // M: m=1, d=0. Sat=1.
        // ...
        // M: m=A, d=0. Sat=1.
        // D: m=A, d=1. Sat=1.
        // ...
        // D: m=A, d=B. Sat=1.
        // Total satisfaction = A + B.
        // This is possible if A > B.
        //
        // So, if A != B, we can achieve satisfaction A + B.
        //
        // What if A == B? Let A = B = k.
        // Total chocolates = 2k.
        // We cannot eat all of one type first and then all of the other, because the counts would become equal.
        // Example: A=1, B=1.
        // Eat M: m=1, d=0. Sat=1.
        // Eat D: m=1, d=1. Sat=0.
        // Total Sat = 1.
        //
        // Example: A=2, B=2. Total=4.
        // Eat M: m=1, d=0. Sat=1.
        // Eat D: m=1, d=1. Sat=0.
        // Eat M: m=2, d=1. Sat=1.
        // Eat D: m=2, d=2. Sat=0.
        // Total Sat = 2.
        //
        // If A = B = k, the maximum satisfaction seems to be k.
        // This is because in every pair of (M, D) or (D, M) eaten, one step will result in m==d.
        // To maximize satisfaction, we want to make the "bad" step (m==d) happen as late as possible.
        //
        // Consider A=B=k.
        // We eat k chocolates. The counts are m=k, d=0. All k steps give satisfaction.
        // Then we eat k chocolates.
        // The first one makes it m=k, d=1. Sat=1.
        // ...
        // The k-th one makes it m=k, d=k. Sat=0.
        //
        // Let's try to keep the counts apart.
        // A=k, B=k.
        // Eat M: m=1, d=0. Sat=1.
        // Eat M: m=2, d=0. Sat=1.
        // ...
        // Eat M: m=k, d=0. Sat=1. (k steps, all sat=1)
        // Now we have k dark chocolates.
        // Eat D: m=k, d=1. Sat=1.
        // ...
        // Eat D: m=k, d=k. Sat=0. (k steps, k-1 sat=1, 1 sat=0)
        // Total satisfaction = k + (k-1) = 2k - 1.
        //
        // Let's recheck A=1, B=1. k=1. Formula: 2*1 - 1 = 1. Matches sample.
        // Let's recheck A=2, B=2. k=2. Formula: 2*2 - 1 = 3.
        // Let's trace A=2, B=2 to get 3.
        // M: m=1, d=0. Sat=1.
        // M: m=2, d=0. Sat=1.
        // D: m=2, d=1. Sat=1.
        // D: m=2, d=2. Sat=0.
        // Total Sat = 3.
        //
        // So, if A == B = k, the maximum satisfaction is 2k - 1.
        //
        // Combining the cases:
        // If A != B: Max satisfaction = A + B.
        // If A == B: Max satisfaction = A + B - 1.
        //
        // This can be written as: A + B - (A == B ? 1 : 0).
        // Or A + B - (min(A, B) == max(A, B) ? 1 : 0).
        // Or A + B - (A == B). (In C++, boolean true is 1, false is 0).
        //
        // Let's test this final hypothesis.
        //
        // Sample 1: A=1, B=2. A != B. Result: 1 + 2 = 3. Matches sample.
        // Sample 2: A=1, B=1. A == B. Result: 1 + 1 - 1 = 1. Matches sample.
        // Sample 3: A=4, B=2. A != B. Result: 4 + 2 = 6. Matches sample.
        //
        // This logic seems correct.
        //
        // Why is A+B achievable when A != B?
        // Assume A > B.
        // Eat all A milk chocolates first.
        // M: m=1, d=0. Sat=1.
        // ...
        // M: m=A, d=0. Sat=1.
        // All A steps give satisfaction because d is always 0 and m is always > 0.
        // Now we have B dark chocolates left.
        // Eat B dark chocolates.
        // D: m=A, d=1. Sat=1. (Since A > B >= 1, A != 1).
        // ...
        // D: m=A, d=B. Sat=1. (Since A > B, A != B).
        // All B steps give satisfaction because m is always A and d is always <= B, and A > B.
        // Total satisfaction = A + B.
        // This strategy works if A > B.
        // Similarly, if B > A, eat all B dark chocolates first, then all A milk chocolates.
        // D: m=0, d=1. Sat=1.
        // ...
        // D: m=0, d=B. Sat=1.
        // M: m=1, d=B. Sat=1. (Since B > A >= 1, B != 1).
        // ...
        // M: m=A, d=B. Sat=1. (Since B > A, B != A).
        // Total satisfaction = B + A.
        //
        // So, if A != B, we can achieve A + B.
        //
        // Why is A+B-1 achievable when A == B = k?
        // We need to have at least one step where m == d.
        // Consider the strategy: Eat k milk chocolates, then k dark chocolates.
        // M: m=1, d=0. Sat=1.
        // ...
        // M: m=k, d=0. Sat=1.
        // (k steps, all satisfaction)
        // D: m=k, d=1. Sat=1. (Since k >= 1)
        // ...
        // D: m=k, d=k-1. Sat=1.
        // D: m=k, d=k. Sat=0. (This is the only step where m==d)
        // Total satisfaction = k (from first phase) + (k-1) (from second phase) = 2k - 1.
        //
        // This strategy works.
        //
        // The logic seems solid.
        // The constraints are A, B <= 10^9, so `long long` is necessary.
        // The calculation is O(1) per test case.

        if (a == b) {
            cout << a + b - 1 << "\n";
        } else {
            cout << a + b << "\n";
        }
    }
    return 0;
}