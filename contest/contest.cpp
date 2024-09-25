#include <bits/stdc++.h>
using namespace std;

#define fastInp                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    fastInp;

    int v, lv;
    string s, slv = "...", ans = "";
    cin >> v >> s;
    for(int i = 0; i < s.size(); i++) slv[s[i] - 49] = '*';
    lv = 1;
    if(v <= 1600) lv = 3;
    else if(v <= 1900) lv = 2;
    else lv = 1;
    
    switch (lv)
    {
    case 1:
    {
        if(slv[0] == '*') ans += "1\n";
        if(slv[1] == '*') ans += "2*\n";
        if(slv[2] == '*') ans += "3*\n";
        break;
    }

    case 2:
    {
        if(slv[0] == '*') ans += "1\n";
        if(slv[1] == '*') ans += "2\n";
        if(slv[2] == '*') ans += "3*\n";
        break;
    }

    case 3:
    {
        if(slv[0] == '*') ans += "1\n";
        if(slv[1] == '*') ans += "2\n";
        if(slv[2] == '*') ans += "3\n";
        break;
    }
    }
    cout << ans;
}