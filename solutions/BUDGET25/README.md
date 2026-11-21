# [Budget Allotment (BUDGET25)](https://www.codechef.com/problems/BUDGET25)
- **Difficulty Rating**: 1258
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum number of sectors that can meet a minimum budget requirement `X`. We are given `N` sectors, each with an initial budget allocation `A_i`.

The rules for budget distribution are:
1.  If a sector's initial allocation `A_i` is already greater than or equal to `X`, it is considered to have met the requirement. Any surplus `(A_i - X)` from such a sector can be transferred to other sectors.
2.  If a sector's initial allocation `A_i` is less than `X`, it needs an additional `(X - A_i)` budget to meet the requirement. This additional budget must come from the surpluses of other sectors.

We need to find the maximum possible count of sectors that can achieve a budget of at least `X` after optimal redistribution of surpluses.

## Intuition & Mathematical Observation

The core idea is to maximize the number of sectors that reach the minimum budget `X`. We can categorize sectors into two groups:

1.  **Sectors already meeting the budget**: These are sectors where `A_i >= X`. They already contribute to our count of successful sectors. Furthermore, any `(A_i - X)` amount they possess is a surplus that can be used to help other sectors.
2.  **Sectors not meeting the budget**: These are sectors where `A_i < X`. Each such sector needs `(X - A_i)` additional budget to meet the requirement. We call this amount a "deficit".

To maximize the total number of sectors meeting the budget, we should:
*   Count all sectors that initially meet the budget (`A_i >= X`).
*   Collect all available surplus `(A_i - X)` from these sectors into a single `total_surplus` pool.
*   Identify all deficits `(X - A_i)` from sectors that initially do not meet the budget.
*   Use the `total_surplus` to cover as many deficits as possible. To cover the maximum number of deficits with a limited `total_surplus`, we should always prioritize covering the **smallest deficits first**. This greedy strategy ensures that we use our surplus most efficiently, leaving more for subsequent deficits.

**Algorithm Steps:**
1.  Initialize `sectors_met_initial = 0` and `total_surplus = 0`.
2.  Create a list (e.g., `std::vector`) to store `deficits`.
3.  Iterate through all `N` sectors:
    *   Read `current_A`.
    *   If `current_A >= X`: Increment `sectors_met_initial`. Add `(current_A - X)` to `total_surplus`.
    *   If `current_A < X`: Add `(X - current_A)` to the `deficits` list.
4.  Sort the `deficits` list in ascending order.
5.  Iterate through the sorted `deficits` list:
    *   For each `deficit_amount`:
        *   If `total_surplus >= deficit_amount`: We have enough budget to cover this deficit. Subtract `deficit_amount` from `total_surplus` and increment `sectors_met_initial`.
        *   Else (`total_surplus < deficit_amount`): We don't have enough budget for this deficit. Since the deficits are sorted, we won't have enough for any subsequent (larger) deficits either. So, we can stop here.
6.  The final value of `sectors_met_initial` is the maximum number of sectors that can meet the budget.

**Data Type Considerations:**
*   `N` can be up to $2 \cdot 10^5$.
*   `X` and `A_i` can be up to $10^9$.
*   `total_surplus` can accumulate up to `N * X` in the worst case (e.g., one sector has `N*X` budget, others have 0). This means `2 \cdot 10^5 \cdot 10^9 = 2 \cdot 10^{14}`, which far exceeds the capacity of a 32-bit integer (`int`). Therefore, `total_surplus` must be a `long long`.
*   Individual `deficit_amount` (`X - A_i`) can be up to `X` ($10^9$), which fits in an `int`. However, using `long long` for elements in the `deficits` vector is safer and consistent with `total_surplus`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `X`: $O(1)$.
    *   Looping through `N` sectors to categorize and calculate surplus/deficits: $O(N)$.
    *   Sorting the `deficits` vector: If there are `k` deficits, this takes $O(k \log k)$. In the worst case, `k = N`, so this is $O(N \log N)$.
    *   Looping through the sorted `deficits` to cover them: $O(k)$, which is $O(N)$ in the worst case.
    *   Overall, the dominant factor is the sorting step. Thus, the time complexity is $\mathbf{O(N \log N)}$.

*   **Space Complexity**:
    *   Storing the `deficits` vector: In the worst case, all `N` sectors might have `A_i < X`, requiring `N` elements to be stored. This takes $O(N)$ space.
    *   Other variables (`N`, `X`, `sectors_met_initial`, `total_surplus`, `current_A`, `deficit_amount`): $O(1)$ space.
    *   Overall, the space complexity is $\mathbf{O(N)}$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N; // Number of sectors
    long long X; // Minimum budget requirement for each sector
    std::cin >> N >> X;
    
    // sectors_met_initial counts sectors that initially have A_i >= X
    int sectors_met_initial = 0;
    // total_surplus accumulates all transferable budget from sectors with A_i >= X
    // Must be long long as sum can exceed 2*10^9 (int max)
    long long total_surplus = 0;
    // deficits stores the amount needed by sectors with A_i < X
    // Elements (X - A_i) fit in int, but long long is used for consistency and safety.
    std::vector<long long> deficits;
    
    // Read initial allocations and categorize them
    for (int i = 0; i < N; ++i) {
        long long current_A; // Current sector's allocation
        std::cin >> current_A;
        
        if (current_A >= X) {
            // This sector already meets the minimum requirement
            sectors_met_initial++;
            // It can contribute its surplus (current_A - X) to other sectors
            total_surplus += (current_A - X);
        } else {
            // This sector does not meet the minimum requirement
            // It needs (X - current_A) to reach the minimum
            deficits.push_back(X - current_A);
        }
    }
    
    // To maximize the number of sectors meeting the budget,
    // we should use the available total_surplus to cover the smallest deficits first.
    std::sort(deficits.begin(), deficits.end());
    
    // Iterate through the sorted deficits and try to cover them
    for (long long deficit_amount : deficits) {
        if (total_surplus >= deficit_amount) {
            // If we have enough surplus, cover this deficit
            total_surplus -= deficit_amount;
            sectors_met_initial++; // This sector now also meets the budget
        } else {
            // If we don't have enough surplus for this deficit,
            // we won't have enough for any subsequent (larger) deficits either.
            // So, we can stop here.
            break;
        }
    }
    
    // Output the maximum number of sectors that can meet the minimum budget
    std::cout << sectors_met_initial << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    
    return 0;
}
```