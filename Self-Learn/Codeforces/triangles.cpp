#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = (a[0] + a[1]) - (a.back() - a[0]) - 1;
    if(ans <= 0) cout << 0;
    else cout << ans;


    return 0; 
    
}
