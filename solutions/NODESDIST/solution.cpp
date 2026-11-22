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