#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find and print the minimum swaps step by step
int minSwapsToMatchArrays(vector<int>& array1, vector<int>& array2) {
    int n = array1.size();
    
    // Create a map to store the target positions in array2
    unordered_map<int, int> targetPosition;
    for (int i = 0; i < n; ++i) {
        targetPosition[array2[i]] = i;
    }

    // Create a visited array to keep track of which elements are already in place
    vector<bool> visited(n, false);
    int swaps = 0;

    // Go through each element in array1
    for (int i = 0; i < n; ++i) {
        // If the element is already visited or in the correct position, skip
        if (visited[i] || targetPosition[array1[i]] == i) {
            continue;
        }

        // Start finding the cycle of misplaced elements
        int cycle_size = 0;
        int j = i;
        vector<int> cycle; // To store the elements involved in the cycle

        // Keep following the cycle of positions
        while (!visited[j]) {
            visited[j] = true;
            cycle.push_back(array1[j]);  // Add each element to the cycle
            j = targetPosition[array1[j]];
            cycle_size++;
        }

        // If there is a cycle of length k, it needs k-1 swaps to correct
        if (cycle_size > 1) {
            swaps += cycle_size - 1;
            // Print out the swaps for this cycle
            for (int k = 0; k < cycle_size - 1; ++k) {
                cout << "Step " << swaps - cycle_size + 1 + k << ": Swap marble of color " << cycle[k] 
                     << " and marble of color " << cycle[k + 1] << endl;
            }
        }
    }

    return swaps;
}

int main() {
    vector<int> array1 = {1, 4, 5, 3, 6, 2};
    vector<int> array2 = {5, 3, 2, 4, 6, 1};

    cout << "Array 1: ";
    for (int num : array1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int num : array2) {
        cout << num << " ";
    }
    cout << endl << endl;

    int result = minSwapsToMatchArrays(array1, array2);
    cout << "\nTotal swaps required: " << result << endl;

    return 0;
}
