#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // adjacency list for the tree
vector<int> parent;      // to store parent of each node in the DFS

// DFS to compute parent relationships in the tree
void dfs(int v)
{
    for (int u : adj[v])
    {
        if (u != parent[v])
        {
            parent[u] = v;
            dfs(u);
        }
    }
}

// Function to generate the Prüfer code
vector<int> pruefer_code()
{
    int n = adj.size(); // number of nodes in the tree
    parent.resize(n);   // resize parent array to fit n nodes
    parent[n - 1] = -1; // set the parent of root node as -1 (no parent)
    dfs(n - 1);         // run DFS from node n-1 (the root)

    int ptr = -1;
    vector<int> degree(n); // stores the degree of each node
    // Initialize degrees and find the first leaf node
    for (int i = 0; i < n; i++)
    {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i; // find the first leaf
    }

    vector<int> code(n - 2); // resulting Prüfer code will have length n-2
    int leaf = ptr;          // start with the first leaf node

    for (int i = 0; i < n - 2; i++)
    {
        int next = parent[leaf]; // find the parent of the current leaf
        code[i] = next;          // add parent to the Prüfer code

        // Update the degree of the parent
        if (--degree[next] == 1 && next < ptr)
        {
            leaf = next; // if parent becomes a leaf, update leaf
        }
        else
        {
            ptr++;
            while (degree[ptr] != 1)
                ptr++; // find the next leaf
            leaf = ptr;
        }
    }

    return code; // return the generated Prüfer code
}

// Helper function to add an edge between nodes u and v
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

    adj.resize(n); // resize adjacency list to fit n nodes

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v); // add edge between u and v
    }

    vector<int> code = pruefer_code(); // generate Prüfer code

    cout << "Prüfer code: ";
    for (int x : code)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
