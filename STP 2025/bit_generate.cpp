#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> bits;

void generate_bits(int index) {
    if (index == n) {
        for (size_t i = 0; i < bits.size(); i++) cout << bits[i] << " ";
        cout << endl;
        return;
    }
    bits[index] = 0;
    generate_bits(index + 1);
    bits[index] = 1;
    generate_bits(index + 1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;


    
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> n;
        bits.resize(n);
        
        cout << "#" << test_case << ":" << endl;
        generate_bits(0);
    }

    return 0;
}
