#include <bits/stdc++.h>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MAX 1000000

// void generateBitString(int n) {
//     ll num_codes = (ll) 1 << n;
//     vector<string> gray_codes;

//     for(int i = 0; i < num_codes; i++) {
//         int gray_code = i ^ (i >> 1);
//         bitset<32> b(gray_code);
//         gray_codes.push_back(b.to_string().substr(32-n));
//     }

//     for(const string& gray_code : gray_codes) {
//             cout << gray_code << endl;
//     }
// }

void printArr(int n, int arr[]) {
     for(int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;

}


void genBits(int n, int arr[], int i) {
    if(i == n) {
        printArr(n, arr);
        return;
    }

    arr[i] = 0;
    genBits(n, arr, i + 1);


    arr[i] = 1;
    genBits(n, arr, i + 1);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    int arr[10000];
    cin >> n;

    // generateBitString(n);
    genBits(n, arr, 0);


    return 0;
}
