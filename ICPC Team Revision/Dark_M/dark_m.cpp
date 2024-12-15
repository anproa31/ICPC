#include <bits/stdc++.h>
using namespace std;


void padNumbers(vector<string>& dark_ms) {
    size_t maxLength = 0;
    for(const auto& dark_m : dark_ms) {
        maxLength = max(maxLength, dark_m.size());
    }

    for(auto& dark_m : dark_ms) {
        while(dark_m.size() < maxLength) {
            dark_m += "0";        }
    }
}

//string new line and space 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // stol string to long long
    int n;
    cin >> n;
    vector<string> dark_ms(n);
    string s;
    string sum;
    for(int i = 0; i < n; i++) {
        cin >> s;
        sum += s;
    }

    cout << sum;



    padNumbers(dark_ms);
    string result = "";
    size_t length = dark_ms[0].size();

    for(size_t i = 0; i < length; i++) {
        int colSum = 0;
        for(int j = 0; j < n; i++) {
            colSum += dark_ms[i][j] - '0';
        }
    }








    return 0;
}
