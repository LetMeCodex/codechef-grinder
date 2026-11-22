#include <iostream>
#include <vector>
#include <map>
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
        std::map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int apples;
            std::cin >> apples;
            counts[apples]++;
        }

        // The problem can be rephrased as finding the minimum number of distinct apple counts
        // that we need to "reduce" to.
        // In each minute, we can pick a subset of trees with the same number of apples.
        // We can reduce their apple count to match any tree *not* in the subset.
        // This means we can effectively group trees by their current apple count and
        // reduce them to a common smaller apple count.
        // The goal is to reach a state where all trees have 0 apples.
        //
        // Consider the distinct initial apple counts. Let these be a1, a2, ..., ak.
        // In one minute, we can pick all trees with `a_i` apples and reduce them to `a_j` apples (where `a_j` is an initial count or 0).
        // The key insight is that in one minute, we can take all trees that currently have `X` apples and reduce them to `Y` apples,
        // where `Y` is the number of apples on *some* tree that is *not* in the chosen subset.
        // If we choose a subset of trees all having `X` apples, and we want to reduce them to `Y` apples,
        // this is only possible if there exists at least one tree (either initially or after some operations)
        // that has `Y` apples and is *not* part of the subset of trees with `X` apples.
        //
        // The most efficient way to think about this is to consider the distinct initial apple counts.
        // Let the distinct initial apple counts be `v1, v2, ..., vk`.
        // In one minute, we can pick all trees with `v_i` apples and reduce them to `v_j` apples.
        // This operation effectively merges the group of trees with `v_i` apples into the group of trees with `v_j` apples.
        // The goal is to make all trees have 0 apples.
        //
        // The number of minutes required is equal to the number of distinct initial apple counts.
        // Why?
        // Let the distinct initial apple counts be `c1 < c2 < ... < ck`.
        //
        // Minute 1: Select all trees with `ck` apples. Reduce them to `c_{k-1}` apples.
        // Now we have groups with `c1, c2, ..., c_{k-2}, c_{k-1}, c_{k-1}` apples.
        //
        // Minute 2: Select all trees that *currently* have `c_{k-1}` apples (this includes original `c_{k-1}` trees and those reduced from `ck`).
        // Reduce them to `c_{k-2}` apples.
        //
        // We continue this process. In minute `m`, we select all trees that currently have `c_{k-m+1}` apples and reduce them to `c_{k-m}` apples.
        // After `k-1` minutes, all trees will have `c1` apples.
        //
        // Minute `k`: Select all trees that currently have `c1` apples. Reduce them to 0 apples.
        //
        // This strategy takes `k` minutes, where `k` is the number of distinct initial apple counts.
        // Can we do better?
        //
        // Consider the sample case: 1 2 3 3. Distinct counts: {1, 2, 3}. Number of distinct counts = 3.
        //
        // Initial: {1:1, 2:1, 3:2}
        //
        // Minute 1: Select trees with 3 apples. Reduce them to 2 apples.
        // Trees: {1:1, 2:1, 2:2} -> {1:1, 2:3}
        //
        // Minute 2: Select trees with 2 apples. Reduce them to 1 apple.
        // Trees: {1:1, 1:3} -> {1:4}
        //
        // Minute 3: Select trees with 1 apple. Reduce them to 0 apples.
        // Trees: {0:4}
        //
        // This takes 3 minutes.
        //
        // The problem statement says: "From each tree in the subset, pluck any number of apples, as long as the number of apples left on the tree equals the number of apples on a tree not in the subset."
        // This implies that if we pick a subset of trees with `X` apples, we can reduce them to `Y` apples, IF there is at least one tree *not* in this subset that has `Y` apples.
        //
        // Let's re-evaluate the sample explanation:
        // 4 trees: 1 2 3 3
        // Distinct counts: {1, 2, 3}
        //
        // Minute 1: Select trees 3 and 4 (both have 3 apples).
        // Pluck 1 apple from tree 3 (leaves 2). Pluck 2 apples from tree 4 (leaves 1).
        // This is allowed because tree 2 has 2 apples, and tree 1 has 1 apple.
        // Trees now: 1, 2, 2, 1.
        // Counts: {1:2, 2:2}
        //
        // Minute 2: Select trees 2 and 3 (both have 2 apples).
        // Pluck 1 apple from tree 2 (leaves 1). Pluck 1 apple from tree 3 (leaves 1).
        // This is allowed because trees 1 and 4 now have 1 apple.
        // Trees now: 1, 1, 1, 1.
        // Counts: {1:4}
        //
        // Minute 3: Select all trees (all have 1 apple).
        // Pluck 1 apple from each (leaves 0).
        // Trees now: 0, 0, 0, 0.
        //
        // This also takes 3 minutes.
        //
        // The crucial part is "the number of apples left on the tree equals the number of apples on a tree not in the subset."
        // This means if we have a set of trees with `X` apples, and we pick them, we can reduce them to `Y` apples, provided there is *some* tree (which is not in our chosen subset) that has `Y` apples.
        //
        // Let's consider the set of *current* apple counts.
        // In one step, we can pick a subset of trees with the same apple count `A`. We can reduce them to `B` apples, where `B` is the apple count of at least one tree *not* in our subset.
        //
        // This operation effectively allows us to take all trees with count `A` and make them have count `B`.
        // If there are multiple groups of trees with the same count `A`, we can pick *any* subset of them.
        //
        // The problem is equivalent to finding the minimum number of "levels" we need to reduce.
        // Each distinct initial apple count represents a "level".
        //
        // Let the distinct initial apple counts be `d1, d2, ..., dk`.
        //
        // Consider the set of all apple counts present across all trees at any given time.
        // In one minute, we can select all trees with count `C`. We can reduce them to count `D`, where `D` is present on at least one tree *not* in the selected subset.
        //
        // If we have distinct counts {1, 2, 3}, we have 3 distinct values.
        //
        // Let's think about what happens to the *set* of distinct apple counts.
        // Initially, we have a set of distinct counts S = {a1, a2, ..., ak}.
        //
        // In one minute, we can pick a subset of trees with count `X`. We can reduce them to count `Y`, where `Y` is present on at least one tree *not* in the subset.
        //
        // If we have counts {1, 2, 3, 3}. Distinct counts {1, 2, 3}.
        //
        // Minute 1: Select trees with 3 apples. We can reduce them to 1 or 2.
        // Option 1: Reduce to 2. Trees become {1, 2, 2, 2}. Distinct counts {1, 2}.
        // Option 2: Reduce to 1. Trees become {1, 2, 1, 1}. Distinct counts {1, 2}.
        //
        // Let's take Option 1: {1, 2, 2, 2}. Distinct counts {1, 2}.
        // Minute 2: Select trees with 2 apples. We can reduce them to 1.
        // Trees become {1, 1, 1, 1}. Distinct counts {1}.
        // Minute 3: Select trees with 1 apple. Reduce to 0.
        // Trees become {0, 0, 0, 0}. Distinct counts {0}.
        // Total minutes: 3.
        //
        // This confirms that the number of distinct initial apple counts is a valid upper bound.
        //
        // Can we achieve the goal in fewer minutes than the number of distinct initial counts?
        //
        // Suppose we have distinct initial counts {c1, c2, ..., ck}.
        // In any given minute, we select a subset of trees with the same current apple count `A`. We reduce them to `B`.
        // This means all trees that had `A` apples now have `B` apples.
        //
        // If `B` was already present on some other tree (not in our subset), then the set of distinct counts might not change, or might shrink.
        // If `B` was not present on any other tree, then `B` becomes a new distinct count.
        //
        // The crucial constraint is "the number of apples left on the tree equals the number of apples on a tree not in the subset."
        // This means if we have a set of trees with `X` apples, and we pick them, we can reduce them to `Y` apples, ONLY IF there is at least one tree *outside* this subset that currently has `Y` apples.
        //
        // Consider the set of distinct apple counts present at any stage. Let this set be `S`.
        // If we pick a subset of trees with count `X` from `S`, and reduce them to `Y`.
        // If `Y` is already in `S` and `Y` is the count of a tree *not* in our subset, then the set of distinct counts might shrink or stay the same.
        // If `Y` is not in `S`, then `Y` becomes a new distinct count.
        //
        // The operation allows us to take all trees with count `X` and make them have count `Y`.
        // If we have distinct counts {1, 2, 3}.
        // Minute 1: Pick trees with 3 apples. We can reduce them to 1 or 2.
        // If we reduce to 2: {1, 2, 2, 2}. Distinct counts {1, 2}.
        // If we reduce to 1: {1, 2, 1, 1}. Distinct counts {1, 2}.
        // In either case, the number of distinct counts reduces from 3 to 2.
        //
        // Minute 2: From {1, 2, 2, 2}, pick trees with 2 apples. We can reduce them to 1.
        // Trees become {1, 1, 1, 1}. Distinct counts {1}.
        //
        // Minute 3: From {1, 1, 1, 1}, pick trees with 1 apple. Reduce to 0.
        // Trees become {0, 0, 0, 0}. Distinct counts {0}.
        //
        // It seems that each distinct initial apple count requires at least one "level" of reduction.
        // If we have `k` distinct initial apple counts, say `c1 < c2 < ... < ck`.
        // We must eventually reduce all `ck` trees to something smaller.
        // We must eventually reduce all `c_{k-1}` trees to something smaller.
        // ...
        // We must eventually reduce all `c1` trees to 0.
        //
        // The operation allows us to take all trees with count `X` and make them have count `Y`.
        // If we have distinct counts {c1, c2, ..., ck}.
        // In minute 1, we can pick all trees with `ck` apples. We can reduce them to `c_{k-1}` apples (since `c_{k-1}` is present on other trees).
        // Now we have counts {c1, c2, ..., c_{k-2}, c_{k-1}, c_{k-1}}. The distinct counts are {c1, ..., c_{k-1}}.
        // In minute 2, we can pick all trees that *currently* have `c_{k-1}` apples. We can reduce them to `c_{k-2}` apples.
        // This process continues. Each minute, we effectively eliminate the highest current distinct apple count by merging it into the next highest.
        // This takes `k-1` minutes to reduce all counts to `c1`.
        // Then, one more minute to reduce `c1` to 0.
        // Total `k` minutes.
        //
        // The number of distinct initial apple counts is the minimum time.
        //
        // Example 1: 3 3 3. Distinct counts: {3}. Number of distinct counts = 1. Output: 1. Correct.
        // Example 2: 1 2 3 3. Distinct counts: {1, 2, 3}. Number of distinct counts = 3. Output: 3. Correct.
        //
        // The logic seems solid. The number of distinct initial apple counts determines the minimum time.

        std::cout << counts.size() << "\n";
    }
    return 0;
}