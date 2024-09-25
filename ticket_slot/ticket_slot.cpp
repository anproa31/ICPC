//
// Created by antoe on 9/24/2024.
//
#include<bits/stdc++.h>
using namespace std;
int main() {
    //Vao tu file MAX34.inp dua ra file MAX34.out
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    //using vector to store the ticket slot
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //sort the ticket slot in descending order
    sort(a.begin(), a.end(), greater<int>());
    //using nth_element to find the 3rd and 4th largest ticket slot
    nth_element(a.begin(), a.begin() + 2, a.end(), greater<int>());
    nth_element(a.begin(), a.begin() + 3, a.end(), greater<int>());
    //output the 3rd and 4th largest ticket slot
    cout << a[2] << " " << a[3];

    return 0;
}