# [Distance between two nodes (NODESDIST)](https://www.codechef.com/problems/NODESDIST)
- **Difficulty Rating**: 1250
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the distance between two given nodes, `u` and `v`, in an unweighted tree. The tree has `N` nodes, numbered from 1 to `N`, and `N-1` edges. We are given `N`, the two query nodes `u` and `v`, and then `N-1` lines describing the edges of the tree.

## Intuition & Mathematical Observation

The core idea for finding the distance between two nodes in a tree relies on the concept of their Lowest Common Ancestor (LCA).

1.  **Tree Representation**: The given input describes a tree. We can represent this tree using an adjacency list, where `adj[i]` stores a list of nodes directly connected to node `i`. Since it's an unweighted tree, each edge has a weight of 1.

2.  **Rooting the Tree and Precomputation**: To effectively work with distances and ancestors, it's helpful to root the tree at an arbitrary node. Let's choose node 1 as the root.
    *   We can perform a Depth First Search (DFS) starting from the root (node 1).
    *   During this DFS, we can precompute two crucial pieces of information for every node:
        *   **`depth[node]`**: The distance (number of edges) from the root (node 1) to `node`. The root itself has a depth of 0.
        *   **`parent[node]`**: The immediate parent of `node` in the tree rooted at 1. The root's parent can be set to a dummy value (e.g., 0).

3.  **Lowest Common Ancestor (LCA)**: The LCA of two nodes `u` and `v` is the deepest node that is an ancestor of both `u` and `v`.
    *   To find `LCA(u, v)` using the precomputed `depth` and `parent` arrays:
        *   **Step 1: Equalize Depths**: First, bring the deeper of the two nodes up until both `u` and `v` are at the same depth. If `depth[u] < depth[v]`, swap `u` and `v` so that `u` is always the deeper (or equally deep) node. Then, repeatedly move `u` to `parent[u]` until `depth[u] == depth[v]`.
        *   **Step 2: Check for Identity**: If, after equalizing depths, `u` and `v` are the same node, then that node is the LCA.
        *   **Step 3: Simultaneous Ascent**: If `u` and `v` are not the same node, move both `u` and `v` simultaneously one step up (to `parent[u]` and `parent[v]` respectively) until their parents become the same. The common parent found at this point is `LCA(u, v)`.

4.  **Distance Calculation**: Once we have the depths of `u`, `v`, and `LCA(u, v)`, the distance between `u` and `v` can be calculated using the following formula:
    `distance(u, v) = depth[u] + depth[v] - 2 * depth[LCA(u, v)]`

    *   **Why this formula?**
        *   `depth[u]` is the distance from the root to `u`.
        *   `depth[v]` is the distance from the root to `v`.
        *   The path from the root to `u` and the path from the root to `v` share a common segment: the path from the root to `LCA(u, v)`.
        *   The distance from `u` to `LCA(u, v)` is `depth[u] - depth[LCA(u, v)]`.
        *   The distance from `v` to `LCA(u, v)` is `depth[v] - depth[LCA(u, v)]`.
        *   The total distance `distance(u, v)` is the sum of these two segments:
            `(depth[u] - depth[LCA(u, v)]) + (depth[v] - depth[LCA(u, v)])`
            `= depth[u] + depth[v] - 2 * depth[LCA(u, v)]`.

## Complexity Analysis

*   **Time Complexity**:
    *   **Input Reading and Adjacency List Construction**: Reading `N` and `N-1` edges takes $O(N)$ time.
    *   **DFS for Precomputation**: The `dfs` function visits each node and each edge exactly once. This takes $O(N + (N-1)) = O(N)$ time.
    *   **`get_lca` Function**: In the worst case (e.g., a path graph), one node might be very deep, and we might have to traverse up to $O(N)$ steps to equalize depths or find the common parent. Thus, `get_lca` takes $O(N)$ time.
    *   **Distance Calculation**: This is a constant time $O(1)$ operation.
    *   **Total Time Complexity**: $O(N)$ (for DFS) + $O(N)$ (for LCA query) = $O(N)$.

*   **Space Complexity**:
    *   **`adj` (Adjacency List)**: Stores $2 \times (N-1)$ entries for an undirected graph, which is $O(N)$.
    *   **`depth` Vector**: Stores `N+1` integers, $O(N)$.
    *   **`parent` Vector**: Stores `N+1` integers, $O(N)$.
    *   **DFS Recursion Stack**: In the worst case (a path graph), the recursion depth can be $O(N)$.
    *   **Total Space Complexity**: $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; as requested by problem instructions
using namespace std;

// Global variables for convenience, accessible by DFS and LCA functions
vector<vector<int>> adj; // Adjacency list to represent the tree
vector<int> depth;       // Stores depth of each node from the root (node 1)
vector<int> parent;      // Stores the immediate parent of each node in the tree rooted at 1

// DFS function to precompute depths and parents for all nodes
// u: current node
// p: parent of current node u
// d: depth of current node u
void dfs(int u, int p, int d) {
    depth[u] = d;   // Set the depth of the current node
    parent[u] = p;  // Set the parent of the current node

    // Iterate over all neighbors of u
    for (int v : adj[u]) {
        if (v == p) {
            // If neighbor v is the parent, skip it to avoid going back up
            continue;
        }
        // Recursively call DFS for child v, with u as its parent and incremented depth
        dfs(v, u, d + 1);
    }
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes u and v
int get_lca(int u, int v) {
    // Step 1: Bring the deeper node up until both nodes are at the same depth
    if (depth[u] < depth[v]) {
        // Ensure u is always the deeper or equally deep node
        swap(u, v);
    }

    // Lift u until its depth matches v's depth
    while (depth[u] > depth[v]) {
        u = parent[u];
    }

    // Step 2: If u and v are now the same node, that node is the LCA
    if (u == v) {
        return u;
    }

    // Step 3: Lift both u and v simultaneously until their parents are the same
    // This common parent will be their LCA
    while (parent[u] != parent[v]) {
        u = parent[u];
        v = parent[v];
    }

    // The LCA is the common parent found
    return parent[u];
}

int main() {
    // Enable fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, u_query, v_query;
    // Read N (number of nodes), and the two query nodes u and v
    cin >> N >> u_query >> v_query;

    // Initialize data structures with size N+1 for 1-based indexing
    adj.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);

    // Read N-1 edges to build the tree
    for (int i = 0; i < N - 1; ++i) {
        int u_edge, v_edge;
        cin >> u_edge >> v_edge;
        // Add bidirectional edges
        adj[u_edge].push_back(v_edge);
        adj[v_edge].push_back(u_edge);
    }

    // Perform DFS starting from root node 1.
    // Root's parent is 0 (a dummy node), and its depth is 0.
    dfs(1, 0, 0);

    // Find the Lowest Common Ancestor (LCA) of the two query nodes
    int lca_node = get_lca(u_query, v_query);

    // Calculate the distance using the formula:
    // distance(u, v) = depth(u) + depth(v) - 2 * depth(LCA(u, v))
    int distance = depth[u_query] + depth[v_query] - 2 * depth[lca_node];

    // Output the calculated distance
    cout << distance << "\n";

    return 0;
}
```