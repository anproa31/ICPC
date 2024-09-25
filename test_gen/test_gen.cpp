#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.begin() + k, 2);
    iota(a.begin() + k, a.end(), 1);
    srand(0);
    random_shuffle(a.begin(), a.end());
        for(int i:a) cout << i << " "; cout<<'\n';
    random_shuffle(a.begin(), a.end());
        for(int i:a) cout << i << " "; cout<<'\n';
}