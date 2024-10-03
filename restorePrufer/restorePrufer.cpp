#include <bits/stdc++.h>
using namespace std;

// Function to decode the Prüfer code and reconstruct the tree
vector<pair<int, int>> pruefer_decode(vector<int> const &code)
{
    int n = code.size();     // n is the length of the Prüfer code
    int total_nodes = n + 2; // The total number of nodes is always two more than the Prüfer code length

    vector<int> degree(total_nodes, 1); // Initialize degrees of all nodes to 1 (all are leaves initially)

    // Step 2: Update the degree of nodes appearing in the Prüfer code
    for (int i : code)
        degree[i - 1]++; // Increment the degree of the nodes appearing in the Prüfer code (1-based indexing)

    // Step 3: Find all initial leaves (nodes with degree 1)
    set<int> leaves; // Use a set to store leaves as they need to be in sorted order
    for (int i = 0; i < total_nodes; i++)
    {
        if (degree[i] == 1)   // If a node has degree 1, it is a leaf
            leaves.insert(i); // Add it to the set of leaves
    }

    // Step 4: Build the tree from the Prüfer code
    vector<pair<int, int>> edges; // To store the edges of the tree
    for (int v : code)
    {                                 // Traverse each node in the Prüfer code
        int leaf = *leaves.begin();   // Get the smallest leaf (first element in the set)
        leaves.erase(leaves.begin()); // Remove the selected leaf from the set

        edges.emplace_back(leaf + 1, v); // Add an edge between the leaf and the current node (convert to 1-based index)

        if (--degree[v - 1] == 1) // Decrease the degree of the node from the Prüfer code
            leaves.insert(v - 1); // If it becomes a leaf (degree = 1), insert it into the set
    }

    // Step 5: Add the final edge between the two remaining nodes
    edges.emplace_back(*leaves.begin() + 1, *next(leaves.begin()) + 1); // Connect the last two remaining nodes (convert to 1-based index)

    return edges; // Return the list of edges
}

vector<pair<int, int>> pruefer_decode_linear(vector<int> const& code) {
    int n = code.size(); // n is the length of the Prüfer code
    int total_nodes = n + 2; // The total number of nodes is always two more than the Prüfer code length

    vector<int> degree(total_nodes, 1); // Initialize degrees of all nodes to 1 (all are leaves initially)
    
    // Step 2: Update the degree of nodes appearing in the Prüfer code
    for (int i : code)
        degree[i-1]++; // Increment the degree of the nodes appearing in the Prüfer code (1-based indexing)

    // Step 3: Find the smallest leaf (node with degree 1)
    int ptr = 0;
    while (degree[ptr] != 1) ptr++; // Find the first leaf (node with degree 1)

    int leaf = ptr; // The first leaf found
    vector<pair<int, int>> edges; // To store the edges of the tree

    // Step 4: Build the tree from the Prüfer code
    for (int v : code) { // Traverse each node in the Prüfer code
        edges.emplace_back(leaf + 1, v); // Add an edge between the leaf and the current node (convert to 1-based index)
        
        // Decrease the degree of the node from the Prüfer code
        if (--degree[v-1] == 1 && v-1 < ptr) {
            leaf = v-1;   // If the node becomes a leaf, assign it as the next leaf
        } else {
            ptr++; // Otherwise, find the next smallest leaf
            while (degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    // Step 5: Add the final edge between the two remaining nodes
    edges.emplace_back(leaf + 1, ptr + 1); // Connect the last two remaining nodes (convert to 1-based index)

    return edges; // Return the list of edges
}


int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; // Length of the Prüfer code
    cin >> n;

    vector<int> code(n); // Read the Prüfer code (size n)
    for (int i = 0; i < n; i++)
    {
        cin >> code[i];
    }

    vector<pair<int, int>> edges = pruefer_decode(code); // Decode the Prüfer code and get the tree's edges
    int total_nodes = n + 2;
    vector<vector<int>> adj(total_nodes + 1); // Using 1-based index
    // Populate adjacency list
    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // Output adjacency list from node 1 to total_nodes
    for (int i = 1; i <= total_nodes; i++)
    {
        cout << i << ": ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}