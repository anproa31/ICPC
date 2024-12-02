#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n, int source, int destination, int auxiliary) {
    if (n == 0) {
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Print current move
    cout << source << " " << destination << "\n";
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

void towerOfHN(int n, int source, int destination, int aux) {
    if(n == 0) {
        return;
    }

    towerOfHN(n - 1, source, aux, destination);

    cout << source << " " << destination << "\n";

    towerOfHN(n -1, aux, destination, source);
}

int main() {

    int n;
    cin >> n;
    
    // Print total number of moves
    cout << (1 << n) - 1 << "\n";
    
    // Generate moves
    towerOfHanoi(n, 1, 3, 2);

    return 0;
}