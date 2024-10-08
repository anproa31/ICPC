#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list for the tree

// Function to implement Prufer sequence O(nlog(n))
vector<int> pruferCode()
{
    int n = adj.size();
    set<int> leaves;               // Set to store the current leaves
    vector<int> degree(n);         // To store the degree of each node
    vector<bool> killed(n, false); // Mark nodes that are removed

    // Initialize the degree of each node and find the initial leaves
    for (int i = 0; i < n; i++)
    {
        degree[i] = adj[i].size(); // Degree is the number of edges
        if (degree[i] == 1)        // If degree is 1, it's a leaf
            leaves.insert(i);      // If degree is 1, it is a leaf
    }

    vector<int> code(n - 2); // To store the Prufer code

    // Generate the Prufer code
    for (int i = 0; i < n - 2; i++)
    {
        // Find the smallest leaf
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        killed[leaf] = true; // Mark the leaf as killed

        // Find the adjacent node of the leaf that still not killed
        int v;
        for (int u : adj[leaf])
        {
            if (!killed[u])
            {
                v = u;
                break;
            }
        }

        code[i] = v; // Add the node to the code

        // Decrease the degree of the adjacent node
        if (--degree[v] == 1)
        {
            leaves.insert(v); // If the degree is 1, it is a leaf
        }
    }

    return code;
}

// Helper function to add an edge to the adjacency list
void add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // Resize the adjacency list to hold n nodes
    adj.resize(n);


    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    // Generate and print the Prüfer code
    vector<int> code = pruferCode();
    cout << "Prüfer code: ";
    for (int x : code)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
